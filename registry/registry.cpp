#include "tests.h"
#include "registry.h"
#include "constants.h"
#include <cassert>
#include <cstdlib>
#include <optional>
#include <cstdint>

namespace registry
{
	namespace
	{
		using std::uint64_t;
		Reading channel1{ 12.5 };
		Reading channel2{ 18.2 };
		Reading channel3{ 14.0 };
		Reading channel4{ 22.9 };

		uint64_t lookupCounter(bool increment)
		{
			static uint64_t callCount{ 0 };
			if (!increment)
				return callCount;

			++callCount;
			return 0;
		}

		void recordLookup()
		{
			lookupCounter(true);
		}
	}

	Reading& channelRef(ChannelId id)
	{
		recordLookup();

		auto* channel{ findChannel(id) };
		if (!channel) {
			assert(false && "Invalid ChannelId!");
			std::abort();
		}

		return *channel;
	}

	Reading* findChannel(ChannelId id)
	{
		recordLookup();

		switch (id) {
		case constants::ch1Id:
			return &channel1;
		case constants::ch2Id:
			return &channel2;
		case constants::ch3Id:
			return &channel3;
		case constants::ch4Id:
			return &channel4;
		default:
			return nullptr;
		}
	}

	// expression must be a modifiable lvalue
	const Reading* peekChannel(ChannelId id)
	{
		recordLookup();

		const auto* channel{ findChannel(id) };

		return channel;
	}

	std::optional<Reading> readChannel(ChannelId id)
	{
		recordLookup();

		const auto* channel{ findChannel(id) };

		if (channel) return *channel;

		return std::nullopt;
	}

	bool calibrate(ChannelId id, Reading offset, Reading* previousOut)
	{
		auto* channel{ findChannel(id) };
		if (!channel) return false;
		if (previousOut) *previousOut = *channel;

		*channel += offset;

		return true;
	}

	std::uint64_t lookupCount()
	{
		return lookupCounter(false);
	}
}