#ifndef VALIDATE_H
#define VALIDATE_H

#include "../registry/registry.h"
#include "../registry/types.h"
#include <limits>

namespace validate
{
	inline bool isChannelIdValid(int id)
	{
		if (id < std::numeric_limits<ChannelId>::min() || id > std::numeric_limits<ChannelId>::max()) return false;

		return registry::isValidChannelId(static_cast<ChannelId>(id)) || id == 0;
	}

	inline bool isOffsetValid(double offset)
	{
		return (offset >= -99.9) && (offset <= 99.9);
	}
}

#endif