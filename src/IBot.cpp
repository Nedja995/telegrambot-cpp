#include "nptelebot/IBot.h"

namespace nptelebot {
	bool IBot::initialize(std::string key)
	{
		_bot = new BotApi(key);
		User& user = _bot->getMe();
		return true;
	}
}