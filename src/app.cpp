#include <iostream>
#include <sstream>

#include "app.h"
#include "appinfo.h"

#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"

#include "curl/curl.h"

using namespace rapidjson;

App::App(int& argc, char** argv) 
{
	
}

App::~App()
{
}


static std::string *DownloadedResponse;

static int writer(char *data, size_t size, size_t nmemb, std::string *buffer_in)
{

	// Is there anything in the buffer?  
	if (buffer_in != NULL)
	{
		// Append the data to the buffer    
		buffer_in->append(data, size * nmemb);

		// How much did we write?   
		DownloadedResponse = buffer_in;

		return size * nmemb;
	}

	return 0;

}

std::string DownloadJSON(std::string URL)
{
	CURL *curl;
	CURLcode res;
	struct curl_slist *headers = NULL; // init to NULL is important 
	std::ostringstream oss;
	//curl_slist_append(headers, "Accept: application/json");
	//curl_slist_append(headers, "Content-Type: application/json");
	//curl_slist_append(headers, "charsets: utf-8");
	curl = curl_easy_init();

	if (curl)
	{
	//	curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
		curl_easy_setopt(curl, CURLOPT_URL,URL.c_str());
		curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
		curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
	//	curl_easy_setopt(curl, CURLOPT_HTTPGET, 1);
	//	curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writer);
		res = curl_easy_perform(curl);

		if (CURLE_OK == res)
		{
			char *ct;
			res = curl_easy_getinfo(curl, CURLINFO_CONTENT_TYPE, &ct);
			if ((CURLE_OK == res) && ct)
				return *DownloadedResponse;
		}
	}

}


int App::Execute()
{
	curl_global_init(CURL_GLOBAL_DEFAULT);
	std::string js = DownloadJSON("https://api.telegram.org/bot209137847:AAH7uktgrCt1_TGDFdX6-xM80KF9GgNfADE/getMe");
	std::cout << js;
	CURL *curl;
	CURLcode res;

	curl = curl_easy_init();
	if (curl) {
		curl_easy_setopt(curl, CURLOPT_URL, "http://api.telegram.org/bot209137847:AAH7uktgrCt1_TGDFdX6-xM80KF9GgNfADE/getMe");
		/* example.com is redirected, so we tell libcurl to follow redirection */
		curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

		/* Perform the request, res will get the return code */
		res = curl_easy_perform(curl);
		/* Check for errors */
		if (res != CURLE_OK)
			fprintf(stderr, "curl_easy_perform() failed: %s\n",
				curl_easy_strerror(res));

		/* always cleanup */
		curl_easy_cleanup(curl);
	}



	// 1. Parse a JSON string into DOM.
	const char* json = "{\"project\":\"rapidjson\",\"stars\":10}";
	Document d;
	d.Parse(json);

	// 2. Modify it by DOM.
	Value& s = d["stars"];
	s.SetInt(s.GetInt() + 1);

	// 3. Stringify the DOM
	StringBuffer buffer;
	Writer<StringBuffer> writer(buffer);
	d.Accept(writer);

	// Output {"project":"rapidjson","stars":11}
	std::cout << buffer.GetString() << std::endl;
	return 0;

	std::cout << "ds";
	return 0;
}
