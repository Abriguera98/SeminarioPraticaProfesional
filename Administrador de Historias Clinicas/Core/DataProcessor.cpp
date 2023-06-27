#include <functional>

#include "Constants.h"
#include "DataProcessor.h"
#include "StateMachine.h"

DataProcessor* DataProcessor::mInstance = nullptr;

DataProcessor* DataProcessor::getInstance()
{
	if (mInstance == nullptr)
	{
		mInstance = new DataProcessor();
	}
	return mInstance;
}

DataProcessor::DataProcessor()
	: mPerfiles(new std::map<unsigned int, PerfilPsicologico*>())
{
	mDatabaseWrapper = DatabaseWrapper::getInstance();
	mDatabaseWrapper->Connect();
}

bool DataProcessor::attemptLogin()
{
	std::string aUser;
	std::string aPass;
	StateMachine::getData(Constants::strUserKey, aUser);
	StateMachine::getData(Constants::strPassKey, aPass);

	std::size_t h1 = std::hash<std::string>{}(aPass);
	return (h1 == mDatabaseWrapper->GetUserLogin(aUser.c_str()));
}

void DataProcessor::fillPerfiles()
{
	mPerfiles = mDatabaseWrapper->getPerfiles();
}

void DataProcessor::fillMainData(System::Windows::Forms::ListView^ list)
{
	for(int i = 1; i <= mPerfiles->size(); ++i)
	{
		System::Windows::Forms::ListViewItem^ item = gcnew System::Windows::Forms::ListViewItem(gcnew System::String((*mPerfiles)[i]->getVoluntario()->getDNI().c_str()));
		item->SubItems->Add(gcnew System::String((*mPerfiles)[i]->getVoluntario()->getNombre().c_str()));
		item->SubItems->Add(gcnew System::String((*mPerfiles)[i]->getVoluntario()->getApellido().c_str()));
		item->SubItems->Add(gcnew System::String((*mPerfiles)[i]->getUltimaModificacion().c_str()));
		item->SubItems->Add(gcnew System::String((*mPerfiles)[i]->getActivo() ? "Abierto" : "Cerrado"));
		list->Items->Add(item);
	}
}

void DataProcessor::fillViewData(System::Windows::Forms::ListView^ list, unsigned int profile)
{
	for (int i = 0; i < (*mPerfiles)[profile]->getEntradas()->size(); ++i)
	{
		std::string date = (*mPerfiles)[profile]->getEntradas()->at(i)->getDate();
		System::Windows::Forms::ListViewItem^ item = gcnew System::Windows::Forms::ListViewItem(gcnew System::String(date.c_str()));
		list->Items->Add(item);
	}
}

System::String^ DataProcessor::getEntryDescriptionFromProfileData(unsigned int profileID, System::String^ date)
{
	return mDatabaseWrapper->getEntryDescriptionFromProfileDate(profileID, date);
}

void DataProcessor::changeProfileState(unsigned int index)
{
	(*mPerfiles)[index]->setActivo(!(*mPerfiles)[index]->getActivo());
	mDatabaseWrapper->changeProfileState(index);
}