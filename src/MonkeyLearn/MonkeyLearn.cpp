#include "MonkeyLearn/MonkeyLearn.h"
#include <curl/curl.h>

namespace npml {
	MonkeyLearn* MonkeyLearn::_instance = nullptr;

	MonkeyLearn::MonkeyLearn()
		: authorizationToken("fec5b02f8ca3037b3644f4092c2a0835b83b493e")
	{
	}

	MonkeyLearn & MonkeyLearn::Instance()
	{
		if (_instance == nullptr) {
			_instance = new MonkeyLearn();
		}
		return *_instance;
	}

	static char* responseBuffer;
	static int __writer(char *data, size_t size, size_t nmemb, char* buffer_in);
	char* MonkeyLearn::classify(vector<const char*> texts, const char * moduleID)
	{
		CURL *curl;
		CURLcode res;
		struct curl_slist *headers = NULL;
		string url("https://api.monkeylearn.com/v2/classifiers/");
		url.append(moduleID);
		url.append("/classify/?sandbox=1");

		string authorizationHeaderParam("Authorization:Token ");
		authorizationHeaderParam.append(authorizationToken);

		//Prepare json with texts list
		string json("{\"text_list\": [");

		for each (const char* text in texts)
		{
			json.append("\"");
			json.append(text);
			json.append("\",");
		}
		json = json.substr(0, json.size() - 1);
		json.append("]}");

		/* In windows, this will init the winsock stuff */
		res = curl_global_init(CURL_GLOBAL_DEFAULT);
		if (res != CURLE_OK) {
			fprintf(stderr, "curl_global_init() failed: %s\n",
				curl_easy_strerror(res));
			return 0;
		}
		curl = curl_easy_init();
		if (curl) {
			curl_easy_setopt(curl, CURLOPT_URL, url.c_str()); //"https://api.monkeylearn.com/v2/classifiers/cl_KFXhoTdt/classify/?sandbox=1"
			curl_easy_setopt(curl, CURLOPT_POST, 1L);
			curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
			curl_easy_setopt(curl, CURLOPT_POSTFIELDS, json.c_str());
			curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, __writer);
			headers = curl_slist_append(headers, "Expect:");
			headers = curl_slist_append(headers, "Content-Type: application/json");
			headers = curl_slist_append(headers, authorizationHeaderParam.c_str()); //"Authorization:Token fec5b02f8ca3037b3644f4092c2a0835b83b493e"
			headers = curl_slist_append(headers, "Transfer-Encoding: chunked");
			curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
//		    curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);
			res = curl_easy_perform(curl);
			if (res != CURLE_OK)
				fprintf(stderr, "curl_easy_perform() failed: %s\n",
					curl_easy_strerror(res));
			//cleanup always
			curl_easy_cleanup(curl);
		}
		curl_global_cleanup();
		return responseBuffer;
	}




	MonkeyLearn::~MonkeyLearn()
	{
	}

	
	static int __writer(char *data, size_t size, size_t nmemb, char* buffer_in)
	{
		unsigned int memSize = size * nmemb;
		responseBuffer = (char*)malloc(memSize);
		strcpy(responseBuffer, data);
		return memSize;
	}

}