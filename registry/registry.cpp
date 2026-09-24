#include "tests.h"
#include "registry.h"
#include "constants.h"
#include <cassert>
#include <cstdlib>
#include <optional>

namespace registry
{
	namespace
	{
		Reading channel1{ constants::ch1Id };
		Reading channel2{ constants::ch2Id };
		Reading channel3{ constants::ch3Id };
		Reading channel4{ constants::ch4Id };
	}

	Reading& channelRef(ChannelId id)
	{
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
		const auto* channelRef{ findChannel(id) };

		return channelRef;
	}

	std::optional<Reading> readChannel(ChannelId id)
	{
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
}