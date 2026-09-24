#include "registry/registry.h"
#include "registry/constants.h"
#include <iostream>

int main()
{
	std::cout << registry::channelRef(constants::ch1Id) << '\n';
	std::cout << registry::channelRef(constants::ch2Id) << '\n';
	std::cout << registry::channelRef(constants::ch3Id) << '\n';
	std::cout << registry::channelRef(constants::ch4Id) << '\n';

	std::cout << *registry::findChannel(constants::ch1Id) << '\n';
	std::cout << *registry::findChannel(constants::ch2Id) << '\n';
	std::cout << *registry::findChannel(constants::ch3Id) << '\n';
	std::cout << *registry::findChannel(constants::ch4Id) << '\n';
	std::cout << registry::findChannel(5) << '\n';

	return 0;
}