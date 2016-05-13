#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <string>

#include "app.h"
#include "appinfo.h"


#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"

#include "curl/curl.h"

using namespace std;
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


		std::ofstream myfile;
		myfile.open("example.txt");
		myfile << data;
		myfile.close();

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
	std::string js = DownloadJSON("https://api.telegram.org/bot209137847:AAH7uktgrCt1_TGDFdX6-xM80KF9GgNfADE/getUpdates?offset=-1");
//	std::cout << js;
	CURL *curl;
	CURLcode res;

	// 1. Parse a JSON string into DOM.
	const char* json = "{\"ok\":true,\"result\":{\"id\":209137847,\"first_name\":\"NedjaBot\",\"username\":\"NedjaBot\"}}"; //
//	const char* json = "{\"project\":\"rapidjson\",\"stars\":10}";
	Document d;
	
	//remove null terminated
	js.erase(std::remove(js.begin(), js.end(), '\0'), js.end());

	d.Parse(js.c_str());

	// 2. Modify it by DOM.
	Value& s = d["ok"];
	cout << s.GetBool();

	Value& res1 = d["result"];
	Value& first = res1[0];
	Value& msg = first["message"];
	Value& text = msg["text"];
	cout << text.GetString();
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
