#include "ConsoleUI.hpp"
#include "Stocker.hpp"
#include "Request.hpp"
#include "json.hpp"

#include <iostream>

void ConsoleUI::Update() {
	m_data = "";
	//auto requestList = Application::StockerSession.Repository()->m_currentSnapShot;
	for (auto& request : Application::StockerSession.Repository()->m_currentSnapShot.requests)
		m_data += m_data += request.Data().Json().dump() + '\n';
}

void ConsoleUI::Display() {
	ConsoleUI::Update();
	std::cout << m_data;
}