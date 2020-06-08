#pragma once
#include "Window.h"
#include "IvyTimer.h"
#include "ImguiManager.h"


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
	ImguiManager imgui;
	Window wnd;
	IvyTimer timer;
	std::vector<std::unique_ptr<class Drawable>> drawables;
	bool show_demo_window = true;
	static constexpr size_t nDrawables = 180;
};