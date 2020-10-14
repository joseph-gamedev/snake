#include <iostream>
#include "Application.h"

int main()
{
	std::unique_ptr<Core::Application> application = CreateApplication();
	if (application)
	{
		application->Run();
	}
	std::cout << "hello world" << std::endl;
}