// <Copyright Holder>. Copyright (C) <Copyright Year(s)>. <License>.
#ifndef HEADER_SRC_APP_H_INCLUDED
#define HEADER_SRC_APP_H_INCLUDED

class App
{
    public:
		App(int& argc, char** argv);
		~App();
		int Execute();
};

#endif
