# Dangling Reference Detective

A small C++ console utility managing four telemetry channels. Each channel
can be reached in several ways — by reference, by pointer, by
pointer-to-const, or as a copy wrapped in `std::optional` — and an
interactive loop lets you apply calibration offsets to channels and see
the before/after readings.

Built as a learning project while working through
[learncpp.com](https://www.learncpp.com/), focused on consolidating
Chapter 12: lvalue references, pointers, `const` with both, null
pointers, return by reference vs. by address vs. by value,
`std::optional`, in/out parameters, and how `auto` deduction interacts
with references. Earlier material is used as part of the design, not as
decoration: internal linkage and static locals (Ch 7), `assert` vs.
recoverable errors and `std::cin` recovery (Ch 9), and a `constexpr`
validity check proven with `static_assert` (Ch F).

## What it does

- Stores four channel readings with internal linkage — no other file can
  name them; the registry functions are the only way in
- Offers four ways to reach a channel, each with a different contract:
  - `channelRef(id)` — returns `Reading&`; an invalid id is a programmer
    error, stopped with `assert` + `std::abort()` in every build
  - `findChannel(id)` — returns `Reading*`, or `nullptr` for an unknown id
  - `peekChannel(id)` — returns `const Reading*`, read-only access
  - `readChannel(id)` — returns `std::optional<Reading>`, a copy or empty
- `calibrate(id, offset, previousOut)` adjusts a channel and optionally
  writes its previous reading through an out-parameter pointer
- `lookupCount()` reports how many registry lookups have happened,
  counted by a single static local variable
- `isValidChannelId(id)` is `constexpr`, with `static_assert` checks for
  every valid id and both invalid boundaries
- An interactive loop reads a channel id and offset, recovers from
  non-numeric input, rejects out-of-range ids before narrowing them to
  `ChannelId`, and prints all channels plus the lookup count on quit

## Project structure

```
main.cpp                    // interactive calibration loop and summary
registry/
  types.h                   // ChannelId and Reading aliases
  constants.h               // channel ids
  registry.h / .cpp         // channel storage, lookups, calibrate, lookupCount
  tests.h                   // static_assert proofs for isValidChannelId
io/
  io.h / io.cpp             // prompts, error messages, stream recovery
validate/
  validate.h                // input-level validity checks
session/
  session.h / .cpp          // read + validate + retry loops
```

## Building

Requires a C++20-capable compiler.

```bash
g++ -std=c++20 -Wall -Wextra -Wconversion -Wshadow -Wsign-conversion -o app \
    main.cpp registry/registry.cpp io/io.cpp session/session.cpp
```

Or open `Dangling Reference Detective.slnx` in Visual Studio.

## Running

```bash
./app
```

Example session:

```
Channel 1: 12.5
Channel 2: 18.2
Channel 3: 14
Channel 4: 22.9

Enter channel id (1-4) or 0 to quit: 257
Invalid channel id! (must be 1 - 4) or 0 to quit
Enter channel id (1-4) or 0 to quit: 2
Enter offset: 5
Enter previous channel id (1-4) or 0 to discard: 0
Channel 2: 18.2
Channel 2: 23.2
----------------

Enter channel id (1-4) or 0 to quit: 0
Total functions called: 3
Channel 1: 12.5
Channel 2: 23.2
Channel 3: 14
Channel 4: 22.9
```

## Notes

`channelRef` has no honest way to report "not found", because a
reference must always refer to a real object — so an invalid id aborts,
while `findChannel` and `readChannel` express "not found" as `nullptr`
and an empty optional. `peekChannel` builds on `findChannel`, relying on
the automatic conversion from `Reading*` to `const Reading*`, and
`findChannel` is the single runtime place that maps ids to channels.
`calibrate` writes `*previousOut` only after the lookup succeeds, so a
failed call leaves the caller's variable untouched. The "previous
channel" prompt deliberately passes a pointer into another channel as
`previousOut`, which overwrites that channel with the calibrated
channel's old value — an intentional demonstration of out-parameter
aliasing. The lookup counter is a static local owned by a private
`lookupCounter` function, with `recordLookup()` and `lookupCount()` as
the only two entry points. Console input is read as `int` and
range-checked before converting to the 8-bit `ChannelId`, so values like
`257` or `-255` are rejected instead of wrapping around to channel 1.