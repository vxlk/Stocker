#pragma once

#include <memory>

#include "IUI.hpp"
#include "Repository.hpp"

class Stocker {
public:

	enum class eUIType {
		Console,
		Gui
	};

	Stocker(eUIType);

	void RunRequestTemporary();

	// Retrieve the ui associated with the application
	IUI* UI() const noexcept					  { return m_pUI.get(); }
	// Retrieve the database associated with the application
	data::Repository* Repository() const noexcept { return m_pRepo.get(); }

	// Non-copyable object
	Stocker() = delete;
	Stocker& operator=(const Stocker&) = delete;
	Stocker(const Stocker&) = delete;

private:
	std::unique_ptr<IUI> m_pUI;
	std::unique_ptr<data::Repository> m_pRepo;
};

// -------------------------------------------------------------------
namespace Application {
// retrieve the object from the current session
static Stocker StockerSession(Stocker::eUIType::Console);
}
// -------------------------------------------------------------------