#include "LandingForm.h"

namespace UIForms
{
    System::Void LandingForm::btnExit_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->Close();
	}

	System::Void LandingForm::UserClosing(System::Object^ sender, System::EventArgs^ e)
	{
		if (!keepProcessing)
		{
			this->mManagerInstance->setResult(GUIManager::Result::eClosed);
		}
	}

	System::Void LandingForm::btnLogin_Click(System::Object^ sender, System::EventArgs^ e)
	{
		keepProcessing = true;
		this->mManagerInstance->setResult(GUIManager::Result::eProceedToLoginWindow);
		this->Close();
	}

}