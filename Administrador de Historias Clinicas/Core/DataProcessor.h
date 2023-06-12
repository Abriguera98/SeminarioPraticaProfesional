#pragma once

#include <string>

#include "DatabaseWrapper.h"

class DataProcessor {
public:
	static DataProcessor* getInstance();
	DataProcessor(DataProcessor& other) = delete;
	void operator=(const DataProcessor&) = delete;

	bool logInUser(char* aUser, char* aPass);
private:
	static DataProcessor* mInstance;
	DatabaseWrapper* mDatabaseWrapper;
	DataProcessor();
};