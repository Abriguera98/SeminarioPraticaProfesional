#pragma once
#include <string>

#include "Usuario.h"

class Entrada {
public:
	Entrada(const std::string& aDate, const std::string& aDescription, Usuario* aUsuario);

	std::string getDate() { return mDate;  };
	std::string getDescription() { return mDescription;  };
	Usuario* getUsuario() { return mUsuario;  };

private:
	std::string mDate;
	std::string mDescription;
	Usuario* mUsuario;
};