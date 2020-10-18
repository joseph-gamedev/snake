#include "Timer.h"

Core::Timer::Timer(float repeatTime, const TimerCallback& callback)
	: m_timeElapsed(0)
	, m_repeatTime(repeatTime)
	, m_IsRunning(false)
	, m_repeatCallback(callback)
{

}

void Core::Timer::Reset()
{
	m_timeElapsed = 0;
}

void Core::Timer::Start()
{
	m_IsRunning = true;
}

void Core::Timer::Stop()
{
	m_IsRunning = false;
}

void Core::Timer::Update(float timeDelta)
{
	if (!m_IsRunning)
		return;

	m_timeElapsed += timeDelta;
	if (m_timeElapsed >= m_repeatTime)
	{
		if (m_repeatCallback)
		{
			m_repeatCallback();
		}
		m_timeElapsed = 0;
	}
}

