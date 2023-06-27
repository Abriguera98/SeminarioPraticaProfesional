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
	/// Summary for NewProfileForm
	/// </summary>
	public ref class NewProfileForm : public System::Windows::Forms::Form
	{
	public:
		NewProfileForm(GUIManager* parent)
			: mManagerInstance(parent)
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
		~NewProfileForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: GUIManager* mManagerInstance;
	private: System::Windows::Forms::Label^ lbName;
	private: System::Windows::Forms::TextBox^ tbName;
	protected:

	protected:

	private: System::Windows::Forms::TextBox^ tbLastName;

	private: System::Windows::Forms::Label^ lbLastName;
	private: System::Windows::Forms::TextBox^ tbDNI;


	private: System::Windows::Forms::Label^ lbDNI;

	private: System::Windows::Forms::Label^ label4;
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
			this->lbName = (gcnew System::Windows::Forms::Label());
			this->tbName = (gcnew System::Windows::Forms::TextBox());
			this->tbLastName = (gcnew System::Windows::Forms::TextBox());
			this->lbLastName = (gcnew System::Windows::Forms::Label());
			this->tbDNI = (gcnew System::Windows::Forms::TextBox());
			this->lbDNI = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->btnAccept = (gcnew System::Windows::Forms::Button());
			this->btnCancel = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// lbName
			// 
			this->lbName->AutoSize = true;
			this->lbName->Location = System::Drawing::Point(12, 33);
			this->lbName->Name = L"lbName";
			this->lbName->Size = System::Drawing::Size(47, 13);
			this->lbName->TabIndex = 0;
			this->lbName->Text = L"Nombre:";
			// 
			// tbName
			// 
			this->tbName->Location = System::Drawing::Point(12, 49);
			this->tbName->Name = L"tbName";
			this->tbName->Size = System::Drawing::Size(373, 20);
			this->tbName->TabIndex = 1;
			// 
			// tbLastName
			// 
			this->tbLastName->Location = System::Drawing::Point(12, 88);
			this->tbLastName->Name = L"tbLastName";
			this->tbLastName->Size = System::Drawing::Size(373, 20);
			this->tbLastName->TabIndex = 3;
			// 
			// lbLastName
			// 
			this->lbLastName->AutoSize = true;
			this->lbLastName->Location = System::Drawing::Point(12, 72);
			this->lbLastName->Name = L"lbLastName";
			this->lbLastName->Size = System::Drawing::Size(47, 13);
			this->lbLastName->TabIndex = 2;
			this->lbLastName->Text = L"Apellido:";
			// 
			// tbDNI
			// 
			this->tbDNI->Location = System::Drawing::Point(12, 129);
			this->tbDNI->MaxLength = 10;
			this->tbDNI->Name = L"tbDNI";
			this->tbDNI->Size = System::Drawing::Size(373, 20);
			this->tbDNI->TabIndex = 5;
			// 
			// lbDNI
			// 
			this->lbDNI->AutoSize = true;
			this->lbDNI->Location = System::Drawing::Point(12, 113);
			this->lbDNI->Name = L"lbDNI";
			this->lbDNI->Size = System::Drawing::Size(29, 13);
			this->lbDNI->TabIndex = 4;
			this->lbDNI->Text = L"DNI:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(120, 9);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(154, 13);
			this->label4->TabIndex = 6;
			this->label4->Text = L"Ingrese los datos del Voluntario";
			// 
			// btnAccept
			// 
			this->btnAccept->Location = System::Drawing::Point(310, 164);
			this->btnAccept->Name = L"btnAccept";
			this->btnAccept->Size = System::Drawing::Size(75, 23);
			this->btnAccept->TabIndex = 7;
			this->btnAccept->Text = L"Aceptar";
			this->btnAccept->UseVisualStyleBackColor = true;
			this->btnAccept->Click += gcnew System::EventHandler(this, &NewProfileForm::btnAccept_Click);
			// 
			// btnCancel
			// 
			this->btnCancel->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->btnCancel->Location = System::Drawing::Point(12, 164);
			this->btnCancel->Name = L"btnCancel";
			this->btnCancel->Size = System::Drawing::Size(75, 23);
			this->btnCancel->TabIndex = 8;
			this->btnCancel->Text = L"Cancelar";
			this->btnCancel->UseVisualStyleBackColor = true;
			// 
			// NewProfileForm
			// 
			this->AcceptButton = this->btnAccept;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->CancelButton = this->btnCancel;
			this->ClientSize = System::Drawing::Size(397, 202);
			this->Controls->Add(this->btnCancel);
			this->Controls->Add(this->btnAccept);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->tbDNI);
			this->Controls->Add(this->lbDNI);
			this->Controls->Add(this->tbLastName);
			this->Controls->Add(this->lbLastName);
			this->Controls->Add(this->tbName);
			this->Controls->Add(this->lbName);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"NewProfileForm";
			this->Text = L"Crear Perfil";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
	private: System::Void btnAccept_Click(System::Object^ sender, System::EventArgs^ e);
};
}
