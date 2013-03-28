/**
 * @file
 * @date 28.3.2013
 * @author Lukáš Vokráčko
 * @brief Source file for download function
 **/

#include "xvokra00.h"

/**
* Download file from url and save it to the filename
* @param url Link to remote file
* @param fileName Name of file where it should be stored
* @param curlHandle Pointer to CURL object
* @return Status code
**/
int wget(const char* url, const char* fileName, CURL** curlHandle)
{
	CURLcode res;
	FILE* file = fopen(fileName, "w");

	if(file == NULL)
	{
		return 3;
	}

	curl_easy_setopt(*curlHandle, CURLOPT_URL, url);
	curl_easy_setopt(*curlHandle, CURLOPT_WRITEFUNCTION, NULL);
	curl_easy_setopt(*curlHandle, CURLOPT_WRITEDATA, file);
	res = curl_easy_perform(*curlHandle);

	fclose(file);

	if(res == CURLE_OK)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}