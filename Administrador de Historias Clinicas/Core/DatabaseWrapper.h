#pragma once
#include <SQLAPI.h>
#include <map>

#include "../Data Abstractions/PerfilPsicologico.h"

class DatabaseWrapper {
public:
	static DatabaseWrapper* getInstance();

	DatabaseWrapper(DatabaseWrapper& other) = delete;
	void operator=(const DatabaseWrapper&) = delete;

	void Connect();
	std::map<unsigned int, PerfilPsicologico*>* getPerfiles();
	std::size_t GetUserLogin(const char* aUser);
	System::String^ getEntryDescriptionFromProfileDate(unsigned int profileID, System::String^ date);
	void changeProfileState(unsigned int index);
private:
	static DatabaseWrapper* mInstance;

	DatabaseWrapper();
	SAConnection mConnection;
};