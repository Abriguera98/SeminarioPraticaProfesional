#include "LoginFailedMessage.h"

namespace UIForms {
	System::Void LoginFailedMessage::btnAccept_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->mManagerInstance->setResult(GUIManager::Result::eClosed);
		this->Close();
	}
}
