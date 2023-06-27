#pragma once
#include <string>
#include <map>

class Voluntario {
public:
	Voluntario(const std::string& aNombre, const std::string& aApellido, const std::string& aDNI);
	Voluntario(Voluntario& other) = delete;
	void operator=(const Voluntario&) = delete;
	
	std::string getNombre() { return mNombre;  };
	std::string getApellido() {return mApellido;};
	std::string getDNI() {return mDNI;};

private:
	std::string mNombre;
	std::string mApellido;
	std::string mDNI;
};