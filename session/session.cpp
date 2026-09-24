#include "session.h"
#include "../io/io.h"
#include "../validate/validate.h"

namespace session
{
	ChannelId setChannelId(bool previous)
	{
		while (true) {
			auto channelId{ io::getChannelId(previous) };
			if (io::helpers::recoverInputStream() || !validate::isChannelIdValid(channelId)) {
				io::errors::channelId();
				continue;
			}

			return static_cast<ChannelId>(channelId);
		}
	}

	double setOffset()
	{
		while (true) {
			auto offset{ io::getOffset() };
			if (io::helpers::recoverInputStream() || !validate::isOffsetValid(offset)) {
				io::errors::offset();
				continue;
			}

			return offset;
		}
	}
}