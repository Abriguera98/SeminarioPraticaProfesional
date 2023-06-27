#pragma once

#include <Windows.h>
#include <stdlib.h>
#include <string.h>
#include <tchar.h>

#include "DataProcessor.h"

class GUIManager {
public:
	enum Result {
		eNotSet = 0,
		eClosed,
		eProceedToLoginWindow,
		eLoginVerified
	};

	//Singleton Definition
	static GUIManager* getInstance(DataProcessor* dataProcessor);
	GUIManager(GUIManager& other) = delete;
	void operator=(const GUIManager &) = delete;

	//Result Handling
	void resetResult() { mResult = eNotSet; };
	void setResult(Result value) { mResult = value; };
	Result getResult() { return mResult; };
	void addNewEmptyProfile(System::String^ name, System::String^ lastName, System::String^ dni);

	//Windows to show
	void ShowLandingScreen();
	void ShowLoginScreen();
	void ShowLoginFailed();
	void ShowMainScreen();

	bool attemptLogin();
	void fillMainData(System::Windows::Forms::ListView^ list);
	void reloadView(System::Windows::Forms::ListView^ list);
	void reloadRow(System::Windows::Forms::ListView^ list, unsigned int index);
	void fillViewData(System::Windows::Forms::ListView^ list, unsigned int profile);
	System::String^ getEntryDescriptionFromProfileDate(unsigned int profileID, System::String^ date);
	System::String^ getEntryAuthorFromProfileDate(unsigned int profileID, System::String^ date);
	void changeProfileState(unsigned int index);
	void addNewEntryToProfile(unsigned int index, System::String^ date, System::String^ description);
private:
	static GUIManager* mInstance;
	DataProcessor* mDataProcessor;

	Result mResult;
	GUIManager(DataProcessor* dataProcessor);
};