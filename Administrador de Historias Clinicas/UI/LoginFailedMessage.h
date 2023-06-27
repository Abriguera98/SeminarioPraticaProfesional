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
	/// Summary for LoginFailled
	/// </summary>
	public ref class LoginFailedMessage : public System::Windows::Forms::Form
	{
	public:
		LoginFailedMessage(GUIManager* parent)
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
		~LoginFailedMessage()
		{
			if (components)
			{
				delete components;
			}
		}
	private: GUIManager* mManagerInstance;

	private: System::Windows::Forms::Button^ btnAccept;
	private: System::Windows::Forms::Label^ lbInfo;
	protected:

	protected:

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
			this->btnAccept = (gcnew System::Windows::Forms::Button());
			this->lbInfo = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// btnAccept
			// 
			this->btnAccept->Location = System::Drawing::Point(142, 37);
			this->btnAccept->Name = L"btnAccept";
			this->btnAccept->Size = System::Drawing::Size(75, 23);
			this->btnAccept->TabIndex = 0;
			this->btnAccept->Text = L"Aceptar";
			this->btnAccept->UseVisualStyleBackColor = true;
			this->btnAccept->Click += gcnew System::EventHandler(this, &LoginFailedMessage::btnAccept_Click);
			// 
			// lbInfo
			// 
			this->lbInfo->AutoSize = true;
			this->lbInfo->Location = System::Drawing::Point(65, 17);
			this->lbInfo->Name = L"lbInfo";
			this->lbInfo->Size = System::Drawing::Size(235, 13);
			this->lbInfo->TabIndex = 1;
			this->lbInfo->Text = L"El nombre de usuario o contraseña es incorrecto";
			// 
			// LoginFailedMessage
			// 
			this->AcceptButton = this->btnAccept;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(370, 72);
			this->ControlBox = false;
			this->Controls->Add(this->lbInfo);
			this->Controls->Add(this->btnAccept);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"LoginFailedMessage";
			this->Text = L"Error al inciar sesion";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		private: System::Void btnAccept_Click(System::Object^ sender, System::EventArgs^ e);
	};
}
