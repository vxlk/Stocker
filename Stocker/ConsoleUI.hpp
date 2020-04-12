#pragma once

#include "IUI.hpp"
#include <string>

// An implementation of the UI interface that spits
// data out to a windows console
class ConsoleUI : public IUI {
	
	std::string m_data;

protected:
	void Update() override;

public:
	void Display() override;
};
