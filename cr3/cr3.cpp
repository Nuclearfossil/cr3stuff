// cr3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "argh.h"

#include <libraw/libraw.h>

int main(int argc, const char* argv[])
{
    std::cout << "Hello World!\n";
	std::cout << "LibRaw Version: " << libraw_version() << std::endl;

	argh::parser argParser(argc, argv);
	LibRaw rawParser;
	int result = rawParser.open_file(argParser[1].c_str());

	if (result != 0)
	{
		std::cout << "Error! " << libraw_strerror(result) << std::endl;
		return -1;
	}

	result = rawParser.unpack();
	if (result != 0)
	{
		std::cout << "Error! " << libraw_strerror(result) << std::endl;
		return -1;
	}

	result = rawParser.dcraw_process();
	if (result != 0)
	{
		std::cout << "Error! " << libraw_strerror(result) << std::endl;
		return -1;
	}

	rawParser.recycle();
	return 0;

}

