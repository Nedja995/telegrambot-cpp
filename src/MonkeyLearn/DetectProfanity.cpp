#include "MonkeyLearn/DetectProfanity.h"
#include "MonkeyLearn/MonkeyLearn.h"
#include "rapidjson/document.h"
#include <iostream>

namespace npml {
	using namespace rapidjson;

	//https://app.monkeylearn.com/categorizer/projects/cl_KFXhoTdt/tab/classify-sandbox
	bool DetectProfanity::hasProfanity(string text)
	{
		bool ret = true;
		vector<const char*> texts;
		texts.push_back(text.c_str());
		auto jsonResponse = npml::MonkeyLearn::Instance().classify(texts, "cl_KFXhoTdt");
		rapidjson::Document doc;
		if (!doc.Parse(jsonResponse).HasParseError()) {
			Value& results = doc["result"];
			Value& first = results[0][0];
			if (!first.HasMember("label")) {
				std::cerr << "hasProfanity: Cannot parse response: no \"label\". JSON: " << jsonResponse << std::endl;
				return false;
			}
			string label = first["label"].GetString();
			if (label == "clean") {
				ret = false;
			}
		}
		else {
			//Cannot read error
			std::cerr << "getResult: Cannot parse response: " << jsonResponse << std::endl;
			return false;
		}
		return ret;
	}
	
}