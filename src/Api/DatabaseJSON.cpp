#include "nptelebot/Api/DatabaseJSON.h"
#include "nptelebot/Api/Database.h"
#include "nptelebot/Api/HelpersRapidJSON.h"

#include <iostream>

namespace nptelebot {
namespace api {
	DatabaseJSON::DatabaseJSON()
		: _database(&Database::Create())
	{	
	}

	bool DatabaseJSON::save(string filePath, Document & jsonDoc)
	{
		string doc = HelpersRapidJson::ToString(jsonDoc);
		//database = Database::Create();
	//	database.save(filePath, doc);
		return true;
	}

	Document & DatabaseJSON::load(string filePath)
	{
		string json = _database->load(filePath);
		Document& ret = *new Document();
		if (ret.Parse(json.c_str()).HasParseError()) {
			cout << "! Failed to parse json from file: " << endl
				 << filePath << endl
				 << "Error code: " << ret.GetParseError() << endl;
		}
		else {
			return ret;
		}
		return *new Document();
	}

}
}
