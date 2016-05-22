#pragma once
#include "ITimedBot.h"
#include "nptelebot/Api/DatabaseJSON.h"
namespace nptelebot {
namespace bots {
	using namespace api;
class BotTimedMessagesSaver : public ITimedBot
{
public:
	string filePath;
	// Inherited via ITimedBot
	virtual bool initialize(string key) override;
	virtual bool task(vector<Update*> newUpdates) override;
protected:
	Database* _database;
};


}
}