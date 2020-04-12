#pragma once

#include <string>

class IUI {
protected:
	// Called by Display() to update the ui to match the data in the repository
	virtual void Update() = 0;
public:
	// Called by the application to show the gui
	virtual void Display() = 0;
};
