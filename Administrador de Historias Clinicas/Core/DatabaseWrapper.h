#pragma once
#include <SQLAPI.h>

class DatabaseWrapper {
public:
	static DatabaseWrapper* getInstance();

	DatabaseWrapper(DatabaseWrapper& other) = delete;
	void operator=(const DatabaseWrapper&) = delete;

	void Connect();
private:
	static DatabaseWrapper* mInstance;
	DatabaseWrapper();
	SAConnection mConnection;

	void GetUser();
};