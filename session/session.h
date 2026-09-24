#ifndef SESSION_H
#define SESSION_H

#include "../registry/types.h"

namespace session
{
	ChannelId setChannelId(bool previous = false);
	double setOffset();
}

#endif