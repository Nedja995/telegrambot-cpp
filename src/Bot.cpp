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
			Value& result = _response["result"];
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

	vector<Update*> Bot::getUpdates(int limit)
	{
		auto ret = vector<Update*>();
		//base request
		auto req = url + "getUpdates"; 
		//add offset if exists
		if (limit > 0) req += "?offset=-" + to_string(limit); 
		// Request
		auto resp = curl->Request(req);
		// Parse response
		if (_parseResponse(resp)){
			// Parse Updates from parsed response
			Value& results = _response["result"];
			for (SizeType i = 0; i < results.Size(); i++) {
				Value& result = results[i];
				ret.push_back(new Update(result));
			}
		}
		else{
			// Not ok
		}
		return ret;
	}

	void Bot::setTyping(int chat_id)
	{
		auto resp = curl->Request(url + "sendChatAction?action=typing&chat_id=" + to_string(chat_id));
	}

	void Bot::sendMessage(int chat_id, string message)
	{
		auto resp = curl->Request(url + "sendMessage?chat_id=" +  to_string(chat_id) + "&text=" + message);
	}

	Bot::~Bot()
	{
	}

	bool Bot::_parseResponse(const char* responseJson)
	{
		if (!_response.Parse(responseJson).HasParseError()){
			Value& s = _response["ok"];
			if (!s.GetBool()) {
				//Not Ok result error
				std::cerr << "getResult: Response not Ok: " << responseJson << std::endl;
				return false;
			}
		}
		else {
			//Cannot read error
			std::cerr << "getResult: Cannot parse response: " << responseJson << std::endl;
			return false;
		}
		//Value& result = _response["result"];

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