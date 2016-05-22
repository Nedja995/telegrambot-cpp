#pragma once
#include <string>
#include "nptelebot/Api/Database.h"
#include "rapidjson/document.h";
namespace nptelebot {
namespace api {
	using namespace std;
	using namespace rapidjson;

	class DatabaseJSON {
	public:
		DatabaseJSON();
		bool save(string filePath, Document& jsonDoc);
		Document& load(string filePath);
	protected:
		Database* _database;
	};
}
}