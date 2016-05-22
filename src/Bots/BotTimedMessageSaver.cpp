#include "nptelebot/Bots/BotTimedMessageSaver.h"
//#include "nptelebot/Objects.h"

namespace nptelebot {
	namespace bots {
		bool BotTimedMessagesSaver::initialize(string key)
		{
			if (!ITimedBot::initialize(key)) {
				return false;
			}
			_database = new Database();
			filePath = "D:\\Projects\\TelegramBot\\telegrambot-cpp\\bin\\Debug\\db_messages.txt";
			return false;
		}
		bool BotTimedMessagesSaver::task(vector<Update*> newUpdates)
		{
			string messageString = _database->load(filePath);
			
			// Append messages
			for each (Update* update in newUpdates)
			{
				string str = update->message->from->first_name
							+ ":" + update->message->from->username
							+ ":" + to_string(update->message->from->id)
							+ ">" + update->message->text;
				messageString += str;
				messageString += '\n';
			}
			
			_database->save(filePath, messageString);
			return true;
		}
	}
}