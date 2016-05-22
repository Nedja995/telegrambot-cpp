#include "nptelebot/Api/DatabaseJSON.h"
#include "nptelebot/Api/Database.h"
#include "nptelebot/Api/HelpersRapidJSON.h"
namespace nptelebot {
namespace api {
	DatabaseJSON::DatabaseJSON()
	{
	//	database = Database::Create();
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
		return *new Document();
	}

}
}
