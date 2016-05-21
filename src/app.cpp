#include <iostream>
#include <algorithm>
#include <string>
#include <stdlib.h>     // for _sleep() 
#include "app.h"
#include "appinfo.h"


//#include "nptelebot/Bot.h"
//#include "nptelebot/ResponseData.h"

#include "nptelebot/Bots/BotSentimentAndAbuse.h"

using namespace std;
using namespace nptelebot;

static string key = "209137847:AAH7uktgrCt1_TGDFdX6-xM80KF9GgNfADE";

App::App(int& argc, char** argv) 
{
	
}

App::~App()
{
}

int App::Execute()
{
	cout << "Start bot that responds to Positive or Negative sentinces and Profanity words.";
	bots::BotSentimentAndAbuse& translater = bots::BotSentimentAndAbuse::Create(key);
	translater.initialize();
	translater.run();
	//Bot& bot = *new Bot(key.c_str());
	//User& user = bot.getMe();
	//cout << user.first_name << " " << user.username << " " << user.id << endl;

	//auto updates = bot.getUpdates(1);
	//if (updates.size() > 0) {
	//	auto update = updates[0];
	//	auto chat = update->message->chat;
	//	if (chat != NULL) {
	//		bot.setTyping(chat->id);
	//		_sleep(3000);
	//		bot.sendMessage(chat->id, "Odgovor od bota");
	//	}
	//}
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
