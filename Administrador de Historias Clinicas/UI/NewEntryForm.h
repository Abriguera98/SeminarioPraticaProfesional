#pragma once
#include "../Core/GUIManager.h"

namespace UIForms {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for NewEntryForm
	/// </summary>
	public ref class NewEntryForm : public System::Windows::Forms::Form
	{
	public:
		NewEntryForm(GUIManager* parent, unsigned int profileID)
			: mManagerInstance(parent), mProfileID(profileID)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~NewEntryForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: GUIManager* mManagerInstance;
	private: unsigned int mProfileID;
	private: System::Windows::Forms::Label^ lbSteps;
	private: System::Windows::Forms::Label^ lbDate;
	private: System::Windows::Forms::Label^ lbDescription;
	private: System::Windows::Forms::TextBox^ tbDescription;

	private: System::Windows::Forms::DateTimePicker^ dtpDate;

	private: System::Windows::Forms::Button^ btnAccept;
	private: System::Windows::Forms::Button^ btnCancel;



	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->lbSteps = (gcnew System::Windows::Forms::Label());
			this->lbDate = (gcnew System::Windows::Forms::Label());
			this->lbDescription = (gcnew System::Windows::Forms::Label());
			this->tbDescription = (gcnew System::Windows::Forms::TextBox());
			this->dtpDate = (gcnew System::Windows::Forms::DateTimePicker());
			this->btnAccept = (gcnew System::Windows::Forms::Button());
			this->btnCancel = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// lbSteps
			// 
			this->lbSteps->AutoSize = true;
			this->lbSteps->Location = System::Drawing::Point(118, 9);
			this->lbSteps->Name = L"lbSteps";
			this->lbSteps->Size = System::Drawing::Size(194, 13);
			this->lbSteps->TabIndex = 0;
			this->lbSteps->Text = L"Ingrese los datos de la entrada del perfil";
			// 
			// lbDate
			// 
			this->lbDate->AutoSize = true;
			this->lbDate->Location = System::Drawing::Point(12, 40);
			this->lbDate->Name = L"lbDate";
			this->lbDate->Size = System::Drawing::Size(37, 13);
			this->lbDate->TabIndex = 1;
			this->lbDate->Text = L"Fecha";
			// 
			// lbDescription
			// 
			this->lbDescription->AutoSize = true;
			this->lbDescription->Location = System::Drawing::Point(12, 91);
			this->lbDescription->Name = L"lbDescription";
			this->lbDescription->Size = System::Drawing::Size(63, 13);
			this->lbDescription->TabIndex = 2;
			this->lbDescription->Text = L"Descripcion";
			// 
			// tbDescription
			// 
			this->tbDescription->Location = System::Drawing::Point(12, 107);
			this->tbDescription->Multiline = true;
			this->tbDescription->Name = L"tbDescription";
			this->tbDescription->Size = System::Drawing::Size(435, 256);
			this->tbDescription->TabIndex = 4;
			// 
			// dtpDate
			// 
			this->dtpDate->CustomFormat = L"yyyy-MM-dd";
			this->dtpDate->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
			this->dtpDate->Location = System::Drawing::Point(12, 56);
			this->dtpDate->Name = L"dtpDate";
			this->dtpDate->Size = System::Drawing::Size(435, 20);
			this->dtpDate->TabIndex = 5;
			this->dtpDate->Value = System::DateTime(2023, 6, 27, 0, 0, 0, 0);
			// 
			// btnAccept
			// 
			this->btnAccept->Location = System::Drawing::Point(371, 370);
			this->btnAccept->Name = L"btnAccept";
			this->btnAccept->Size = System::Drawing::Size(75, 23);
			this->btnAccept->TabIndex = 6;
			this->btnAccept->Text = L"Aceptar";
			this->btnAccept->UseVisualStyleBackColor = true;
			this->btnAccept->Click += gcnew System::EventHandler(this, &NewEntryForm::btnAccept_Click);
			// 
			// btnCancel
			// 
			this->btnCancel->Location = System::Drawing::Point(12, 369);
			this->btnCancel->Name = L"btnCancel";
			this->btnCancel->Size = System::Drawing::Size(75, 23);
			this->btnCancel->TabIndex = 7;
			this->btnCancel->Text = L"Cancelar";
			this->btnCancel->UseVisualStyleBackColor = true;
			// 
			// NewEntryForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(459, 401);
			this->Controls->Add(this->btnCancel);
			this->Controls->Add(this->btnAccept);
			this->Controls->Add(this->dtpDate);
			this->Controls->Add(this->tbDescription);
			this->Controls->Add(this->lbDescription);
			this->Controls->Add(this->lbDate);
			this->Controls->Add(this->lbSteps);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"NewEntryForm";
			this->Text = L"Agregar Entrada";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnAccept_Click(System::Object^ sender, System::EventArgs^ e);
};
}
