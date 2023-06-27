#pragma once
#include "../Core/GUIManager.h"
#include "VisualizationForm.h"
#include "NewEntryForm.h"
#include "NewProfileForm.h"

namespace UIForms {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MainScreen
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(GUIManager* parent)
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
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: GUIManager* mManagerInstance;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ btnSearch;
	private: System::Windows::Forms::ListView^ lsvData;
	private: System::Windows::Forms::Button^ btnCreate;
	private: System::Windows::Forms::Button^ btnAdd;

	private: System::Windows::Forms::Button^ btnClose;

	private: System::Windows::Forms::ColumnHeader^ ColDNI;

	private: System::Windows::Forms::ColumnHeader^ ColFirstName;

	private: System::Windows::Forms::ColumnHeader^ ColLastName;

	private: System::Windows::Forms::ColumnHeader^ ColLastMod;
	private: System::Windows::Forms::Button^ btnView;
	private: System::Windows::Forms::ColumnHeader^ colStatus;


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
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->btnSearch = (gcnew System::Windows::Forms::Button());
			this->lsvData = (gcnew System::Windows::Forms::ListView());
			this->ColDNI = (gcnew System::Windows::Forms::ColumnHeader());
			this->ColFirstName = (gcnew System::Windows::Forms::ColumnHeader());
			this->ColLastName = (gcnew System::Windows::Forms::ColumnHeader());
			this->ColLastMod = (gcnew System::Windows::Forms::ColumnHeader());
			this->colStatus = (gcnew System::Windows::Forms::ColumnHeader());
			this->btnCreate = (gcnew System::Windows::Forms::Button());
			this->btnAdd = (gcnew System::Windows::Forms::Button());
			this->btnClose = (gcnew System::Windows::Forms::Button());
			this->btnView = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(12, 12);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(903, 20);
			this->textBox1->TabIndex = 0;
			// 
			// btnSearch
			// 
			this->btnSearch->Location = System::Drawing::Point(921, 12);
			this->btnSearch->Name = L"btnSearch";
			this->btnSearch->Size = System::Drawing::Size(75, 23);
			this->btnSearch->TabIndex = 1;
			this->btnSearch->Text = L"Buscar";
			this->btnSearch->UseVisualStyleBackColor = true;
			this->btnSearch->Click += gcnew System::EventHandler(this, &MainForm::btnSearch_Click);
			// 
			// lsvData
			// 
			this->lsvData->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(5) {
				this->ColDNI, this->ColFirstName,
					this->ColLastName, this->ColLastMod, this->colStatus
			});
			this->lsvData->FullRowSelect = true;
			this->lsvData->HideSelection = false;
			this->lsvData->Location = System::Drawing::Point(12, 41);
			this->lsvData->MultiSelect = false;
			this->lsvData->Name = L"lsvData";
			this->lsvData->Size = System::Drawing::Size(984, 647);
			this->lsvData->TabIndex = 2;
			this->lsvData->UseCompatibleStateImageBehavior = false;
			this->lsvData->View = System::Windows::Forms::View::Details;
			this->lsvData->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::lsvData_SelectedIndexChanged);
			// 
			// ColDNI
			// 
			this->ColDNI->Text = L"DNI";
			this->ColDNI->Width = 179;
			// 
			// ColFirstName
			// 
			this->ColFirstName->Text = L"Nombre";
			this->ColFirstName->Width = 225;
			// 
			// ColLastName
			// 
			this->ColLastName->Text = L"Apellido";
			this->ColLastName->Width = 237;
			// 
			// ColLastMod
			// 
			this->ColLastMod->Text = L"Fecha de Ultima Consulta";
			this->ColLastMod->Width = 279;
			// 
			// colStatus
			// 
			this->colStatus->Text = L"Estado";
			// 
			// btnCreate
			// 
			this->btnCreate->Location = System::Drawing::Point(12, 694);
			this->btnCreate->Name = L"btnCreate";
			this->btnCreate->Size = System::Drawing::Size(240, 23);
			this->btnCreate->TabIndex = 3;
			this->btnCreate->Text = L"Crear Nuevo Perfil";
			this->btnCreate->UseVisualStyleBackColor = true;
			this->btnCreate->Click += gcnew System::EventHandler(this, &MainForm::btnCreate_Click);
			// 
			// btnAdd
			// 
			this->btnAdd->Enabled = false;
			this->btnAdd->Location = System::Drawing::Point(510, 694);
			this->btnAdd->Name = L"btnAdd";
			this->btnAdd->Size = System::Drawing::Size(240, 23);
			this->btnAdd->TabIndex = 5;
			this->btnAdd->Text = L"Agregar Entrada";
			this->btnAdd->UseVisualStyleBackColor = true;
			this->btnAdd->Click += gcnew System::EventHandler(this, &MainForm::btnAdd_Click);
			// 
			// btnClose
			// 
			this->btnClose->Enabled = false;
			this->btnClose->Location = System::Drawing::Point(756, 694);
			this->btnClose->Name = L"btnClose";
			this->btnClose->Size = System::Drawing::Size(240, 23);
			this->btnClose->TabIndex = 6;
			this->btnClose->Text = L"Cerrar Perfil";
			this->btnClose->UseVisualStyleBackColor = true;
			this->btnClose->Click += gcnew System::EventHandler(this, &MainForm::btnClose_Click);
			// 
			// btnView
			// 
			this->btnView->Enabled = false;
			this->btnView->Location = System::Drawing::Point(258, 694);
			this->btnView->Name = L"btnView";
			this->btnView->Size = System::Drawing::Size(240, 23);
			this->btnView->TabIndex = 7;
			this->btnView->Text = L"Ver Perfil";
			this->btnView->UseVisualStyleBackColor = true;
			this->btnView->Click += gcnew System::EventHandler(this, &MainForm::btnView_Click);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1008, 729);
			this->Controls->Add(this->btnView);
			this->Controls->Add(this->btnClose);
			this->Controls->Add(this->btnAdd);
			this->Controls->Add(this->btnCreate);
			this->Controls->Add(this->lsvData);
			this->Controls->Add(this->btnSearch);
			this->Controls->Add(this->textBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"MainForm";
			this->Text = L"MainScreen";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->Closed += gcnew System::EventHandler(this, &MainForm::UserClosing);
			this->ResumeLayout(false);
			this->PerformLayout();

		}

		private: System::Void MainForm_Load(System::Object^ sender, System::EventArgs^ e);
		private: System::Void lsvData_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e);
		private: System::Void btnView_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void btnClose_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void btnSearch_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void btnCreate_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void btnAdd_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void UserClosing(System::Object^ sender, System::EventArgs^ e);
				
	};
}
