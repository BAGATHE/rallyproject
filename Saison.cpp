#include "Saison.h"
#include "Connection.h"
using namespace System;
using namespace System::Data;
using namespace System::Collections::Generic;
using namespace System::Data::SqlClient;
using namespace System::Windows::Forms;
using namespace DataAccess;

namespace Model
{
    // Constructeur avec paramètres
    Saison::Saison(int idSaison, int annee)
    {
        this->idSaison = idSaison;
        this->annee = annee;
        this->rallyes = gcnew List<Rallye^>();
    }

    // Méthode pour ajouter un Rallye à la liste
    void Saison::addRallye(Rallye^ rallye)
    {
        rallyes->Add(rallye);
    }

    // Getter pour idSaison
    int Saison::getIdSaison()
    {
        return idSaison;
    }

    // Getter pour annee
    int Saison::getAnnee()
    {
        return annee;
    }

    // Getter pour la liste de Rallye
    List<Rallye^>^ Saison::getRallyes()
    {
        return rallyes;
    }

    // Méthode pour obtenir toutes les saisons depuis la base de données
    List<Saison^>^ Saison::getAllSaisons() {
        List<Saison^>^ listSaison = gcnew List<Saison^>();

        SqlConnection^ connection = DataAccess::Connection::getConnection();

        try {
            connection->Open();
            String^ query = "SELECT * FROM Saison";
            SqlCommand^ command = gcnew SqlCommand(query, connection);
            SqlDataReader^ reader = command->ExecuteReader();

            while (reader->Read()) {
                Saison^ saison = gcnew Saison(reader->GetInt32(0), reader->GetInt32(1));
                listSaison->Add(saison);
            }
            reader->Close();
        }
        catch (SqlException^ ex) {
            MessageBox::Show("Erreur de connexion: " + ex->Message, "Message", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
        finally {
            if (connection->State == ConnectionState::Open) {
                connection->Close();
            }
        }

        return listSaison;
    }
}
