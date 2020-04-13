#include "Repository.hpp"
#include "Request.hpp"

//temp
#include <iostream>
namespace {
	//cURL buffer setup
static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
	((std::string*)userp)->append((char*)contents, size * nmemb);
	return size * nmemb;
}
}

namespace data {

Repository::Repository() {
	m_pCurl = curl_easy_init();

	assert(m_pCurl != nullptr);

	curl_easy_setopt(m_pCurl, CURLOPT_SSL_VERIFYPEER, 0L); //only for https
	curl_easy_setopt(m_pCurl, CURLOPT_SSL_VERIFYHOST, 0L); //only for https

	curl_easy_setopt(m_pCurl, CURLOPT_WRITEFUNCTION, ::WriteCallback);
	curl_easy_setopt(m_pCurl, CURLOPT_WRITEDATA, &m_readBuffer);

	curl_easy_setopt(m_pCurl, CURLOPT_USERAGENT, "libcurl-agent/1.0");
	//if (m_pCurl) {
		//curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
		//curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
		//m_res = curl_easy_perform(curl);
}

Repository::~Repository() {
	curl_easy_cleanup(m_pCurl);
}

Request::eResult Repository::Query(std::string name) {
	// construct the url for the request
	std::string url = std::string(Repository::URL) + std::string(Repository::TOKEN);
	
	curl_easy_setopt(m_pCurl, CURLOPT_URL, url.c_str());
	
	m_curlResult = curl_easy_perform(m_pCurl);

	/* Check for errors */
	if (m_curlResult != CURLE_OK)
		fprintf(stderr, "curl_easy_perform() failed: %s\n",
			curl_easy_strerror(m_curlResult));

	Request request(name);
	std::cout << m_readBuffer;
	auto result = request.Fetch(m_readBuffer);
	
	//assert(result == Request::eResult::Succeeded);
	// this is where we make the http request
	return Request::eResult::Succeeded;
}

} //namespace data