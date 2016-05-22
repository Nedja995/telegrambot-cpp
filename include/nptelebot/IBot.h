#pragma once
#include <string>
#include "nptelebot/Bot.h"
namespace nptelebot {
	class IBot {
	public:
		IBot() {};
		virtual ~IBot() = 0 {} ;
		virtual bool initialize(std::string key) = 0;
		virtual bool run() = 0;
	protected:
		Bot* _bot;
	};
};