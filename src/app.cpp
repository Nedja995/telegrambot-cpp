#include <iostream>
#include <algorithm>
#include <string>
#include <stdlib.h>     // for _sleep() 
#include "app.h"
#include "appinfo.h"

#include "nptelebot/Bots/BotSentimentAndAbuse.h"
#include "nptelebot/Bots/BotTimedMessageSaver.h"

using namespace std;
using namespace nptelebot;

static string key = "209137847:AAH7uktgrCt1_TGDFdX6-xM80KF9GgNfADE";

App::App(int argc, char* argv[])
	: _bot(nullptr)
{
	if (argc == 3) {
		key = argv[1];
		if (!createBot(argv[2])) {
			cout << "! Error starting bot with name: " << argv[2] << endl;
			system("PAUSE");
			exit(EXIT_FAILURE);
		}
	}
	else {
		cout << "! Error starting bot. Need arguments: <MonkeyLearn.com Api Key> <bot>" << endl;
		cout << "Available bots:" << endl;
		cout << "	SentimentAndAbuse" << endl;
		cout << "	TimedMessageSaver" << endl;
		cout << "	" << endl;
		system("PAUSE");
		exit(EXIT_FAILURE);
	}
}

bool App::createBot(string botName)
{
	if (botName == "SentimentAndAbuse") {
		_bot = (IBot*)new bots::BotSentimentAndAbuse();
		cout << "Create bot that responds to Positive or Negative sentinces and Profanity words.";
		return true;
	}
	else if (botName == "TimedMessageSaver") {
		cout << "Create bot that save all messages at given interval.";
		_bot = (IBot*)new bots::BotTimedMessagesSaver();
		return true;
	}
	return false;
}

App::~App()
{
	delete _bot;
}

int App::Execute()
{
	_bot->initialize(key);
	_bot->run();
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

