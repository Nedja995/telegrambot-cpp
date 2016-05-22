#pragma once
#include <string>
#include "nptelebot/Api/BotApi.h"
#include "nptelebot/IBot.h"

namespace nptelebot {
namespace bots {
	using namespace std;

	class BotSentimentAndAbuse : IBot {
	public:
		static BotSentimentAndAbuse& Create();
		// Inherited via IBot
		 ~BotSentimentAndAbuse() override;
//		virtual bool initialize(std::string key) override;
		virtual bool run() override;

	protected:
		BotApi* _bot;
		// Last responded message Id
		int _lastMessageId;

	};
}
}