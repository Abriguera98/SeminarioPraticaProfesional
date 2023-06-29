#include <functional>

#include "Constants.h"
#include "DataProcessor.h"
#include "StateMachine.h"

DataProcessor* DataProcessor::mInstance = nullptr;
Usuario* DataProcessor::mLoggedUser = nullptr;

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
	mDatabaseWrapper = DatabaseInterface::getInstance();
	mDatabaseWrapper->Connect();
}

DataProcessor::~DataProcessor()
{
	delete mPerfiles;
	delete mDatabaseWrapper;
}

bool DataProcessor::attemptLogin()
{
	std::string aUser;
	std::string aPass;
	StateMachine::getData(Constants::strUserKey, aUser);
	StateMachine::getData(Constants::strPassKey, aPass);

	std::size_t h1 = std::hash<std::string>{}(aPass);
	if (h1 == mDatabaseWrapper->GetUserLogin(aUser.c_str()))
	{
		mLoggedUser = mDatabaseWrapper->GetLoggedUser(aUser);
		return true;
	}
	return false;
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

void DataProcessor::reloadView(System::Windows::Forms::ListView^ list)
{
	for (int i = list->Items->Count+1; i <= mPerfiles->size(); ++i)
	{
		System::Windows::Forms::ListViewItem^ item = gcnew System::Windows::Forms::ListViewItem(gcnew System::String((*mPerfiles)[i]->getVoluntario()->getDNI().c_str()));
		item->SubItems->Add(gcnew System::String((*mPerfiles)[i]->getVoluntario()->getNombre().c_str()));
		item->SubItems->Add(gcnew System::String((*mPerfiles)[i]->getVoluntario()->getApellido().c_str()));
		item->SubItems->Add(gcnew System::String((*mPerfiles)[i]->getUltimaModificacion().c_str()));
		item->SubItems->Add(gcnew System::String((*mPerfiles)[i]->getActivo() ? "Abierto" : "Cerrado"));
		list->Items->Add(item);
	}
}

void DataProcessor::reloadRow(System::Windows::Forms::ListView^ list, unsigned int index)
{
	std::string newDate = (*mPerfiles)[index]->getUltimaModificacion().c_str();
	list->Items[index-1]->SubItems[3]->Text = gcnew System::String(newDate.c_str());
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

System::String^ DataProcessor::getEntryAuthorFromProfileDate(unsigned int profileID, System::String^ date)
{
	return mDatabaseWrapper->getEntryAuthorFromProfileDate(profileID, date);
}

System::String^ DataProcessor::getEntryDescriptionFromProfileDate(unsigned int profileID, System::String^ date)
{
	return mDatabaseWrapper->getEntryDescriptionFromProfileDate(profileID, date);
}

void DataProcessor::changeProfileState(unsigned int index)
{
	(*mPerfiles)[index]->setActivo(!(*mPerfiles)[index]->getActivo());
	mDatabaseWrapper->changeProfileState(index);
}

void DataProcessor::addNewEmptyProfile(System::String^ name, System::String^ lastName, System::String^ dni)
{
	PerfilPsicologico* newPro = mDatabaseWrapper->addNewEmptyProfile(name, lastName, dni);
	(*mPerfiles)[mPerfiles->size() + 1] = newPro;
}

void DataProcessor::addNewEntryToProfile(unsigned int index, System::String^ date, System::String^ description)
{
	Entrada* ent = mDatabaseWrapper->addNewEntryToProfile(index, date, description, mLoggedUser);
	(*mPerfiles)[index]->getEntradas()->push_back(ent);
	(*mPerfiles)[index]->ActualizarUltimaModificacion();
}
