#pragma once

#include "Request.hpp"

namespace data {

struct SnapShot {
	std::vector<data::Request> requests;
};

class Repository {
public:
	SnapShot m_currentSnapShot;    // the most recent batch
	SnapShot m_sessionSnapShot;    // the batch since the application started running
	SnapShot m_todaysSnapShot;	   // the batch from today
	SnapShot m_historicalSnapShot; // every request ever made

	data::Request::eResult Query(std::string name);

	static constexpr const char* TOKEN = "6cLhhQNVyZdh4geiYXXEbuCs3djWNWVrWXEO24ZNc5a9mEmbQ8hsSe5WmEsF";
};

}