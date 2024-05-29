#pragma once
#include "Rallye.h"
#include "Classement.h"

namespace rallyecpp {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace Model;


	/// <summary>
	/// Description résumée de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: ajoutez ici le code du constructeur
			//
		}

	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::Button^ SaisonBtn;
	private: System::Windows::Forms::Button^ RallyeBtn;
	private: System::Windows::Forms::Button^ SpecialBtn;
	private: System::Windows::Forms::Button^ CourseBtn;
	private: System::Windows::Forms::Button^ classementBtn;


    //element du panel2 
	private: System::Windows::Forms::Button^ btn_show_classement;
	private: System::Windows::Forms::ComboBox^ cbb_classement_rallye;
	private: System::Windows::Forms::ComboBox^ cbb_categorie;







	private:
		/// <summary>
		/// Variable nécessaire au concepteur.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Méthode requise pour la prise en charge du concepteur - ne modifiez pas
		/// le contenu de cette méthode avec l'éditeur de code.
		/// </summary>
		void InitializeComponent(void)
		{
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->btn_show_classement = (gcnew System::Windows::Forms::Button());
			this->cbb_classement_rallye = (gcnew System::Windows::Forms::ComboBox());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->classementBtn = (gcnew System::Windows::Forms::Button());
			this->CourseBtn = (gcnew System::Windows::Forms::Button());
			this->SpecialBtn = (gcnew System::Windows::Forms::Button());
			this->RallyeBtn = (gcnew System::Windows::Forms::Button());
			this->SaisonBtn = (gcnew System::Windows::Forms::Button());
			this->cbb_categorie = (gcnew System::Windows::Forms::ComboBox());
			this->panel2->SuspendLayout();
			this->panel3->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->cbb_categorie);
			this->panel2->Controls->Add(this->btn_show_classement);
			this->panel2->Controls->Add(this->cbb_classement_rallye);
			this->panel2->Location = System::Drawing::Point(0, 58);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(1001, 401);
			this->panel2->TabIndex = 1;
			this->panel2->Visible = false;
			// 
			// btn_show_classement
			// 
			this->btn_show_classement->Location = System::Drawing::Point(439, 105);
			this->btn_show_classement->Name = L"btn_show_classement";
			this->btn_show_classement->Size = System::Drawing::Size(198, 23);
			this->btn_show_classement->TabIndex = 1;
			this->btn_show_classement->Text = L"Show Classement";
			this->btn_show_classement->UseVisualStyleBackColor = true;
			this->btn_show_classement->Click += gcnew System::EventHandler(this, &MyForm::show_classement_click);
			// 
			// cbb_classement_rallye
			// 
			this->cbb_classement_rallye->FormattingEnabled = true;
			this->cbb_classement_rallye->Location = System::Drawing::Point(330, 27);
			this->cbb_classement_rallye->Name = L"cbb_classement_rallye";
			this->cbb_classement_rallye->Size = System::Drawing::Size(381, 21);
			this->cbb_classement_rallye->TabIndex = 0;
			// 
			// panel3
			// 
			this->panel3->Controls->Add(this->classementBtn);
			this->panel3->Controls->Add(this->CourseBtn);
			this->panel3->Controls->Add(this->SpecialBtn);
			this->panel3->Controls->Add(this->RallyeBtn);
			this->panel3->Controls->Add(this->SaisonBtn);
			this->panel3->Location = System::Drawing::Point(0, 1);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(998, 51);
			this->panel3->TabIndex = 2;
			// 
			// classementBtn
			// 
			this->classementBtn->Location = System::Drawing::Point(816, 11);
			this->classementBtn->Name = L"classementBtn";
			this->classementBtn->Size = System::Drawing::Size(127, 24);
			this->classementBtn->TabIndex = 4;
			this->classementBtn->Text = L"classement";
			this->classementBtn->UseVisualStyleBackColor = true;
			this->classementBtn->Click += gcnew System::EventHandler(this, &MyForm::classement_click);
			// 
			// CourseBtn
			// 
			this->CourseBtn->Location = System::Drawing::Point(231, 11);
			this->CourseBtn->Name = L"CourseBtn";
			this->CourseBtn->Size = System::Drawing::Size(127, 24);
			this->CourseBtn->TabIndex = 3;
			this->CourseBtn->Text = L"Course";
			this->CourseBtn->UseVisualStyleBackColor = true;
			this->CourseBtn->Click += gcnew System::EventHandler(this, &MyForm::courseBtn);
			// 
			// SpecialBtn
			// 
			this->SpecialBtn->Location = System::Drawing::Point(639, 11);
			this->SpecialBtn->Name = L"SpecialBtn";
			this->SpecialBtn->Size = System::Drawing::Size(127, 24);
			this->SpecialBtn->TabIndex = 2;
			this->SpecialBtn->Text = L"Special";
			this->SpecialBtn->UseVisualStyleBackColor = true;
			this->SpecialBtn->Click += gcnew System::EventHandler(this, &MyForm::special_click);
			// 
			// RallyeBtn
			// 
			this->RallyeBtn->Location = System::Drawing::Point(439, 11);
			this->RallyeBtn->Name = L"RallyeBtn";
			this->RallyeBtn->Size = System::Drawing::Size(127, 24);
			this->RallyeBtn->TabIndex = 1;
			this->RallyeBtn->Text = L"Rallye";
			this->RallyeBtn->UseVisualStyleBackColor = true;
			this->RallyeBtn->Click += gcnew System::EventHandler(this, &MyForm::rallye_click);
			// 
			// SaisonBtn
			// 
			this->SaisonBtn->Location = System::Drawing::Point(39, 11);
			this->SaisonBtn->Name = L"SaisonBtn";
			this->SaisonBtn->Size = System::Drawing::Size(127, 24);
			this->SaisonBtn->TabIndex = 0;
			this->SaisonBtn->Text = L"Saison";
			this->SaisonBtn->UseVisualStyleBackColor = true;
			this->SaisonBtn->Click += gcnew System::EventHandler(this, &MyForm::saisonClick);
			// 
			// cbb_categorie
			// 
			this->cbb_categorie->FormattingEnabled = true;
			this->cbb_categorie->Location = System::Drawing::Point(332, 69);
			this->cbb_categorie->Name = L"cbb_categorie";
			this->cbb_categorie->Size = System::Drawing::Size(378, 21);
			this->cbb_categorie->TabIndex = 2;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1000, 800);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->panel2);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->panel2->ResumeLayout(false);
			this->panel3->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void saisonClick(System::Object^ sender, System::EventArgs^ e) {
		this->panel2->Visible = false;
	}
	private: System::Void rallye_click(System::Object^ sender, System::EventArgs^ e) {
		this->panel2->Visible = false;
	}
