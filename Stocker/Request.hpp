#pragma once

#include "json.hpp"
#include <vector>
#include <ctime>

namespace data {

using JSONObject = nlohmann::json;
// A wrapper around a json response object
// knows how to display / serialize itself
class RequestObject {
	// ----------------- data ------------------
	JSONObject m_cachedJSONObject;
	// -----------------------------------------
public:
	RequestObject(JSONObject obj) : m_cachedJSONObject(obj) {}
	// Return the data this object holds as json
	JSONObject Json() { return m_cachedJSONObject; }
};

// Handles an HTTP request to the world wide trading data rest api
// A wrapper around a curl HTTP request, also holds the data returned
// from the request
// Requests will be broken down into sub-requests if needed (due to 
// license limitations) but will we composed into one object
class Request {

	std::vector<Request> m_subRequestList;
	std::unique_ptr<RequestObject> m_data = nullptr;
	std::string m_name;
	time_t m_timeOfRequest;

public:
	
	enum class eResult {
		Succeeded,
		Failed
	};
	
	Request(std::string name) : m_name(name) {}

	// Populate the data of this request by passing in the query string
	RequestObject		  Fetch(std::string queryObj);

	// Retrieve the underlying data of this request
	RequestObject Data();

	// Return the named identifier of this request
	std::string   Name();

	// Retrieve the time that this request was made
	time_t		  TimeStamp() const noexcept { return m_timeOfRequest; }

	unsigned int  Size()	  const noexcept { return m_subRequestList.size(); }
	// A request is unique, a new one should be made for each query
	Request() = delete;
	Request& operator=(const Request&) = delete;
	Request(const Request&) = delete;
};
} // namespace http