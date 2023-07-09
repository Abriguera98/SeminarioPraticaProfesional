#include "NewProfileForm.h"

namespace UIForms {
	System::Void NewProfileForm::btnAccept_Click(System::Object^ sender, System::EventArgs^ e)
	{
		System::String^ errors = "";
		if (tbName->Text->Length < 1)
		{
			errors += "Nombre no valido\n";
		}
		if (tbLastName->Text->Length < 1)
		{
			errors += "Apellido no valido\n";
		}
		if (!System::Text::RegularExpressions::Regex::IsMatch(tbDNI->Text, "^[0-9]+$") || tbDNI->Text->Length < 7)
		{
			errors += "El voluntario ya posee un perfil\n";
		}

		if (errors != "")
		{
			MessageBox::Show(errors, "Error de Datos", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		else
		{
			System::String^ name = tbName->Text;
			System::String^ lastName = tbLastName->Text;
			System::String^ dni = tbDNI->Text;
			mManagerInstance->addNewEmptyProfile(name, lastName, dni);
			this->Close();
		}
	}
}
