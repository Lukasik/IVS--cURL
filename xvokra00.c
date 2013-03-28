/**
 * @file
 * @date 28.3.2013
 * @author Lukáš Vokráčko
 * @brief Main source file
 **/

#include "xvokra00.h"

enum
{
	URL = 1,
	PARITY,
	FOPEN,
	PARAMCOUNT
} ERRORCODES; //!< Return codes

const char* errors[] =
{
	[URL] = "Z url %s se nepodařilo stáhnout soubor\n",
	[PARITY] = "U souboru %s se nepodařilo vypočítat paritu\n",
	[FOPEN] = "Soubor %s se nepodařilo otevřít\n",
	[PARAMCOUNT] = "Chybný počet parametrů\n"
}; //!< Error messages
