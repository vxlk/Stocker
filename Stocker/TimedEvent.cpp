#include "TimedEvent.hpp"

TimedEvent::TimedEvent() {
	// time = now
	auto currentTime = time(nullptr);
	m_activationTime = std::make_unique<TimeStructure>(localtime(&currentTime));
	m_currentTime = std::make_unique<TimeStructure>(m_activationTime);
	m_interval = 10; // 10 seconds
}