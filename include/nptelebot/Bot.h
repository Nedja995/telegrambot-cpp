#pragma once
#include <string>
#include "nptelebot/Objects.h"
#include "nptelebot/CurlTools.h"
#include "rapidjson/document.h"
namespace nptelebot
{
	using namespace rapidjson;
	class Bot
	{
	public:
		std::string key;
		Bot(std::string key);
		User& getMe();
		vector<Update*> getUpdates(int offset);
		void setTyping(string chat_id);
		void sendMessage(int chat_id, string message);
		~Bot();
	protected:
		bool _parseResponse(const char* request);
		rapidjson::Document _lastResponse;
		std::string url;
		CurlTools* curl;
	};
}