#include "App.h"
#include <sstream>
#include <iomanip>

App::App()
	:
	wnd(800, 600, "Ivy Window")
{}

int App::Go()
{
	while (true)
	{
		// process all messages pending, but do not block for new messages
		if (const auto ecode = Window::ProcessMessages())
		{
			// if return optional has value, meas we're quitting so return exit code
			return *ecode;
		}
		DoFrame();
	}
}

void App::DoFrame()
{
	//const float c = sin(timer.Peek()) / 2.0f + 0.5f;
	wnd.Gfx().ClearBuffer(1.0f, 1.0f, 1.0f);
	wnd.Gfx().DrawTestTriangle(timer.Peek(), 
		wnd.mouse.GetPosX() / 400.0f - 1.0f, 
		-wnd.mouse.GetPosY() / 300.0f + 1.0f);
	wnd.Gfx().EndFrame();
}