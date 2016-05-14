#include "nptelebot/Bot.h"
#include "rapidjson/document.h"
#include <algorithm>
namespace nptelebot
{
	using namespace rapidjson;
	using namespace std;

	Bot::Bot(std::string key)
	{
		curl = &CurlTools::Create();
		url = "https://api.telegram.org/bot209137847:AAH7uktgrCt1_TGDFdX6-xM80KF9GgNfADE/";
	}

	bool Bot::getMe()
	{
		auto resp = curl->Request((url + "getMe").c_str());
		// Remove \0
	//	resp.erase(std::remove(resp.begin(), resp.end(), '\0'), resp.end());

		Document d;

		d.Parse(resp);

		// 2. Modify it by DOM.
		Value& s = d["ok"];
		auto ret = s.GetBool();
		//cout << s.GetBool();

	/*	Value& res1 = d["result"];
		Value& first = res1[0];
		Value& msg = first["message"];
		Value& text = msg["text"];
		cout << text.GetString();*/
		return ret;
	}


	string Bot::getUpdates(int offset)
	{
		return "";
	}

	Bot::~Bot()
	{
	}
}