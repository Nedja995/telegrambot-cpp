#pragma once
#include <string>
#include "rapidjson/document.h"
namespace nptelebot {
	namespace api {
		using namespace std;
		using namespace rapidjson;
		static class HelpersRapidJson {
		public:
			static string ToString(Document& doc);
		};
	}
}