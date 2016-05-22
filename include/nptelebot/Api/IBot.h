#pragma once
#include <string>
#include "nptelebot/Bot.h"
namespace nptelebot {
	class IBot {
	public:
		IBot(std::string key) : _bot(new Bot(key)) {}
		virtual ~IBot() {}
		virtual bool initialize() = 0;
		virtual bool run() = 0;
	protected:
		Bot* _bot;
	};
};