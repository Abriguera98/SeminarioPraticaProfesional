#include <cassert>

#include "StateMachine.h"

StateMachine* StateMachine::mInstance = nullptr;

StateMachine::StateMachine()
{
	mGUIManager = GUIManager::getInstance();
	mDataProcessor = DataProcessor::getInstance();
}

void StateMachine::setWaiting(bool waiting)
{
	mWaiting = waiting;
}

StateMachine* StateMachine::getInstance()
{
	if (mInstance == nullptr)
	{
		mInstance = new StateMachine();
	}
	return mInstance;
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
	switch (mState)
	{
		case eInitializing:
			Step_Initializing();
			break;
		case eShowWelcomeScreen:
			break;
		case eExit:
			break;
	}
}

void StateMachine::getNextStep()
{
	switch (mState)
	{
	case eInitializing:
		break;
	case eShowWelcomeScreen:
		break;
	case eExit:
		break;
	}
}

void StateMachine::Step_Initializing()
{
	mWaiting = true;
}