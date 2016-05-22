#include "nptelebot/Api/Database.h"
#include <fstream>
#include <iostream>
namespace nptelebot {
namespace api {
	Database & Database::Create()
	{
		return *new Database();
	}
	Database::Database()
	{

	}
	bool Database::save(string filePath, string data)
	{
		ofstream myfile;
		myfile.open(filePath);
		myfile << data;
		myfile.close();
		return true;
	}
	string Database::load(string filePath)
	{
		string ret;
		string line;
		ifstream myfile(filePath);
		
		if (myfile.is_open())
		{
			while (getline(myfile, line))
			{
				ret.append(line);
			}
			myfile.close();
		}
		else cout << "Unable to open file";
		return ret;
	}
}
}