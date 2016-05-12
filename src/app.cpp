#include <iostream>
#include <string.h>
#include "app.h"
#include "appinfo.h"

#include "lib.h"

App::App(int& argc, char** argv) 
{
	
}

App::~App()
{
}

int App::Execute()
{
	Lib *lib = new Lib();
	std::string msg = lib->Message();
	std::cout << msg.c_str();
	return 0;
}
