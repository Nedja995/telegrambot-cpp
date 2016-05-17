#pragma once
#include "rapidjson/document.h"
#include <iostream>
#include "rapidjson/stringbuffer.h"
#include "rapidjson/writer.h"
#include "rapidjson/pointer.h"

namespace nptelebot {
	/*!  
	* Parse responsed json
	*/
	namespace response {
//		using namespace rapidjson;
		
		//static Value& getResult_alloc(const char* json)
		//{
		//	rapidjson::Document d;

		//	if (!d.Parse(json).HasParseError())
		//	{
		//		Value& s = d["ok"];
		//		if (!s.GetBool()) {
		//			std::cerr << "getResult: Response not Ok: " << json << std::endl;
		//			return Value();
		//		}
		//	}
		//	else {
		//		std::cerr << "getResult: Cannot parse response: " << json << std::endl;
		//		return Value();
		//	}
		//	Value& result = d["result"];
		//	
		////	Value* resP = GetValueByPointer(d, "result");
		////	Value& idd = *res;
		////	Document::AllocatorType& a = d.GetAllocator();
		////	Value re(result, a);


		//	StringBuffer buffer;
		//	Writer<StringBuffer> writer(buffer);
		//	result.Accept(writer);
		//	const char* output = buffer.GetString();

		////	Value& id = re["id"];
		////	auto ret = id.GetInt();
		//	char* s;
		////	id.Accept(s);
		//	//auto a = new Value(id);
		//	return std::move(result);
		//}


		/*static class User
		{
		public:
			static int id(Value& user);
		};*/
	}
}