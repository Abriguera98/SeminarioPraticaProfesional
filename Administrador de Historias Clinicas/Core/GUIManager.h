#pragma once
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <tchar.h>

class GUIManager {
public:
	static GUIManager* getInstance();
	GUIManager(GUIManager& other) = delete;
	void operator=(const GUIManager &) = delete;
private:
	static GUIManager* mInstance;
	GUIManager();
};