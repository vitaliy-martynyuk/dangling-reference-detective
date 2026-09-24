#ifndef IO_H
#define IO_H

namespace io
{
	int getChannelId(bool previous = false);
	double getOffset();

	void printChannelInfo(int id, double value);

	namespace errors
	{
		void channelId();
		void offset();
	}

	namespace helpers
	{
		bool recoverInputStream();
	}
}

#endif