#include "Stocker.hpp"
#include <iostream>

#define CURL_LIB_LOCATION "curl/libcurl-vc14-x86-release-static-ipv6-sspi-winssl/lib/libcurl_a"
#pragma comment(lib, CURL_LIB_LOCATION)

int main(void) {

	/*
	while (stockerApp->MainLoop()) {

	}
	*/

	Application::StockerSession.RunRequestTemporary();
	Application::StockerSession.UI()->Display();

	int x;
	std::cin >> x;
	
	return 0;
}