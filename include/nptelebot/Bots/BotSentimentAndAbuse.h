#pragma once
#include <string>
#include "nptelebot/Bot.h"
#include "nptelebot/IBot.h"

namespace nptelebot {
namespace bots {
	using namespace std;

	class BotSentimentAndAbuse : IBot {
	public:
	//	BotSentimentAndAbuse(string key);
		 ~BotSentimentAndAbuse() override;
		static BotSentimentAndAbuse& Create();
		// Inherited via IBot
		virtual bool initialize(std::string key) override;
		virtual bool run() override;

	protected:
		Bot* _bot;
		// Last responded message Id
		int _lastMessageId;

	};
}
}