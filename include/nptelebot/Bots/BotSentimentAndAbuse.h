#pragma once
#include <string>
#include "nptelebot/Bot.h"

namespace nptelebot {
namespace bots {
	using namespace std;

	class BotSentimentAndAbuse {
	public:
		BotSentimentAndAbuse(string key);
		static BotSentimentAndAbuse& Create(string key);
		bool initialize();
		bool run();
	protected:
		Bot* _bot;
		// Last responded message Id
		int _lastMessageId;
	};
}
}