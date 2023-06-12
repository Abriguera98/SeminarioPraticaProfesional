#include <functional>

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

bool DataProcessor::logInUser(char* aUser, char* aPass)
{
	std::size_t h1 = std::hash<std::string>{}(aPass);
	bool success = h1 == mDatabaseWrapper->GetUserData(aUser);
	return false;
}
