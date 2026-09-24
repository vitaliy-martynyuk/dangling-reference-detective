#include "registry/registry.h"
#include "registry/constants.h"
#include <iostream>

int main()
{
	std::cout << std::boolalpha;
	std::cout << registry::channelRef(constants::ch1Id) << '\n';
	std::cout << registry::channelRef(constants::ch2Id) << '\n';
	std::cout << registry::channelRef(constants::ch3Id) << '\n';
	std::cout << registry::channelRef(constants::ch4Id) << '\n';

	std::cout << "-------------------\n\n";

	Reading* v1{ registry::findChannel(constants::ch1Id) };
	Reading* v2{ registry::findChannel(constants::ch2Id) };
	Reading* v3{ registry::findChannel(constants::ch3Id) };
	Reading* v4{ registry::findChannel(constants::ch4Id) };
	Reading* v5{ registry::findChannel(5) };

	std::cout << *v1 << '\n';
	std::cout << *v2 << '\n';
	std::cout << *v3 << '\n';
	std::cout << *v4 << '\n';
	std::cout << v5 << '\n';

	v5 = v1;
	*v5 = 12;

	std::cout << *v5 << '\n';
	std::cout << "-------------------\n\n";

	const Reading* cv1{ registry::peekChannel(constants::ch1Id) };
	const Reading* cv2{ registry::peekChannel(constants::ch2Id) };
	const Reading* cv3{ registry::peekChannel(constants::ch3Id) };
	const Reading* cv4{ registry::peekChannel(constants::ch4Id) };
	const Reading* cv5{ registry::peekChannel(5) };

	std::cout << *cv1 << '\n';
	std::cout << *cv2 << '\n';
	std::cout << *cv3 << '\n';
	std::cout << *cv4 << '\n';
	std::cout << cv5 << '\n';

	cv5 = cv1;

	std::cout << *cv5 << '\n';
	std::cout << "-------------------\n\n";

	auto rv1{ registry::readChannel(constants::ch1Id) };
	auto rv2{ registry::readChannel(5) };

	std::cout << *cv1 << '\n';
	std::cout << *rv1 << '\n';
	std::cout << (rv2 && *rv2) << '\n';

	rv1 = 999;

	std::cout << *cv1 << '\n';
	std::cout << *rv1 << '\n';
	std::cout << (rv2 && *rv2) << '\n';
	std::cout << "-------------------\n\n";

	return 0;
}