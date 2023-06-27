#include "MainForm.h"

namespace UIForms {

	System::Void MainForm::MainForm_Load(System::Object^ sender, System::EventArgs^ e)
	{
		mManagerInstance->fillMainData(lsvData);
	}

	System::Void MainForm::lsvData_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
	{
		this->btnClose->Enabled = (this->lsvData->SelectedItems->Count > 0);
		this->btnAdd->Enabled = (this->lsvData->SelectedItems->Count > 0 && this->lsvData->SelectedItems[0]->SubItems[4]->Text == "Abierto");
		this->btnView->Enabled = (this->lsvData->SelectedItems->Count > 0);
		if (this->lsvData->SelectedItems->Count > 0)
		{
			this->btnClose->Text = this->lsvData->SelectedItems[0]->SubItems[4]->Text == "Cerrado" ? "Re-Abrir Perfil" : "Cerrar Perfil";
		}
	}

	System::Void MainForm::btnView_Click(System::Object^ sender, System::EventArgs^ e) {
		auto index = this->lsvData->SelectedIndices[0] + 1;

		UIForms::VisualizationForm form(mManagerInstance, index);
		System::String^ volunteerName = lsvData->Items[index]->SubItems[1]->Text +", " + this->lsvData->Items[index]->SubItems[2]->Text;
		form.setVolunteerData(volunteerName, lsvData->Items[index]->SubItems[0]->Text);
		form.ShowDialog();
	}

	System::Void MainForm::btnClose_Click(System::Object^ sender, System::EventArgs^ e) {
		auto index = this->lsvData->SelectedIndices[0] + 1;
		this->lsvData->SelectedItems[0]->SubItems[4]->Text = this->lsvData->SelectedItems[0]->SubItems[4]->Text == "Cerrado" ? "Abierto" : "Cerrado";
		this->mManagerInstance->changeProfileState(index);
		this->btnClose->Text = this->lsvData->SelectedItems[0]->SubItems[4]->Text == "Cerrado" ? "Re-Abrir Perfil" : "Cerrar Perfil";
	}

	System::Void MainForm::btnSearch_Click(System::Object^ sender, System::EventArgs^ e) {
		//Implement Search
	}
}