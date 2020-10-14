#pragma once

#include "ApplicationBase.h"
#include "ILifeCycle.h"

namespace Core
{
	struct AppData
	{
		const char* title;
		int16_t width;
		int16_t height;
		Color color;
	};

	class Application : public ApplicationBase, ILifeCycle
	{
		public:
			Application(const AppData& data);
			virtual ~Application();
			void Run();

		protected:
			AppData m_appData;

		private:
			uint32_t m_lastTick;
	};
};
extern std::unique_ptr<Core::Application> CreateApplication();
