#pragma once
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <map>
#include <tchar.h>

#include "GUIManager.h"
#include "DataProcessor.h"

class StateMachine {
	enum State {
		eInitializing,
		eLogin,
		eExit,
		eMainScreen
	};
public:
	static StateMachine* getInstance();
	~StateMachine();

	static bool addData(std::string key, std::string value);
	static bool getData(std::string key, std::string& ret);

	StateMachine(StateMachine& other) = delete;
	void operator=(const StateMachine&) = delete;

	void run();

private:
	static StateMachine* mInstance;
	static std::map<std::string, std::string>* mDataMap;

	GUIManager* mGUIManager;
	StateMachine();

	State mState;

	void doStep();
	void getNextStep();

	void Step_Initializing();
	void Step_Login();
	void Step_MainScreen();
};