/**
 * @file
 * @date 28.3.2013
 * @author Lukáš Vokráčko
 * @brief Source file for error printing
 */

#include "xvokra00.h"


/**
* Print error message with param in it
* @param index Index of error message
* @param param String that should be print inside the error message
**/
void printError(const int index, const char* param)
{
	fprintf(stderr, errors[index], param);
}