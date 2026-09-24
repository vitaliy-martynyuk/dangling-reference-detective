#ifndef SESSION_H
#define SESSION_H

#include "../registry/types.h"

namespace session
{
	const ChannelId setChannelId(bool previous = false);
	const double setOffset();
}

#endif