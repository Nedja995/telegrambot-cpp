#pragma once
#include "nptelebot/IBot.h"
#include "vector"
namespace nptelebot {
namespace bots {
	using namespace std;

	class ITimedBot : IBot {
	public:
		int miliseconds;
		int seconds;
		int minutes;
		int hours;
		virtual bool task(vector<Update*> newUpdates) = 0;
		// Inherited via IBot
		virtual bool run() override;
		virtual bool initialize(string key) override;
	protected:
		int _offset;
	};
}
}