#ifndef IO_H
#define IO_H

#include "../registry/types.h"
#include <cstdint>

namespace io
{
	ChannelId getChannelId(bool previous = false);
	double getOffset();

	namespace helpers
	{
		bool recoverInputStream();
	}
}

#endif