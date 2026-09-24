#include "io.h"
#include <iostream>
#include <limits>
#include <cstdlib>

namespace io
{
	namespace
	{
		using std::cin;
		using std::cout;
		using std::numeric_limits;
		using std::streamsize;
	}

	int getChannelId(bool previous)
	{
		if (previous) cout << "Enter previous channel id (1-4) or 0 to discard: ";
		else cout << "Enter channel id (1-4) or 0 to quit: ";

		int input{};
		cin >> input;

		return input;
	}

	double getOffset()
	{
		cout << "Enter offset: ";
		double input{};
		cin >> input;

		return input;
	}

	void printChannelInfo(int id, double value)
	{
		cout << "Channel " << id << ": " << value << '\n';
	}

	namespace errors
	{
		void channelId()
		{
			cout << "Invalid channel id! (must be 1 - 4) or 0 to quit\n";
		}

		void offset()
		{
			cout << "Invalid offset! (must be -99.9 - 99.9)\n";
		}
	}

	namespace helpers
	{
		bool recoverInputStream()
		{
			const bool hasUnextractedInput{ !cin.eof() && cin.peek() != '\n' };
			if (!cin || hasUnextractedInput) {
				if (cin.eof()) {
					std::exit(1);
				}

				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');

				return true;
			}

			return false;
		}
	}
}