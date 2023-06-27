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

Usuario* DatabaseWrapper::GetLoggedUser(std::string user)
{
    SACommand cmd(&mConnection, _TSA(Constants::sqlGetUserAlias));
    cmd.Param(1).setAsString() = user.c_str();
    cmd.Execute();
    cmd.FetchNext();

    std::string alias(cmd.Field(1).asString());
    unsigned int id(cmd.Field(2).asInt64());

    return Usuario::getUsuario(alias, id);
}

std::size_t DatabaseWrapper::GetUserLogin(std::string aUser)
{
    size_t result;
    SACommand cmd(&mConnection, _TSA(Constants::sqlGetUserLoginData));
    cmd.Param(1).setAsString() = aUser.c_str();
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

System::String^ DatabaseWrapper::getEntryAuthorFromProfileDate(unsigned int profileID, System::String^ date)
{
    SACommand cmdEntryDescription(&mConnection, _TSA(Constants::sqlGetEntryAuthorFromProfileDate));

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

PerfilPsicologico* DatabaseWrapper::addNewEmptyProfile(System::String^ name, System::String^ lastName, System::String^ dni)
{
    std::string nameString = msclr::interop::marshal_as<std::string>(name).c_str();
    std::string lastNameString = msclr::interop::marshal_as<std::string>(lastName).c_str();
    std::string dniString = msclr::interop::marshal_as<std::string>(dni).c_str();

    SACommand cmdChangeProfileState(&mConnection, _TSA(Constants::sqlCreateNewEmptyProfile));
    cmdChangeProfileState.Param(1).setAsString() = nameString.c_str();
    cmdChangeProfileState.Param(2).setAsString() = lastNameString.c_str();
    cmdChangeProfileState.Param(3).setAsString() = dniString.c_str();
    cmdChangeProfileState.Execute();

    Voluntario* vol = new Voluntario(nameString, lastNameString, dniString);
    std::vector<Entrada*>* ent = new std::vector<Entrada*>();
    PerfilPsicologico* prof = new PerfilPsicologico(vol, ent, true);

    return prof;
}

Entrada* DatabaseWrapper::addNewEntryToProfile(unsigned int index, System::String^ date, System::String^ description, Usuario* user)
{
    std::string dateString = msclr::interop::marshal_as<std::string>(date).c_str();
    std::string descripcionString = msclr::interop::marshal_as<std::string>(description).c_str();

    SACommand cmdInsertEntry(&mConnection, _TSA(Constants::sqlInsertEntry));

    cmdInsertEntry.Param(1).setAsString() = dateString.c_str();
    cmdInsertEntry.Param(2).setAsString() = descripcionString.c_str();
    cmdInsertEntry.Param(3).setAsInt64() = user->getUsuarioID();
    cmdInsertEntry.Param(4).setAsInt64() = index;

    cmdInsertEntry.Execute();

    Entrada* ent = new Entrada(dateString, descripcionString, user);
    return ent;
}
