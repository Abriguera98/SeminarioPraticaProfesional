#pragma once
#include <map>
#include <string>

class Usuario {
public:
	static Usuario* getUsuario(const std::string& aAlias, unsigned int aID);
	Usuario(Usuario& other) = delete;
	void operator=(const Usuario&) = delete;

private:
	static std::map<unsigned int, Usuario*> sInstances;
	Usuario(const std::string& aAlias, unsigned int aID);
	std::string mAlias;
	unsigned int mID;
};