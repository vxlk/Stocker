#include "Request.hpp"
#include "curl/curl.h"

namespace data {

RequestObject Request::Fetch(std::string queryObj) {
	JSONObject obj;
	obj.parse(queryObj);
	return { obj };
}


RequestObject Request::Data() {
	// poop
	return *m_data;
}

} //namespace data