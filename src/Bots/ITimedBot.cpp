#include "nptelebot/Bots/ITimedBot.h"
#include <atlcomcli.h> 
namespace nptelebot {
	namespace bots {
		bool ITimedBot::run()
		{
			int retCode = 0;
			while (retCode == 0) {
				// LOOP START
				auto updates = _bot->getUpdates(_offset);
				// Update offset
				_offset += updates.size();
				// CALL CUSTOM TASK
				task(updates);
				// WAIT TIME
				_sleep(miliseconds);
				// END LOOP
			}
			return true;
		}
		bool ITimedBot::initialize(string key)
		{
			if (!IBot::initialize(key)) {
				return false;
			}
			miliseconds = 10000;
			return true;
		}
	}
}