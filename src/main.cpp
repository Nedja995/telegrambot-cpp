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

    App app(argc,argv);
    return app.Execute();
}

