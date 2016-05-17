#include "nptelebot/Objects.h"

namespace nptelebot {

	Message::Message(rapidjson::Value& message) : Message() {
		if (message.HasMember("message_id")) message_id = message["message_id"].GetInt();
		if (message.HasMember("date")) date = message["date"].GetInt();
		if (message.HasMember("text")) text = message["text"].GetString();
		//--From
		if (message.HasMember("from"))from = new User(message["from"]);
		//--Chat
		if (message.HasMember("chat"))chat = new Chat(message["chat"]);
	};

	Update::Update(rapidjson::Value& update) : Update() {
		if (update.HasMember("update_id")) update_id = update["update_id"].GetInt();
		if (update.HasMember("message")) message = new Message(update["message"]);
	};

	Chat::Chat(rapidjson::Value& chat) : Chat() {
		if (chat.HasMember("id")) id = chat["id"].GetInt();
		if (chat.HasMember("first_name")) first_name = chat["first_name"].GetString();
		if (chat.HasMember("username")) username = chat["last_name"].GetString();
		if (chat.HasMember("type")) type = chat["type"].GetString();
	};

	User::User(rapidjson::Value& user) : User() {
		if (user.HasMember("id")) id = user["id"].GetInt();
		if (user.HasMember("first_name")) first_name = user["first_name"].GetString();
		if (user.HasMember("last_name")) username = user["last_name"].GetString();
	};
}