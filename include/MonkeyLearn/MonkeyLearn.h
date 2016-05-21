#pragma once
#include <string>
#include <vector>

namespace npml {
	using namespace std;
	class MonkeyLearn
	{
	public:
		char* Authorization_Token;
		static MonkeyLearn& Instance();
		char* classify(vector<const char*> texts, const char* moduleID);
		string authorizationToken;
	protected:
		MonkeyLearn();
		~MonkeyLearn();
	private:
		static MonkeyLearn* _instance;
		
		
	};
}