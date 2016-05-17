#pragma once
#include <iostream>
#include <vector>
#include "rapidjson/document.h"
namespace nptelebot
{ 
	using namespace std;
	class Audio;
	class User;
	class Update;
	class MessageEntity;
	class Message;
	class Audio;
	class Contact;
	class InlineQuery;
	class ChosenInlineResult;
	class CallbackQuery;
	class Venue;
	class Location;
	class Voice;
	class PhotoSize;
	class Sticker;
	class Video;
	class Document;

	class User
	{ 
	public:
		User() : id(0) {};
		User(rapidjson::Value& user);
		int id;
		string first_name;
		string username;
	};
	class Update
	{ 
	public:
		Update() : update_id(0), message(NULL), inline_query(NULL), chosen_inline_result(NULL), callback_query(NULL) {};
		Update(rapidjson::Value& update);
		unsigned int update_id;
		Message* message;
		InlineQuery* inline_query;
		ChosenInlineResult* chosen_inline_result;
		CallbackQuery* callback_query;
	};
	class Chat
	{ 
	public:
		Chat() : id(0) {};
		Chat(rapidjson::Value& chat);;
		int id;
		string type;
		string title;
		string username;
		string first_name;
		string last_name;
	};
	class MessageEntity 
	{ 
	public:
		string type;
		int offset;
		int length;
		string url;
	};
	class Message
	{ 
	public:
		// Create empty
		Message() : message_id(0), from(NULL), forward_from(NULL),
			forward_from_chat(NULL), audio(NULL), document(NULL),
			sticker(NULL), video(NULL), voice(NULL), location(NULL),
			venue(NULL), new_chat_member(NULL), left_chat_member(NULL),
			pinned_message(NULL) {};
		// Parse json
		Message(rapidjson::Value& message);

 		int message_id;
		User* from;
		int date;
		Chat* chat;
		User* forward_from;
		Chat* forward_from_chat;
		int forward_date;
		string text;
		vector<MessageEntity*> entities;
		Audio* audio;
		Document* document;
		vector<PhotoSize*> photo;
		Sticker* sticker;
		Video* video;
		Voice* voice;
		string caption;
		string contact;
		Location* location;
		Venue* venue;
		User* new_chat_member;
		User* left_chat_member;
		string new_chat_title;
		vector<PhotoSize*> new_chat_photo;
		bool delete_chat_photo;
		bool group_chat_created;
		bool supergroup_chat_created;
		bool channel_chat_created;
		Message* pinned_message;
	};
	class Audio
	{ 
	public:
		string file_id;
		int duration;
		string performer;
		string title;
		string mime_type;
		int file_size;
	};
	class Contact
	{ 
	public:
		string phone_number;
		string first_name;
		string last_name;
		int user_id;
	};
	class InlineQuery
	{ 
	public:
		string id;
		User* from;
		Location* location;
		string query;
		string offset;
	};
	class ChosenInlineResult
	{ 
	public:
		string result_id;
		User* from;
		Location* location;
		string inline_message_id;
		string query;
	};
	class CallbackQuery
	{ 
	public:
		string id;
		User* from;
		Message* message;
		string inline_message_id;
		string data;
	};
	class Venue
	{ 
	public:
		Location* location;
		string title;
		string address;
		string foursquare_id;
	};
	class Location
	{ 
	public:
		float longitude;
		float latitude;
	};
	class Voice
	{
	public:
		string file_id;
		int duration;
		string mime_type;
		int file_size;
	};
	class PhotoSize
	{ 
	public:
		string file_id;
		int width;
		int height;
		int file_size;
	};
	class Sticker
	{ 
	public:
		string file_id;
		int width;
		int height;
		PhotoSize* thumb;
		string emoji;
		int file_size;
	};
	class Video
	{
	public:
		string file_id;
		int width;
		int height;
		int duration;
		PhotoSize* thumb;
		string mime_type;
		int file_size;
	};
	class Document
	{ 
	public:
		string file_id;
		PhotoSize* thumb;
		string file_name;
		string mime_type;
		int file_size;
	};
};