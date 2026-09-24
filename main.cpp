#include "registry/registry.h"
#include "registry/constants.h"
#include "session/session.h"
#include "io/io.h"
#include <iostream>

int main()
{
	std::cout << "Channel 1: " << *registry::peekChannel(constants::ch1Id) << '\n';
	std::cout << "Channel 2: " << *registry::peekChannel(constants::ch2Id) << '\n';
	std::cout << "Channel 3: " << *registry::peekChannel(constants::ch3Id) << '\n';
	std::cout << "Channel 4: " << *registry::peekChannel(constants::ch4Id) << "\n\n";

	while (true) {
		auto channelId{ session::setChannelId() };
		if (channelId == 0) break;

		auto offset{ session::setOffset() };
		auto prevChannelId{ session::setChannelId(true) };

		auto channel{ registry::peekChannel(channelId) };
		auto prevChannel{ registry::findChannel(prevChannelId) };

		io::printChannelInfo(channelId, *channel);
		if (prevChannel) io::printChannelInfo(prevChannelId, *prevChannel);

		registry::calibrate(channelId, offset, prevChannel);
		io::printChannelInfo(channelId, *channel);
		if (prevChannel) io::printChannelInfo(prevChannelId, *prevChannel);
		std::cout << "----------------\n\n";
	}

	std::cout << "Total functions called: " << registry::lookupCount() << '\n';
	std::cout << "Channel 1: " << *registry::peekChannel(constants::ch1Id) << '\n';
	std::cout << "Channel 2: " << *registry::peekChannel(constants::ch2Id) << '\n';
	std::cout << "Channel 3: " << *registry::peekChannel(constants::ch3Id) << '\n';
	std::cout << "Channel 4: " << *registry::peekChannel(constants::ch4Id) << '\n';

	return 0;
}