#include <iostream>
#include <algorithm>
#include <string>

#include "app.h"
#include "appinfo.h"


#include "nptelebot/Bot.h"
#include "nptelebot/ResponseData.h"

using namespace std;
using namespace nptelebot;
using namespace response;

static string key = "209137847:AAH7uktgrCt1_TGDFdX6-xM80KF9GgNfADE";

App::App(int& argc, char** argv) 
{
	
}

App::~App()
{
}

int App::Execute()
{
	Bot& bot = *new Bot(key.c_str());
	User& user = bot.getMe();
	cout << user.first_name << " " << user.username << " " << user.id << endl;

	auto updates = bot.getUpdates(2);

	/*if (user == NULL) {
		cerr << "getMe: Failed" << endl;
		return 1;
	}*/
	//int id = User::id);
//	cout << id;
	//Value& res1 = d["result"];
	//Value& first = res1[0];
	//Value& msg = first["message"];
	//Value& text = msg["text"];
	//cout << text.GetString();
	//// 3. Stringify the DOM
	//StringBuffer buffer;
	//Writer<StringBuffer> writer(buffer);
	//d.Accept(writer);

	//// Output {"project":"rapidjson","stars":11}
	//std::cout << buffer.GetString() << std::endl;
	//return 0;

	//std::cout << "ds";
	return 0;
}
