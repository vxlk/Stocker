#include "Stocker.hpp"
#include "Request.hpp"
#include "ConsoleUI.hpp"
#include "Repository.hpp"

Stocker::Stocker(Stocker::eUIType uiLevel) {
	switch (uiLevel) {
		case Stocker::eUIType::Console: m_pUI = std::make_unique<ConsoleUI>();
	}
	m_pRepo = std::make_unique<data::Repository>();
}
void Stocker::RunRequestTemporary() {
	assert(m_pRepo && m_pUI);
	auto result = m_pRepo->Query("Test");
	assert(result == data::Request::eResult::Succeeded);
}
