/**
 * @file
 * @date 28.3.2013
 * @author Lukáš Vokráčko
 * @brief Source file for parity count
 **/

#include "xvokra00.h"

/**
* Count even parity of file
* @param fileName Name of file
* @return Parity [0,1] or error code
**/
int parity(const char* fileName)
{
	FILE* file;
	int parity = 0;
	char byte;
	char byteXOR = 0;

	file = fopen(fileName, "rb");

	if(file != NULL)
	{
		while(fscanf(file, "%c", &byte) == 1)
		{
			byteXOR ^= byte;
		}
	}
	else
	{
		return 3;
	}

	fclose(file);

	for(int i = 0; i < 8; ++i)
	{
		parity ^= byteXOR >> i & 1;
	}

	return parity;
}