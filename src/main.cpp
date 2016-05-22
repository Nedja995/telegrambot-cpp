#include "app.h"
#include "curl/curl.h"

void initThirdParty()
{
	// Haxx Curl
	curl_global_init(CURL_GLOBAL_DEFAULT);
}

int main(int argc, char* argv[])
{
	initThirdParty();

	//debug params
	argc = 3;
	char* argvDebug[] = {
		"",
		"209137847:AAH7uktgrCt1_TGDFdX6-xM80KF9GgNfADE",
		"SentimentAndAbuse"
	};

    nptelebot::App app(argc, argvDebug);
    return app.Execute();
}

