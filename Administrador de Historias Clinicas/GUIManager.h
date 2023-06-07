#pragma once
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <tchar.h>

class GUIManager {
public:
	static GUIManager* getInstance(HINSTANCE& hInstance);
	GUIManager(GUIManager& other) = delete;
	void operator=(const GUIManager &) = delete;

	HWND* setIdle();
private:
	static GUIManager* mInstance;
	HINSTANCE * mHInstance;
	GUIManager(HINSTANCE& hInstance);
};