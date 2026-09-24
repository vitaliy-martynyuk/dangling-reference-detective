#include "tests.h"
#include "registry.h"
#include "constants.h"
#include <cassert>
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
		const Reading& dummy{ 0.0 };
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
			return dummy;
		}
	}
}