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
		using std::uint8_t;
		Reading channel1{ constants::ch1Id };
		Reading channel2{ constants::ch2Id };
		Reading channel3{ constants::ch3Id };
		Reading channel4{ constants::ch4Id };

		uint8_t channelRefCallCount{ 0 };
		uint8_t findChannelCallCount{ 0 };
		uint8_t peekChannelCallCount{ 0 };
		uint8_t readChannelCallCount{ 0 };
	}

	Reading& channelRef(ChannelId id)
	{
		++channelRefCallCount;

		switch (id) {
		case constants::ch1Id:
			return channel1;
		case constants::ch2Id:
			return channel2;
		case constants::ch3Id:
			return channel3;
		case constants::ch4Id:
			return channel4;
		default:
			assert(false && "Invalid ChannelId!");
			std::abort();
		}
	}

	Reading* findChannel(ChannelId id)
	{
		++findChannelCallCount;

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
		++peekChannelCallCount;

		const auto* channelRef{ findChannel(id) };

		return channelRef;
	}

	std::optional<Reading> readChannel(ChannelId id)
	{
		++readChannelCallCount;

		switch (id) {
		case constants::ch1Id:
			return channel1;
		case constants::ch2Id:
			return channel2;
		case constants::ch3Id:
			return channel3;
		case constants::ch4Id:
			return channel4;
		default:
			return std::nullopt;
		}
	}

	bool calibrate(ChannelId id, Reading offset, Reading* previousOut)
	{
		auto* channel{ findChannel(id) };
		if (!channel) return false;
		if (previousOut) *previousOut = *channel;

		*channel += offset;

		return true;
	}
}