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
	/// Summary for VisualizationForm
	/// </summary>
	public ref class VisualizationForm : public System::Windows::Forms::Form
	{
	public:
		VisualizationForm(GUIManager* parent, unsigned int profileID)
			: mManagerInstance(parent), mProfileID(profileID)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

		void setVolunteerData(System::String^ aVolunteerName, System::String^ aDNI)
		{
			this->tbVolunteer->Text = aVolunteerName;
			this->tbDNI->Text = aDNI;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~VisualizationForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: GUIManager* mManagerInstance;
	private: unsigned int mProfileID;
	private: System::Windows::Forms::ListView^ lsvEnrtys;
	private: System::Windows::Forms::TextBox^ tbDescription;


	private: System::Windows::Forms::Label^ lbVolunteer;
	private: System::Windows::Forms::Label^ lbDNI;
	private: System::Windows::Forms::Label^ lbEntrys;



	private: System::Windows::Forms::TextBox^ tbVolunteer;
	private: System::Windows::Forms::TextBox^ tbDNI;
	private: System::Windows::Forms::Label^ lbDescription;
	private: System::Windows::Forms::Button^ btBack;
	private: System::Windows::Forms::ColumnHeader^ Fecha;
	private: System::Windows::Forms::Label^ lbAuthor;
	private: System::Windows::Forms::TextBox^ tbAuthor;


	protected:

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
			this->lsvEnrtys = (gcnew System::Windows::Forms::ListView());
			this->Fecha = (gcnew System::Windows::Forms::ColumnHeader());
			this->tbDescription = (gcnew System::Windows::Forms::TextBox());
			this->lbVolunteer = (gcnew System::Windows::Forms::Label());
			this->lbDNI = (gcnew System::Windows::Forms::Label());
			this->lbEntrys = (gcnew System::Windows::Forms::Label());
			this->tbVolunteer = (gcnew System::Windows::Forms::TextBox());
			this->tbDNI = (gcnew System::Windows::Forms::TextBox());
			this->lbDescription = (gcnew System::Windows::Forms::Label());
			this->btBack = (gcnew System::Windows::Forms::Button());
			this->lbAuthor = (gcnew System::Windows::Forms::Label());
			this->tbAuthor = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// lsvEnrtys
			// 
			this->lsvEnrtys->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(1) { this->Fecha });
			this->lsvEnrtys->FullRowSelect = true;
			this->lsvEnrtys->HideSelection = false;
			this->lsvEnrtys->Location = System::Drawing::Point(12, 65);
			this->lsvEnrtys->MultiSelect = false;
			this->lsvEnrtys->Name = L"lsvEnrtys";
			this->lsvEnrtys->Size = System::Drawing::Size(245, 430);
			this->lsvEnrtys->TabIndex = 0;
			this->lsvEnrtys->UseCompatibleStateImageBehavior = false;
			this->lsvEnrtys->View = System::Windows::Forms::View::Details;
			this->lsvEnrtys->SelectedIndexChanged += gcnew System::EventHandler(this, &VisualizationForm::listView1_SelectedIndexChanged);
			// 
			// Fecha
			// 
			this->Fecha->Text = L"Fecha";
			this->Fecha->Width = 245;
			// 
			// tbDescription
			// 
			this->tbDescription->Location = System::Drawing::Point(263, 65);
			this->tbDescription->Multiline = true;
			this->tbDescription->Name = L"tbDescription";
			this->tbDescription->ReadOnly = true;
			this->tbDescription->Size = System::Drawing::Size(511, 403);
			this->tbDescription->TabIndex = 1;
			// 
			// lbVolunteer
			// 
			this->lbVolunteer->AutoSize = true;
			this->lbVolunteer->Location = System::Drawing::Point(16, 16);
			this->lbVolunteer->Name = L"lbVolunteer";
			this->lbVolunteer->Size = System::Drawing::Size(57, 13);
			this->lbVolunteer->TabIndex = 2;
			this->lbVolunteer->Text = L"Voluntario:";
			// 
			// lbDNI
			// 
			this->lbDNI->AutoSize = true;
			this->lbDNI->Location = System::Drawing::Point(377, 15);
			this->lbDNI->Name = L"lbDNI";
			this->lbDNI->Size = System::Drawing::Size(65, 13);
			this->lbDNI->TabIndex = 3;
			this->lbDNI->Text = L"Documento:";
			// 
			// lbEntrys
			// 
			this->lbEntrys->AutoSize = true;
			this->lbEntrys->Location = System::Drawing::Point(16, 49);
			this->lbEntrys->Name = L"lbEntrys";
			this->lbEntrys->Size = System::Drawing::Size(52, 13);
			this->lbEntrys->TabIndex = 4;
			this->lbEntrys->Text = L"Entradas:";
			// 
			// tbVolunteer
			// 
			this->tbVolunteer->Location = System::Drawing::Point(79, 9);
			this->tbVolunteer->Name = L"tbVolunteer";
			this->tbVolunteer->ReadOnly = true;
			this->tbVolunteer->Size = System::Drawing::Size(292, 20);
			this->tbVolunteer->TabIndex = 5;
			// 
			// tbDNI
			// 
			this->tbDNI->Location = System::Drawing::Point(448, 9);
			this->tbDNI->Name = L"tbDNI";
			this->tbDNI->ReadOnly = true;
			this->tbDNI->Size = System::Drawing::Size(325, 20);
			this->tbDNI->TabIndex = 6;
			// 
			// lbDescription
			// 
			this->lbDescription->AutoSize = true;
			this->lbDescription->Location = System::Drawing::Point(263, 49);
			this->lbDescription->Name = L"lbDescription";
			this->lbDescription->Size = System::Drawing::Size(66, 13);
			this->lbDescription->TabIndex = 7;
			this->lbDescription->Text = L"Descripcion:";
			// 
			// btBack
			// 
			this->btBack->Location = System::Drawing::Point(699, 507);
			this->btBack->Name = L"btBack";
			this->btBack->Size = System::Drawing::Size(75, 23);
			this->btBack->TabIndex = 8;
			this->btBack->Text = L"Volver";
			this->btBack->UseVisualStyleBackColor = true;
			this->btBack->Click += gcnew System::EventHandler(this, &VisualizationForm::btBack_Click);
			// 
			// lbAuthor
			// 
			this->lbAuthor->AutoSize = true;
			this->lbAuthor->Location = System::Drawing::Point(266, 481);
			this->lbAuthor->Name = L"lbAuthor";
			this->lbAuthor->Size = System::Drawing::Size(35, 13);
			this->lbAuthor->TabIndex = 9;
			this->lbAuthor->Text = L"Autor:";
			// 
			// tbAuthor
			// 
			this->tbAuthor->Location = System::Drawing::Point(307, 474);
			this->tbAuthor->Name = L"tbAuthor";
			this->tbAuthor->ReadOnly = true;
			this->tbAuthor->Size = System::Drawing::Size(466, 20);
			this->tbAuthor->TabIndex = 10;
			// 
			// VisualizationForm
			// 
			this->AcceptButton = this->btBack;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(786, 542);
			this->Controls->Add(this->tbAuthor);
			this->Controls->Add(this->lbAuthor);
			this->Controls->Add(this->btBack);
			this->Controls->Add(this->lbDescription);
			this->Controls->Add(this->tbDNI);
			this->Controls->Add(this->tbVolunteer);
			this->Controls->Add(this->lbEntrys);
			this->Controls->Add(this->lbDNI);
			this->Controls->Add(this->lbVolunteer);
			this->Controls->Add(this->tbDescription);
			this->Controls->Add(this->lsvEnrtys);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"Visualizar Perfil";
			this->Text = L"Visualizar Perfil";
			this->Load += gcnew System::EventHandler(this, &VisualizationForm::VisualizationForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void listView1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void VisualizationForm_Load(System::Object^ sender, System::EventArgs^ e);
private: System::Void btBack_Click(System::Object^ sender, System::EventArgs^ e);
};
}