private: System::Void special_click(System::Object^ sender, System::EventArgs^ e) {
	this->panel2->Visible = false;
}
private: System::Void courseBtn(System::Object^ sender, System::EventArgs^ e) {
	this->panel2->Visible = false;
}
private: System::Void classement_click(System::Object^ sender, System::EventArgs^ e) {
	this->panel2->Visible = true;
	// Supposons que getSaison() retourne un tableau de chaînes de caractères représentant les années des saisons
	List<Rallye^>^ rallyes = Rallye::getAllRallyes();
	// Vider le ComboBox avant d'ajouter les nouvelles données
	this->cbb_classement_rallye->Items->Clear();
	// Ajouter les années des saisons au ComboBox
	for (int i = 0; i < rallyes->Count; i++) {
		int idRallye = rallyes[i]->getIdRallye();
		String^ intituler = rallyes[i]->getIntituler();
		String^ choix = System::Convert::ToString(idRallye)+"-"+intituler;
		this->cbb_classement_rallye->Items->Add(choix);
	}
	
}



private: System::Void show_classement_click(System::Object^ sender, System::EventArgs^ e){
	//recupère l'option selection
	String^ selectedValue = this->cbb_classement_rallye->SelectedItem != nullptr ? this->cbb_classement_rallye->SelectedItem->ToString() : "Nothing selected";
	//splitter le message et recuperer le numero de l'option
	array<String^>^ parts = selectedValue->Split('-');
	String^ firstPart = parts[0];
	int intValue = Int32::Parse(firstPart);
	List<Classement^>^ classements = Classement::getClassementGeneral(intValue);



	//recupère l'option selection
	String^ selectedCat = this->cbb_categorie->SelectedItem != nullptr ? this->cbb_categorie->SelectedItem->ToString() : "not";
	if (selectedCat->Equals("not")) {
	
		// Initialiser le DataGridView
		DataGridView^ dataGridViewRallyes = gcnew DataGridView();
		dataGridViewRallyes->Location = System::Drawing::Point(100, 100); // Ajustez la position selon vos besoins
		dataGridViewRallyes->Size = System::Drawing::Size(500, 250); // Ajustez la taille selon vos besoins
		// Ajouter les colonnes au DataGridView
		dataGridViewRallyes->Columns->Add("rallye", "Rallye");
		dataGridViewRallyes->Columns->Add("pilote", "Pilote");
		dataGridViewRallyes->Columns->Add("categorie", "Categorie");
		dataGridViewRallyes->Columns->Add("tempTotal", "Temptotal");
		dataGridViewRallyes->Columns->Add("rang", "Rang");
		dataGridViewRallyes->Columns->Add("point", "Point");


		// Ajouter les données des rallyes au DataGridView
		for (int i = 0; i < classements->Count; i++) {
			Classement^ classement = classements[i];
			dataGridViewRallyes->Rows->Add(classement->getRallye(), classement->getPilote(), classement->getCategorie(), classement->getTempsTotal(), classement->getRank(), classement->getPoints());
		}
		// Ajouter le DataGridView au panel ou au formulaire
		this->panel2->Controls->Add(dataGridViewRallyes);
	}
	else {




		// Initialiser le DataGridView
		DataGridView^ dataGridViewRallyes = gcnew DataGridView();
		dataGridViewRallyes->Location = System::Drawing::Point(100, 200); // Ajustez la position selon vos besoins
		dataGridViewRallyes->Size = System::Drawing::Size(500, 250); // Ajustez la taille selon vos besoins
		// Ajouter les colonnes au DataGridView
		dataGridViewRallyes->Columns->Add("rallye", "Rallye");
		dataGridViewRallyes->Columns->Add("pilote", "Pilote");
		dataGridViewRallyes->Columns->Add("categorie", "Categorie");
		dataGridViewRallyes->Columns->Add("tempTotal", "Temptotal");
		dataGridViewRallyes->Columns->Add("rang", "Rang");
		dataGridViewRallyes->Columns->Add("point", "Point");


		// Ajouter les données des rallyes au DataGridView
		for (int i = 0; i < classements->Count; i++) {
			Classement^ classement = classements[i];
			dataGridViewRallyes->Rows->Add(classement->getRallye(), classement->getPilote(), classement->getCategorie(), classement->getTempsTotal(), classement->getRank(), classement->getPoints());
		}
		// Ajouter le DataGridView au panel ou au formulaire
		this->panel2->Controls->Add(dataGridViewRallyes);





		//splitter le message et recuperer le numero de l'option
		array<String^>^ parts = selectedCat->Split('-');
		String^ firstPart = parts[0];
		int intcat = Int32::Parse(firstPart);
		List<Classement^>^ classementsCats = Classement::getClassementParCategorie(intValue,intcat);



		// Initialiser le DataGridView
		DataGridView^ dataGridViewCat = gcnew DataGridView();
		dataGridViewCat->Location = System::Drawing::Point(800, 200); // Ajustez la position selon vos besoins
		dataGridViewCat->Size = System::Drawing::Size(500, 250); // Ajustez la taille selon vos besoins
		// Ajouter les colonnes au DataGridView
		dataGridViewCat->Columns->Add("rallye", "Rallye");
		dataGridViewCat->Columns->Add("pilote", "Pilote");
		dataGridViewCat->Columns->Add("categorie", "Categorie");
		dataGridViewCat->Columns->Add("tempTotal", "Temptotal");
		dataGridViewCat->Columns->Add("rang", "Rang");
		dataGridViewCat->Columns->Add("point", "Point");

		// Ajouter les données des rallyes au DataGridView
		for (int i = 0; i < classementsCats->Count; i++) {
			Classement^ classementCat = classementsCats[i];
			dataGridViewCat->Rows->Add(classementCat->getRallye(), classementCat->getPilote(), classementCat->getCategorie(), classementCat->getTempsTotal(), classementCat->getRank(), classementCat->getPoints());
		}
		// Ajouter le DataGridView au panel ou au formulaire
		this->panel2->Controls->Add(dataGridViewCat);





	}
 	
}
};
}
