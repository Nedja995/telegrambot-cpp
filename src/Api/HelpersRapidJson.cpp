#include "nptelebot/Api/HelpersRapidJson.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/writer.h"
namespace nptelebot {
	namespace api {
		string HelpersRapidJson::ToString(Document & doc)
		{
			rapidjson::StringBuffer buffer;

			buffer.Clear();

			rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
			doc.Accept(writer);

			return strdup(buffer.GetString());
		}
	}
}