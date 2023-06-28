#include <cassert>
#include <cliext\map>

#include "GUIManager.h"
#include "StateMachine.h"
#include "Constants.h"

#include "../UI/LandingForm.h"
#include "../UI/LoginForm.h"
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

void GUIManager::addNewEmptyProfile(System::String^ name, System::String^ lastName, System::String^ dni)
{
	mDataProcessor->addNewEmptyProfile(name, lastName, dni);
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

void GUIManager::ShowMainScreen()
{
	mDataProcessor->fillPerfiles();
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

void GUIManager::reloadView(System::Windows::Forms::ListView^ list)
{
	mDataProcessor->reloadView(list);
}

void GUIManager::reloadRow(System::Windows::Forms::ListView^ list, unsigned int index)
{
	mDataProcessor->reloadRow(list, index);
}

void GUIManager::fillViewData(System::Windows::Forms::ListView^ list, unsigned int profile)
{
	mDataProcessor->fillViewData(list, profile);
}

System::String^ GUIManager::getEntryDescriptionFromProfileDate(unsigned int profileID, System::String^ date)
{
	return mDataProcessor->getEntryDescriptionFromProfileDate(profileID, date);
}

System::String^ GUIManager::getEntryAuthorFromProfileDate(unsigned int profileID, System::String^ date)
{
	return mDataProcessor->getEntryAuthorFromProfileDate(profileID, date);
}

void GUIManager::changeProfileState(unsigned int index)
{
	mDataProcessor->changeProfileState(index);
}

void GUIManager::addNewEntryToProfile(unsigned int index, System::String^ date, System::String^ description)
{
	mDataProcessor->addNewEntryToProfile(index, date, description);
}
