#include "LoginForm.h"

namespace UIForms {

	System::Void LoginForm::btnCancel_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}

	void LoginForm::FormClosingHandler(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e)
	{
		if (mManagerInstance->getResult() == GUIManager::Result::eNotSet)
		{
			mManagerInstance->setResult(GUIManager::Result::eClosed);
		}
	}

	System::Void LoginForm::btnAccept_Click(System::Object^ sender, System::EventArgs^ e)
	{
		msclr::interop::marshal_context context;
		assert(StateMachine::addData(Constants::strUserKey, context.marshal_as<std::string>(this->tbUser->Text)));
		assert(StateMachine::addData(Constants::strPassKey, context.marshal_as<std::string>(this->tbPassword->Text)));
		if (mManagerInstance->attemptLogin())
		{
			mManagerInstance->setResult(GUIManager::Result::eLoginVerified);
			this->Close();
		}
		else
		{
			MessageBox::Show(this, "El nombre de usuario o contraseña son incorrectos", "Atencion", MessageBoxButtons::OK, MessageBoxIcon::Warning, MessageBoxDefaultButton::Button1);
		}
	}
}
