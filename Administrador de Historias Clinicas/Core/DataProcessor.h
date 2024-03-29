#pragma once

#include <string>
#include <vector>

#include "../Data Abstractions/PerfilPsicologico.h"
#include "DatabaseWrapper.h"

class DataProcessor {
public:

	//Singleton Definition
	static DataProcessor* getInstance();
	static Usuario* mLoggedUser;
	DataProcessor(DataProcessor& other) = delete;
	void operator=(const DataProcessor&) = delete;
	~DataProcessor();

	bool attemptLogin();
	void fillPerfiles();
	void fillMainData(System::Windows::Forms::ListView^ list);
	void reloadView(System::Windows::Forms::ListView^ list);
	void reloadRow(System::Windows::Forms::ListView^ list, unsigned int index);
	void fillViewData(System::Windows::Forms::ListView^ list, unsigned int profile);
	System::String^ getEntryAuthorFromProfileDate(unsigned int profileID, System::String^ date);
	System::String^ getEntryDescriptionFromProfileDate(unsigned int profileID, System::String^ date);
	void changeProfileState(unsigned int index);
	void addNewEmptyProfile(System::String^ name, System::String^ lastName, System::String^ dni);
	void addNewEntryToProfile(unsigned int index, System::String^ date, System::String^ description);
private:
	std::map<unsigned int, PerfilPsicologico*>* mPerfiles;
	static DataProcessor* mInstance;
	DatabaseInterface* mDatabaseWrapper;
	DataProcessor();
};