#ifndef REGISTRY_H
#define REGISTRY_H

#include "types.h"
#include "constants.h"
#include <optional>

namespace registry
{
	constexpr bool isValidChannelId(const ChannelId id)
	{
		switch (id) {
		case constants::ch1Id:
		case constants::ch2Id:
		case constants::ch3Id:
		case constants::ch4Id:
			return true;
		default:
			return false;
		}
	}

	Reading& channelRef(ChannelId id);
	Reading* findChannel(ChannelId id);
	const Reading* peekChannel(ChannelId id);
	std::optional<Reading> readChannel(ChannelId id);
	bool calibrate(ChannelId id, Reading offset, Reading* previousOut = nullptr);
	int lookupCount();
}

#endif