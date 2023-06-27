#include "NewEntryForm.h"

namespace UIForms
{
    System::Void NewEntryForm::btnAccept_Click(System::Object^ sender, System::EventArgs^ e)
    {
        auto date = this->dtpDate->Text;
        auto description = this->tbDescription->Text;
        mManagerInstance->addNewEntryToProfile(mProfileID, date, description);
        this->Close();
    }
}
