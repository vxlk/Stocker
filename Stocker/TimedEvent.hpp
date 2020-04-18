#pragma once

#include <functional>
#include <vector>
#include <ctime>
#include <string>
#include <thread>
#include <mutex>
#include <atomic>

using TimeStructure = tm;

class TimedEvent {

	std::vector<std::pair<std::string, std::function<void()>>> m_callbacks;
	
	std::unique_ptr<TimeStructure> m_activationTime;
	std::unique_ptr<TimeStructure> m_currentTime;
	time_t m_interval;

	std::thread blockedThread;
	std::atomic<bool> isLooping = false;
	std::mutex m_mutex;

public:
	// Construct and keep track of the current time
	TimedEvent();
	// Free the thread if we need to
	~TimedEvent() = default;

	void AddEvent(std::function<void()>, std::string) {}
	void RemoveEvent(std::string) {}

	void SetShouldBlock(bool onOrOff) { isLooping = onOrOff; }

	// Blocks and calls callback functions on set time
	bool Loop() { return true; }

	TimedEvent& operator=(const TimedEvent&) = delete;
	TimedEvent(const TimedEvent&) = delete;
};
