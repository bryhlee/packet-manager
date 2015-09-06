#include <fstream>
#include <string>
#include <iostream>

const int MAX_SIZE = 1900;

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
	else 
	{
		std::cout << "> File " << argv[1] << " opened successfully." << std::endl;
	}
	
	std::cout << "> Running diagnostics..." << std::endl;
	
	int i = 0;
	char buffer[MAX_SIZE];
	int buffersize = 0;
	int checksum = 0;
	
	while (!rwfile.eof())
	{
		rwfile.get(buffer[i++]);
		buffersize++;
	}
	buffersize-1;
	
	std::cout << "> Finished." << std::endl;
	std::cout << "Number of characters in this packet: " << buffersize << std::endl;
	
	
	for (i = 0; i < buffersize; i++)
	{
		checksum += (int)buffer[i];
	}
	std::cout << "Checksum: " << checksum << std::endl;
	
	return 0;
}