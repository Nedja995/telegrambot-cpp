#include "MonkeyLearn/DetectSentiment.h"
#include "MonkeyLearn/MonkeyLearn.h"
#include "rapidjson/document.h"
#include <iostream>
#include <vector>
namespace npml {
	using namespace std;
	using namespace rapidjson;

	//https://app.monkeylearn.com/categorizer/projects/cl_qkjxv9Ly/tab/main-tab
	TextSentiment DetectSentiment::detect(const char * text)
	{
		bool ret = true;
		vector<const char*> texts;
		texts.push_back(text);
		auto jsonResponse = npml::MonkeyLearn::Instance().classify(texts, "cl_qkjxv9Ly");
		rapidjson::Document doc;
		if (!doc.Parse(jsonResponse).HasParseError()) {
			Value& results = doc["result"];
			Value& first = results[0][0];
			if (!first.HasMember("label")) {
				std::cerr << "hasProfanity: Cannot parse response: no \"label\". JSON: " << jsonResponse << std::endl;
				return TextSentiment::Neutral;
			}
			string label = first["label"].GetString();
			if (label == "neutral") {
				return TextSentiment::Neutral;
			}
			else if (label == "positive") {
				return TextSentiment::Positive;
			}
			else if (label == "negative") {
				return TextSentiment::Negative;
			}
		}
		else {
			//Cannot read error
			std::cerr << "getResult: Cannot parse response: " << jsonResponse << std::endl;
			return TextSentiment::Neutral;
		}
		return TextSentiment::Neutral;
	}
	DetectSentiment::DetectSentiment()
	{
	}


	DetectSentiment::~DetectSentiment()
	{
	}
}
