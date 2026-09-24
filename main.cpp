#include "registry/registry.h"
#include "registry/constants.h"
#include "session/session.h"
#include "io/io.h"
#include <iostream>

int main()
{
	while (true) {
		auto channelId{ session::setChannelId() };
		if (channelId == 0) break;

		auto offset{ session::setOffset() };
		auto prevChannelId{ session::setChannelId(true) };

		auto channel{ registry::findChannel(channelId) };
		auto prevChannel{ registry::findChannel(prevChannelId) };

		io::printChannelInfo(channelId, *channel);
		if (prevChannel) io::printChannelInfo(prevChannelId, *prevChannel);

		registry::calibrate(channelId, offset, prevChannel);
		io::printChannelInfo(channelId, *channel);
		if (prevChannel) io::printChannelInfo(prevChannelId, *prevChannel);
		std::cout << "----------------\n\n";
	}

	std::cout << "Total functions called: " << registry::lookupCount() << '\n';

	return 0;
}