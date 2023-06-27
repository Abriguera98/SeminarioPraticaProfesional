#pragma once
#include "../Core/Constants.h"
#include "../Core/GUIManager.h"
#include "../Core/StateMachine.h"

namespace UIForms {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for LandingForm
	/// </summary>
	public ref class LandingForm : public System::Windows::Forms::Form {
	public:
		LandingForm(GUIManager* parent)
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
		~LandingForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btnLogin;
	protected:

	private: System::Windows::Forms::Button^ btnExit;
	private: System::Windows::Forms::Label^ lbWelcome;
	private: GUIManager* mManagerInstance;

	private: bool keepProcessing = false;

	protected:


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->btnLogin = (gcnew System::Windows::Forms::Button());
			this->btnExit = (gcnew System::Windows::Forms::Button());
			this->lbWelcome = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// btnLogin
			// 
			this->btnLogin->Location = System::Drawing::Point(354, 51);
			this->btnLogin->Name = L"btnLogin";
			this->btnLogin->Size = System::Drawing::Size(75, 23);
			this->btnLogin->TabIndex = 0;
			this->btnLogin->Text = L"Ingresar";
			this->btnLogin->UseVisualStyleBackColor = true;
			this->btnLogin->Click += gcnew System::EventHandler(this, &LandingForm::btnLogin_Click);
			// 
			// btnExit
			// 
			this->btnExit->AutoSize = true;
			this->btnExit->Location = System::Drawing::Point(12, 51);
			this->btnExit->Name = L"btnExit";
			this->btnExit->Size = System::Drawing::Size(75, 23);
			this->btnExit->TabIndex = 1;
			this->btnExit->Text = L"Salir";
			this->btnExit->UseVisualStyleBackColor = true;
			this->btnExit->Click += gcnew System::EventHandler(this, &LandingForm::btnExit_Click);
			// 
			// lbWelcome
			// 
			this->lbWelcome->AutoSize = true;
			this->lbWelcome->Location = System::Drawing::Point(90, 22);
			this->lbWelcome->Name = L"lbWelcome";
			this->lbWelcome->Size = System::Drawing::Size(262, 13);
			this->lbWelcome->TabIndex = 2;
			this->lbWelcome->Text = L"Bienvenido al Sistema de Gestion de Historias Clinicas";
			// 
			// LandingForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(441, 88);
			this->Controls->Add(this->lbWelcome);
			this->Controls->Add(this->btnExit);
			this->Controls->Add(this->btnLogin);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"LandingForm";
			this->Text = L"Sistema de Gestion de Historias Clinicas";
			this->Closed += gcnew System::EventHandler(this, &LandingForm::UserClosing);
			this->Load += gcnew System::EventHandler(this, &LandingForm::LandingForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnExit_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}

	private: System::Void UserClosing(System::Object^ sender, System::EventArgs^ e) {
		if (!keepProcessing)
		{
			this->mManagerInstance->setResult(GUIManager::Result::eClosed);
		}
	}

	private: System::Void btnLogin_Click(System::Object^ sender, System::EventArgs^ e) {
		keepProcessing = true;
		this->mManagerInstance->setResult(GUIManager::Result::eProceedToLoginWindow);
		this->Close();
	}

	private: System::Void LandingForm_Load(System::Object^ sender, System::EventArgs^ e) {

	}
	};
}
