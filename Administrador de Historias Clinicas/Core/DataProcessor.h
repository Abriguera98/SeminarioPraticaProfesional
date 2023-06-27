#pragma once

#include <string>
#include <vector>

#include "../Data Abstractions/PerfilPsicologico.h"
#include "DatabaseWrapper.h"

class DataProcessor {
public:
	enum Result {
		eNotSet = 0
	};

	//Singleton Definition
	static DataProcessor* getInstance();
	DataProcessor(DataProcessor& other) = delete;
	void operator=(const DataProcessor&) = delete;

	//Result Handling
	void resetResult() { mResult = eNotSet; };
	void setResult(Result value) { mResult = value; };
	Result getResult() { return mResult; };

	bool attemptLogin();
	void fillPerfiles();
	void fillMainData(System::Windows::Forms::ListView^ list);
	void fillViewData(System::Windows::Forms::ListView^ list, unsigned int profile);
	System::String^ getEntryDescriptionFromProfileData(unsigned int profileID, System::String^ date);
	void changeProfileState(unsigned int index);
private:
	std::map<unsigned int, PerfilPsicologico*>* mPerfiles;
	static DataProcessor* mInstance;
	DatabaseWrapper* mDatabaseWrapper;
	Result mResult;
	DataProcessor();
};