#pragma once
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <tchar.h>

#include "GUIManager.h"
#include "DataProcessor.h"

class StateMachine {
	enum State {
		eInitializing,
		eShowWelcomeScreen,
		eWaiting,
		eExit
	};
public:
	static StateMachine* getInstance(HINSTANCE& hInstance, int nCmdShow);
	static StateMachine* getInstance();

	StateMachine(StateMachine& other) = delete;
	void operator=(const StateMachine&) = delete;

	void run();
	void setWaiting(bool waiting);

private:
	static StateMachine* mInstance;
	GUIManager* mGUIManager;
	DataProcessor* mDataProcessor;
	StateMachine(HINSTANCE& hInstance, int nCmdShow);
	HWND* mHWnd;

	State mState;
	const int mCmdShow;
	bool mWaiting;

	void doStep();
	void getNextStep();

	void Step_Initializing();
};

LRESULT CALLBACK OnMessage(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);