#include "Usuario.h"

std::map<unsigned int, Usuario*> Usuario::sInstances = std::map<unsigned int, Usuario*>();

Usuario* Usuario::getUsuario(const std::string& aAlias, unsigned int aID)
{
	if (sInstances.find(aID) == sInstances.end())
	{
		sInstances[aID] = new Usuario(aAlias, aID);
	}
	return sInstances[aID];
}

Usuario::Usuario(const std::string& aAlias, unsigned int aID)
	:mAlias(aAlias), mID(aID)
{
}
