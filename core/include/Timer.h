#pragma once

#include <functional>

using TimerCallback = std::function<void()>;

namespace Core
{
	class Timer
	{
		public:

			Timer(float repeatTime, const TimerCallback& callback);
			void Reset();
			void Start();
			void Stop();
			void Update(float timeDelta);

		private:
			float m_timeElapsed;
			float m_repeatTime;
			bool m_IsRunning;
			TimerCallback m_repeatCallback;
	};

};