#pragma once
#include <SQLAPI.h>
#include <map>

#include "../Data Abstractions/PerfilPsicologico.h"

class DatabaseInterface {
public:
	static DatabaseInterface* getInstance();
	DatabaseInterface(DatabaseInterface& other) = delete;
	void operator=(const DatabaseInterface&) = delete;
	~DatabaseInterface();

	void Connect();
	std::map<unsigned int, PerfilPsicologico*>* getPerfiles();
	std::size_t GetUserLogin(std::string);
	Usuario* GetLoggedUser(std::string);
	System::String^ getEntryAuthorFromProfileDate(unsigned int profileID, System::String^ date);
	System::String^ getEntryDescriptionFromProfileDate(unsigned int profileID, System::String^ date);
	void changeProfileState(unsigned int index);
	PerfilPsicologico* addNewEmptyProfile(System::String^ name, System::String^ lastName, System::String^ dni);
	Entrada* addNewEntryToProfile(unsigned int index, System::String^ date, System::String^ description, Usuario* user);
private:
	static DatabaseInterface* mInstance;

	DatabaseInterface();
	SAConnection mConnection;
};