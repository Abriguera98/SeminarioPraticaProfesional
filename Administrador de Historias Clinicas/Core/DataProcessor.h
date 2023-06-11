#pragma once

#include "DatabaseWrapper.h"

class DataProcessor {
public:
	static DataProcessor* getInstance();

	DataProcessor(DataProcessor& other) = delete;
	void operator=(const DataProcessor&) = delete;
private:
	static DataProcessor* mInstance;
	DatabaseWrapper* mDatabaseWrapper;
	DataProcessor();
};