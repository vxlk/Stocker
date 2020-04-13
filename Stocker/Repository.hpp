#pragma once

#include "Request.hpp"
#include "curl/curl.h"

namespace data {

struct SnapShot {
	std::vector<data::Request> requests;
};

class Repository {

	CURL*		m_pCurl;
	CURLcode	m_curlResult;
	std::string m_readBuffer;

public:
	SnapShot m_currentSnapShot;    // the most recent batch
	SnapShot m_sessionSnapShot;    // the batch since the application started running
	SnapShot m_todaysSnapShot;	   // the batch from today
	SnapShot m_historicalSnapShot; // every request ever made

	data::Request::eResult Query(std::string name);

	//static constexpr const char* TOKEN = "6cLhhQNVyZdh4geiYXXEbuCs3djWNWVrWXEO24ZNc5a9mEmbQ8hsSe5WmEsF";
	static constexpr const char* TOKEN = "6cLhhQNVyZdh4geiYXXEbuCs3djWNWVrWXEO24ZNc5a9mEmbQ8hsSe5WmEsF";
	// GONNA have to split for options later on
	static constexpr const char* URL = "https://api.worldtradingdata.com/api/v1/stock?symbol=SNAP,TWTR&api_token=";
	//static constexpr const char* URL = "https://api.worldtradingdata.com/api/v1/history?symbol=TWTR&api_token=";

	Repository();
	~Repository();
};

}