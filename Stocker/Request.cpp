#include "Request.hpp"
#include "curl/curl.h"

namespace data {

Request::eResult Request::Fetch() {
	return Request::eResult::Succeeded;
}


RequestObject Request::Data() {
	return m_data;
}

} //namespace data