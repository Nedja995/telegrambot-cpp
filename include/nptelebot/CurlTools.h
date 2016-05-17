#pragma once
#include <string>
namespace nptelebot
{
	class CurlTools
	{
	public:
		static CurlTools& Create();
		char* Request(std::string url);
	};
}