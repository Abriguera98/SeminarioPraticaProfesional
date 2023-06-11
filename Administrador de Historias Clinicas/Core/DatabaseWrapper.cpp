#include <string>

#include "DatabaseWrapper.h"

DatabaseWrapper* DatabaseWrapper::mInstance = nullptr;

DatabaseWrapper* DatabaseWrapper::getInstance()
{
	if (mInstance == nullptr)
	{
		mInstance = new DatabaseWrapper();
	}
	return mInstance;
}

void DatabaseWrapper::Connect()
{
    try
    {
        mConnection.Connect(_TSA("Soles_DB"), _TSA("sa"), _TSA("sa"), SA_SQLServer_Client);
    } 
    catch (SAException& x)
    {
        std::string test(x.ErrText());
    }
}

DatabaseWrapper::DatabaseWrapper()
{
}

void DatabaseWrapper::GetUser()
{

}