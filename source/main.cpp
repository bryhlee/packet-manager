#include <fstream>
#include <string>
#include <iostream>

int main (int argc, char *argv[])
{
	std::cout << std::endl << "Packet Manager pkmg v 0.1" << std::endl;
	
	if (argc != 2)
	{
		std::cout << "> Error 254: Arguments incorrect or invalid." << std::endl;
		return 255;
	}
	std::fstream rwfile;
	rwfile.open(argv[1]);
	if(rwfile.is_open() != true)
	{
		std::cout << "> Error 255: Could not open file " << argv[1] << std::endl; 
		return 255;
	}
	
	std::cout << "Running diagnostics..." << std::endl;
	
	int i = 0;
	char buffer[400];
	while (!rwfile.eof())
	{
		rwfile >> buffer[i++];
	}
	
	std::cout << "Finished." << std::endl;
	std::cout << "Number of characters in this packet: " << i << std::endl;
	
	int checksum = 0;
	for (i = 0; i < 400; i++)
	{
		checksum+=buffer[i++];
	}
	std::cout << "Checksum: " << checksum << std::endl;
	
	return 0;
}