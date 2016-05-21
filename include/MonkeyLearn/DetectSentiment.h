#pragma once
namespace npml {

	enum TextSentiment
	{
		Neutral, Positive, Negative
	};

	class DetectSentiment
	{
	public:
		TextSentiment detect(const char* text);
		DetectSentiment();
		~DetectSentiment();
	};

}