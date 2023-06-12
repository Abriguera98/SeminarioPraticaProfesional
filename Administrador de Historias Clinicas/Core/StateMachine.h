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
		eExit
	};
public:
	static StateMachine* getInstance();

	StateMachine(StateMachine& other) = delete;
	void operator=(const StateMachine&) = delete;

	void run();
	void setWaiting(bool waiting);

private:
	static StateMachine* mInstance;
	GUIManager* mGUIManager;
	DataProcessor* mDataProcessor;
	StateMachine();

	State mState;
	bool mWaiting;

	void doStep();
	void getNextStep();

	void Step_Initializing();
};