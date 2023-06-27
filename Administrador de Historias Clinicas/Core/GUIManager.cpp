#include <cassert>
#include <cliext\map>

#include "GUIManager.h"
#include "StateMachine.h"
#include "Constants.h"

#include "../UI/LandingForm.h"
#include "../UI/LoginForm.h"
#include "../UI/LoginFailedMessage.h"
#include "../UI/MainForm.h"

using namespace System;

using namespace System::Windows::Forms;

GUIManager* GUIManager::mInstance = nullptr;

GUIManager* GUIManager::getInstance(DataProcessor* dataProcessor)
{
	if (mInstance == nullptr) {
		mInstance = new GUIManager(dataProcessor);
	}
	return mInstance;
}

GUIManager::GUIManager(DataProcessor* dataProcessor)
{
	mDataProcessor = dataProcessor;
}

void GUIManager::ShowLandingScreen()
{
	UIForms::LandingForm var(this);
	Application::Run(% var);
}

void GUIManager::ShowLoginScreen()
{
	UIForms::LoginForm var(this);
	Application::Run(% var);
}

void GUIManager::ShowLoginFailed()
{
	UIForms::LoginFailedMessage var(this);
	Application::Run(% var);
};

void GUIManager::ShowMainScreen()
{
	UIForms::MainForm var(this);
	Application::Run(% var);
}

bool GUIManager::attemptLogin()
{
	return mDataProcessor->attemptLogin();
}

void GUIManager::fillMainData(System::Windows::Forms::ListView^ list)
{
	mDataProcessor->fillMainData(list);
}

void GUIManager::fillViewData(System::Windows::Forms::ListView^ list, unsigned int profile)
{
	mDataProcessor->fillViewData(list, profile);
}

System::String^ GUIManager::getEntryDescriptionFromProfileDate(unsigned int profileID, System::String^ date)
{
	return mDataProcessor->getEntryDescriptionFromProfileData(profileID, date);
}

void GUIManager::changeProfileState(unsigned int index)
{
	mDataProcessor->changeProfileState(index);
}
