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

	file = fopen(fileName, "rb");

	if(file != NULL)
	{
		while(fscanf(file, "%c", &byte) == 1)
		{
			//xvokra00 debug
			for(int i = 0; i < 8; ++i)
			{
				parity ^= byte >> i & 1;
			}
		}
	}
	else
	{
		return 3;
	}

	fclose(file);

	return parity;
}