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

/**
* Handle parameters and decide which function should be used
* @param argc Number of parameters
* @param argv Array of paramters
* @return Status code
**/
int main(int argc, char* argv[])
{
	CURL* curlHandle;
	int p, wgetCode;

	if(argc == 2)
	{
		p = parity(argv[1]);
		if(p == 0 || p ==1)
		{
			printf("%d\n", p);
			return EXIT_SUCCESS;
		}
		else
		{
			printError(p, argv[1]);
			return EXIT_FAILURE;
		}
	}
	else if(argc % 2 == 0)
	{
		printError(PARAMCOUNT, NULL);
		return EXIT_FAILURE;
	}
	else
	{

		curlHandle = curl_easy_init();

		for(int i = 1; i < argc; i = i + 2)
		{
			wgetCode = wget(argv[i], argv[i+1], &curlHandle);
			if(wgetCode == 0)
			{
				p = parity(argv[i+1]);

				if(p == 1 || p == 0)
				{
					printf("%d", p);
				}
				else
				{
					return 2;
				}
			}
			else
			{
				return 3;
			}
		}

		printf("\n");
		curl_easy_cleanup(curlHandle);
	}

	return EXIT_SUCCESS;
}
