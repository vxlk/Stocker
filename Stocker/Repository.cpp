#include "Repository.hpp"

namespace data {
Request::eResult Repository::Query(std::string name) {
	// this is where we make the http request
	return Request::eResult::Succeeded;
}

} //namespace data