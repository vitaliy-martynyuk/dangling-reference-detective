#ifndef VALIDATE_H
#define VALIDATE_H

#include "../registry/constants.h"

namespace validate
{
	inline bool isChannelIdValid(int id)
	{
		switch (id) {
		case constants::ch1Id:
		case constants::ch2Id:
		case constants::ch3Id:
		case constants::ch4Id:
			return true;
		default:
			return false;
		}
	}

	inline bool isOffsetValid(double offset)
	{
		return (offset >= 0.1) && (offset <= 99.9);
	}
}

#endif