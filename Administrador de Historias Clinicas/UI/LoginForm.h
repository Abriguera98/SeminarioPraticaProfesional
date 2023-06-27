#pragma once

#include <cassert>
#include <msclr\marshal_cppstd.h>

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
	/// Summary for LoginForm
	/// </summary>
	public ref class LoginForm : public System::Windows::Forms::Form
	{
	public:
		LoginForm(GUIManager* parent)
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
		~LoginForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: GUIManager* mManagerInstance;

	private: System::Windows::Forms::TextBox^ tbUser;
	private: System::Windows::Forms::TextBox^ tbPassword;


	private: System::Windows::Forms::Label^ lbUser;
	private: System::Windows::Forms::Label^ lbPass;
	private: System::Windows::Forms::Button^ btnCancel;

	private: System::Windows::Forms::Button^ btnAccept;





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
			this->tbUser = (gcnew System::Windows::Forms::TextBox());
			this->tbPassword = (gcnew System::Windows::Forms::TextBox());
			this->lbUser = (gcnew System::Windows::Forms::Label());
			this->lbPass = (gcnew System::Windows::Forms::Label());
			this->btnCancel = (gcnew System::Windows::Forms::Button());
			this->btnAccept = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// tbUser
			// 
			this->tbUser->Location = System::Drawing::Point(12, 41);
			this->tbUser->Name = L"tbUser";
			this->tbUser->Size = System::Drawing::Size(385, 20);
			this->tbUser->TabIndex = 0;
			// 
			// tbPassword
			// 
			this->tbPassword->Location = System::Drawing::Point(12, 92);
			this->tbPassword->Name = L"tbPassword";
			this->tbPassword->PasswordChar = '*';
			this->tbPassword->Size = System::Drawing::Size(385, 20);
			this->tbPassword->TabIndex = 1;
			// 
			// lbUser
			// 
			this->lbUser->AutoSize = true;
			this->lbUser->Location = System::Drawing::Point(12, 25);
			this->lbUser->Name = L"lbUser";
			this->lbUser->Size = System::Drawing::Size(46, 13);
			this->lbUser->TabIndex = 3;
			this->lbUser->Text = L"Usuario:";
			// 
			// lbPass
			// 
			this->lbPass->AutoSize = true;
			this->lbPass->Location = System::Drawing::Point(9, 76);
			this->lbPass->Name = L"lbPass";
			this->lbPass->Size = System::Drawing::Size(64, 13);
			this->lbPass->TabIndex = 4;
			this->lbPass->Text = L"Contraseña:";
			// 
			// btnCancel
			// 
			this->btnCancel->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->btnCancel->Location = System::Drawing::Point(12, 164);
			this->btnCancel->Name = L"btnCancel";
			this->btnCancel->Size = System::Drawing::Size(75, 23);
			this->btnCancel->TabIndex = 5;
			this->btnCancel->Text = L"Cancelar";
			this->btnCancel->UseVisualStyleBackColor = true;
			this->btnCancel->Click += gcnew System::EventHandler(this, &LoginForm::btnCancel_Click);
			// 
			// btnAccept
			// 
			this->btnAccept->Location = System::Drawing::Point(322, 164);
			this->btnAccept->Name = L"btnAccept";
			this->btnAccept->Size = System::Drawing::Size(75, 23);
			this->btnAccept->TabIndex = 6;
			this->btnAccept->Text = L"Aceptar";
			this->btnAccept->UseVisualStyleBackColor = true;
			this->btnAccept->Click += gcnew System::EventHandler(this, &LoginForm::btnAccept_Click);
			// 
			// LoginForm
			// 
			this->AcceptButton = this->btnAccept;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->CancelButton = this->btnCancel;
			this->ClientSize = System::Drawing::Size(409, 199);
			this->Controls->Add(this->btnAccept);
			this->Controls->Add(this->btnCancel);
			this->Controls->Add(this->lbPass);
			this->Controls->Add(this->lbUser);
			this->Controls->Add(this->tbPassword);
			this->Controls->Add(this->tbUser);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"LoginForm";
			this->Text = L"LoginForm";
			this->ResumeLayout(false);
			this->PerformLayout();

			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &LoginForm::FormClosingHandler);
		}

		private: System::Void btnAccept_Click(System::Object^ sender, System::EventArgs^ e);
		private: void FormClosingHandler(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e);
		private: System::Void btnCancel_Click(System::Object^ sender, System::EventArgs^ e);
	};
}
