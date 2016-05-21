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
		vector<Update*> getUpdates(int limit);
		void setTyping(int chat_id);
		void sendMessage(int chat_id, string message);
		~Bot();
	protected:
		// Recive response and store in _response;
		bool _parseResponse(const char* responseJson);
		rapidjson::Document _response;
		std::string url;
		CurlTools* curl;
	};
}