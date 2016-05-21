#include "nptelebot/Bots/BotSentimentAndAbuse.h"
#include <algorithm>
#include <atlcomcli.h> 
#include "MonkeyLearn/DetectProfanity.h"
#include "MonkeyLearn/DetectSentiment.h"

namespace nptelebot {
namespace bots {

	BotSentimentAndAbuse::BotSentimentAndAbuse(string key)
		: _bot(new Bot(key))
	{
	}
	BotSentimentAndAbuse & BotSentimentAndAbuse::Create(string key)
	{
		return *new BotSentimentAndAbuse(key);
	}
	bool BotSentimentAndAbuse::initialize()
	{
		auto user = _bot->getMe();
		return true;
	}
//	CComPtr<IProgram> yourClass;
	bool BotSentimentAndAbuse::run()
	{
		auto profanityDetector = npml::DetectProfanity();
		auto sentimentDector = npml::DetectSentiment();

		while (true) {
			auto updates = _bot->getUpdates(1);
			if (updates.size() > 0) {
				auto update = updates[0];
				if (_lastMessageId != update->message->message_id)
					_lastMessageId = update->message->message_id;
				else
					// MESSAGE ALREADY RESPONDED - SKIP
					continue;
				auto chat = update->message->chat;
				if (chat != NULL) {
					_bot->setTyping(chat->id);
					//--BOT LOGIC AND RESPOND
					//Detect and respong to PROFANITY
					string warant;
					auto profanityText = profanityDetector.hasProfanity(update->message->text);
					if (profanityText) {
						//PROFANITY DETECTED
						warant = "Pay attention to your words!!!";
						//_bot->sendMessage(chat->id, "Pay attention to your words!!!");
					}
					else {
						//NO Profanity
						//_bot->sendMessage(chat->id, "Nije uvredljiv odgovor :)");
					}
					//Detect and respong to PROFANITY
					auto sentiment = sentimentDector.detect(update->message->text.c_str());
					if (sentiment == npml::TextSentiment::Negative) {
						//PROFANITY DETECTED
						_bot->sendMessage(chat->id, "Why are you so negative? " + warant);
					}
					else if (sentiment == npml::TextSentiment::Positive) {
						//PROFANITY DETECTED
						_bot->sendMessage(chat->id, "It is good to be positive :) " + warant);
					}
					else if (sentiment == npml::TextSentiment::Neutral) {
						//PROFANITY DETECTED
					//	_bot->sendMessage(chat->id, "It is good to be positive");
					}
					//_sleep(3000);
					//std::transform(update->message->text.begin(), update->message->text.end(), update->message->text.begin(), ::toupper);
					//_bot->sendMessage(chat->id, update->message->text);
					//--END BOT LOGIC
				}
			}
		}
		return true;
	}
}
}