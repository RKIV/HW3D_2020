#pragma once
#include "Window.h"
#include "IvyTimer.h"

class App
{
public:
	App();
	// master frame / message loop
	int Go();
	~App();
private:
	void DoFrame();
private:
	Window wnd;
	IvyTimer timer;
	std::vector<std::unique_ptr<class Box>> boxes;
};