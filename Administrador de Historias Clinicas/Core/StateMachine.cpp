#include <cassert>

#include "StateMachine.h"

StateMachine* StateMachine::mInstance = nullptr;

std::map<std::string, std::string>* StateMachine::mDataMap = new std::map<std::string, std::string>();

StateMachine::StateMachine()
	: mState(eInitializing)
{
	mGUIManager = GUIManager::getInstance(DataProcessor::getInstance());
}

StateMachine* StateMachine::getInstance()
{
	if (mInstance == nullptr)
	{
		mInstance = new StateMachine();
	}
	return mInstance;
}

StateMachine::~StateMachine()
{
	delete mGUIManager;
}

bool StateMachine::addData(std::string key, std::string value)
{
	(*mDataMap)[key] =  value;
	return true;
}

bool StateMachine::getData(std::string key, std::string& ret)
{
	ret = (*mDataMap)[key];
	return true;
}

void StateMachine::run()
{
	while (mState != State::eExit)
	{
		doStep();
		getNextStep();
	}
}

void StateMachine::doStep()
{
	mGUIManager->resetResult();
	switch (mState)
	{
		case eInitializing:
			Step_Initializing();
			break;
		case eLogin:
			Step_Login();
			break;
		case eMainScreen:
			Step_MainScreen();
			break;
		case eExit:
			break;
	}
}

void StateMachine::getNextStep()
{
	GUIManager::Result guiResult = mGUIManager->getResult();

	switch (mState)
	{
	case eInitializing:
		switch (guiResult) {
		case GUIManager::Result::eClosed:
			mState = eExit;
			break;
		case GUIManager::Result::eProceedToLoginWindow:
			mState = eLogin;
			break;
		}
		break;

	case eLogin:
		switch (guiResult) {
		case GUIManager::Result::eClosed:
			mState = eExit;
			break;
		case GUIManager::Result::eLoginVerified:
			mState = eMainScreen;
			break;
		}
		break;

	case eMainScreen:
		switch (guiResult) {
		case GUIManager::Result::eClosed:
			mState = eExit;
			break;
		}
		break;

	case eExit:
		break;
	}
	mGUIManager->resetResult();
}

void StateMachine::Step_Initializing()
{
	mGUIManager->ShowLandingScreen();
}

void StateMachine::Step_Login()
{
	mGUIManager->ShowLoginScreen();
}

void StateMachine::Step_MainScreen()
{
	mGUIManager->ShowMainScreen();
}