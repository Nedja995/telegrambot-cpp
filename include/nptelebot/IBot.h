#pragma once
#include <string>
#include "nptelebot/Api/BotApi.h"
namespace nptelebot {
	class IBot {
	public:
		IBot() {};
		virtual ~IBot() = 0 {} ;
		virtual bool initialize(std::string key);
		virtual bool run() = 0;
	protected:
		BotApi* _bot;
	};
};