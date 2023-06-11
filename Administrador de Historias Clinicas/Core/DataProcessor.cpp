#include "DataProcessor.h"

DataProcessor* DataProcessor::mInstance = nullptr;

DataProcessor* DataProcessor::getInstance()
{
	if (mInstance == nullptr)
	{
		mInstance = new DataProcessor();
	}
	return mInstance;
}

DataProcessor::DataProcessor()
{
	mDatabaseWrapper = DatabaseWrapper::getInstance();
	mDatabaseWrapper->Connect();
}
