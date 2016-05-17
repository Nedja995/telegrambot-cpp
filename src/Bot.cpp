#include "nptelebot/Bot.h"
#include "nptelebot/ResponseData.h"

#include <algorithm>
#include <iostream>
namespace nptelebot
{

	using namespace std;
	using namespace response;

	Bot::Bot(std::string key)
	{
		curl = &CurlTools::Create();
		url = "https://api.telegram.org/bot" + key + "/";
	}

	User& Bot::getMe()
	{
		//auto ret = true;
		auto resp = curl->Request(url + "getMe");
		if (_parseResponse(resp))
		{
			User& ret = *new User;
			Value& result = _lastResponse["result"];
			ret.id = result["id"].GetInt();
			ret.first_name = result["first_name"].GetString();
			ret.username = result["username"].GetString();
			return ret;
		}
		else
		{
			// Not ok
		}
//		Value res(c.c_str(), 100);
		
		
		

	//	Value& id = res["id"];
	//	ret.id = id.GetInt();
	//	delete resp;
		// 2. Modify it by DOM.

		//cout << s.GetBool();

	/*	Value& res1 = d["result"];
		Value& first = res1[0];
		Value& msg = first["message"];
		Value& text = msg["text"];
		cout << text.GetString();*/
		return *new User;
	}

	vector<Update*> Bot::getUpdates(int offset)
	{
		auto ret = vector<Update*>();
		auto resp = curl->Request(url + "getUpdates");
		if (_parseResponse(resp))
		{
			Value& results = _lastResponse["result"];

			for (SizeType i = 0; i < results.Size(); i++) {
				Value& result = results[i];
				//-Update
				ret.push_back(new Update(result));
			}
			
		}
		else
		{
			// Not ok
		}

		return ret;
	}

	void Bot::setTyping()
	{
		auto resp = curl->Request(url + "sendChatAction?action=typing&chat_id=180771137");	
	}

	Bot::~Bot()
	{
	}

	bool Bot::_parseResponse(const char* request)
	{
		//Document d;

		if (!_lastResponse.Parse(request).HasParseError())
		{
			Value& s = _lastResponse["ok"];
			if (!s.GetBool()) {
				std::cerr << "getResult: Response not Ok: " << request << std::endl;
				return false;
			}
		}
		else {
			std::cerr << "getResult: Cannot parse response: " << request << std::endl;
			return false;
		}
		//Value& result = _lastResponse["result"];

		//	Value* resP = GetValueByPointer(d, "result");
		//	Value& idd = *res;
		//	Document::AllocatorType& a = d.GetAllocator();
		//	Value re(result, a);


	/*	StringBuffer buffer;
		Writer<StringBuffer> writer(buffer);
		result.Accept(writer);
		const char* output = buffer.GetString();*/

		//	Value& id = re["id"];
		//	auto ret = id.GetInt();

		return true;

	}
}