#pragma once
#include <string>
namespace nptelebot {
namespace api {
	using namespace std;
	class Database {
	public:
		static Database& Create();
		Database();
		bool save(string filePath, string data);
		string load(string filePath);
	protected:
	//	Database& database;
	};
}
}