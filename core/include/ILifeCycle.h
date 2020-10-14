#pragma once

namespace Core
{
	class ILifeCycle
	{
	public:
		virtual ~ILifeCycle() {}

		virtual void Load() = 0;

		virtual void OnLoadComplete() = 0;

		virtual void Start() = 0;

		virtual void Stop() = 0;

		virtual void PostUpdate(float deltaTime) = 0;

		virtual void Update(float timeDelta) = 0;

		virtual void Draw() = 0;
	};
};