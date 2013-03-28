/**
 * @file
 * @date 28.3.2013
 * @author Lukáš Vokráčko
 *
 * @section DESCRIPTION
 * Include all necessary headers which have been used by source files.
 * Define prototypes for all functions used in project
 **/

#include <stdio.h>
#include <stdlib.h>
#include "../curl/include/curl/curl.h"

extern const char* errors[];

int parity(const char* fileName);
int wget(const char* url, const char* fileName, CURL** curlHandle);
void printError(const int index, const char* param);