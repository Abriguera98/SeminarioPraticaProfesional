#include <string>
#include <sstream>
#include <msclr/marshal_cppstd.h>

#include "Constants.h"
#include "DatabaseWrapper.h"

#include "../Data Abstractions/Entrada.h"
#include "../Data Abstractions/PerfilPsicologico.h"
#include "../Data Abstractions/Usuario.h"
#include "../Data Abstractions/Voluntario.h"

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
        mConnection.Connect(_TSA("..\\Database\\Soles_DB"), _TSA(""), _TSA(""), SA_SQLite_Client);
    } 
    catch (SAException& x)
    {
        std::string test(x.ErrText());
    }
}

std::map<unsigned int, PerfilPsicologico*>* DatabaseWrapper::getPerfiles()
{
    std::map<unsigned int, PerfilPsicologico*>* result = new std::map<unsigned int, PerfilPsicologico*>();

    SACommand cmdProfiles(&mConnection, _TSA(Constants::sqlGetProfiles));
    SACommand cmdEntrysForProfile(&mConnection, _TSA(Constants::sqlGetEntrysForProfile));
    SACommand cmdGetVolunteer(&mConnection, _TSA(Constants::sqlGetVolunteer));
    SACommand cmdGetUserAlias(&mConnection, _TSA(Constants::sqlGetUserAlias));

    cmdProfiles.Execute();
    while (cmdProfiles.FetchNext())
    {
        cmdGetVolunteer.Param(1).setAsString() = cmdProfiles.Field(2).asString();
        cmdGetVolunteer.Execute();
        cmdGetVolunteer.FetchNext();
        Voluntario* voluntario = new Voluntario(std::string(cmdGetVolunteer.Field(2).asString()), std::string(cmdGetVolunteer.Field(3).asString()), std::string(cmdGetVolunteer.Field(1).asString()));

        int ID = cmdProfiles.Field(1).asInt64();
        cmdEntrysForProfile.Param(1).setAsInt64() = ID;

        std::vector<Entrada*>* entradas = new std::vector<Entrada*>();
        cmdEntrysForProfile.Execute();
        while (cmdEntrysForProfile.FetchNext())
        {
            cmdGetUserAlias.Param(1).setAsInt64() = cmdEntrysForProfile.Field(4).asInt64();
            cmdGetUserAlias.Execute();
            cmdGetUserAlias.FetchNext();

            std::string date = cmdEntrysForProfile.Field(2).asString();
            std::string description = cmdEntrysForProfile.Field(3).asString();
            entradas->push_back(new Entrada(date, description, Usuario::getUsuario(std::string(cmdGetUserAlias.Field(1).asString()), cmdEntrysForProfile.Field(4).asInt64())));
        }

        bool estado = cmdProfiles.Field(3).asBool();

        (*result)[ID] = (new PerfilPsicologico(voluntario, entradas, estado));
    }
    return result;
}

DatabaseWrapper::DatabaseWrapper()
{
}

std::size_t DatabaseWrapper::GetUserLogin(const char* aUser)
{
    size_t result;
    SACommand cmd(&mConnection, _TSA(Constants::sqlGetUserLoginData));
    cmd.Param(1).setAsString() = aUser;
    cmd.Execute();
    cmd.FetchNext();

    std::stringstream sstream(std::string(cmd.Field(1).asString()));
    sstream >> result;
    return result;
}

System::String^ DatabaseWrapper::getEntryDescriptionFromProfileDate(unsigned int profileID, System::String^ date)
{
    SACommand cmdEntryDescription(&mConnection, _TSA(Constants::sqlGetEntryDescriptionFromProfileDate));

    std::string dateString = msclr::interop::marshal_as<std::string>(date).c_str();

    cmdEntryDescription.Param(1).setAsInt64() = profileID;
    cmdEntryDescription.Param(2).setAsString() = dateString.c_str();

    cmdEntryDescription.Execute();
    cmdEntryDescription.FetchNext();

    return gcnew System::String(cmdEntryDescription.Field(1).asString().GetMultiByteChars());
}

void DatabaseWrapper::changeProfileState(unsigned int index)
{
    SACommand cmdChangeProfileState(&mConnection, _TSA(Constants::sqlChangeProfileState));
    cmdChangeProfileState.Param(1).setAsInt64() = index;
    cmdChangeProfileState.Execute();
}