#include <algorithm>
#include <string>

#include "nptelebot/CurlTools.h"

#include "curl/curl.h"

namespace nptelebot
{
	CurlTools & CurlTools::Create()
	{
		auto ret = new CurlTools;
		
		return *ret;
	}

	//static std::string *DownloadedResponse;
	static char* responseBuffer;
	static int writer(char *data, size_t size, size_t nmemb, std::string *buffer_in)
	{
		unsigned int memSize = size * nmemb;
		responseBuffer = new char[memSize];
		strcpy(responseBuffer, data);
		
		// Is there anything in the buffer?  
//		if (buffer_in != NULL)
//		{
			// Append the data to the buffer    
//			buffer_in->append(data, size * nmemb);
			// How much did we write?   
//			DownloadedResponse = buffer_in;
			return memSize;
//		}
//		return 0;
	}

	char* CurlTools::Request(std::string url)
	{
		CURL *curl;
		CURLcode res;
		curl = curl_easy_init();

		if (curl)
		{
			curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
			curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
			curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
			curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writer);
			res = curl_easy_perform(curl);

			if (CURLE_OK == res)
			{
				char *ct;
				res = curl_easy_getinfo(curl, CURLINFO_CONTENT_TYPE, &ct);
				if ((CURLE_OK == res) && ct)
					return responseBuffer;
			}
		}

	}

}