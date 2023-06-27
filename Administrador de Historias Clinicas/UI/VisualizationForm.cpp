#include "VisualizationForm.h"

namespace UIForms {
	System::Void VisualizationForm::listView1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
	{
		System::String^ description = "";
		System::String^ author = "";
		if (lsvEnrtys->SelectedItems->Count > 0)
		{
			description = mManagerInstance->getEntryDescriptionFromProfileDate(mProfileID, lsvEnrtys->SelectedItems[0]->Text);
			author = mManagerInstance->getEntryAuthorFromProfileDate(mProfileID, lsvEnrtys->SelectedItems[0]->Text);
		}
		this->tbDescription->Text = description;
		this->tbAuthor->Text = author;
	}

	System::Void VisualizationForm::VisualizationForm_Load(System::Object^ sender, System::EventArgs^ e)
	{
		mManagerInstance->fillViewData(lsvEnrtys, mProfileID);
	}

	System::Void VisualizationForm::btBack_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->Close();
	}
}
