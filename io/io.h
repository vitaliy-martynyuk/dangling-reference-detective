#ifndef IO_H
#define IO_H

namespace io
{
	int getChannelId(bool previous = false);
	double getOffset();

	namespace helpers
	{
		bool recoverInputStream();
	}
}

#endif