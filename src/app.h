// <Copyright Holder>. Copyright (C) <Copyright Year(s)>. <License>.
#ifndef HEADER_SRC_APP_H_INCLUDED
#define HEADER_SRC_APP_H_INCLUDED
#include "nptelebot/IBot.h"

namespace nptelebot {
	class App
	{
	public:
		App(int argc, char* argv[]);
		~App();
		int Execute();
	protected:
		IBot* _bot;
		bool createBot(string botName);
	};
}
#endif
