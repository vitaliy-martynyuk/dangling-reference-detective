#include "session.h"
#include "../io/io.h"
#include "../validate/validate.h"

namespace session
{
	const ChannelId setChannelId(bool previous)
	{
		while (true) {
			auto channelId{ io::getChannelId(previous) };
			if (!validate::isChannelIdValid(channelId) || io::helpers::recoverInputStream()) {
				io::errors::channelId();
				continue;
			}

			return static_cast<ChannelId>(channelId);
		}
	}

	const double setOffset()
	{
		while (true) {
			auto offset{ io::getOffset() };
			if (!validate::isOffsetValid(offset) || io::helpers::recoverInputStream()) {
				io::errors::offset();
				continue;
			}

			return offset;
		}
	}
}