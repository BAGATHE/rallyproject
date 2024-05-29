#include "Classement.h"
#include "Connection.h"

using namespace System;
using namespace System::Data;
using namespace System::Collections::Generic;
using namespace System::Data::SqlClient;
using namespace System::Windows::Forms;
using namespace DataAccess;
namespace Model
{
    // Constructo
    Classement::Classement(int idRallye, int idCategorie, int idPilote, String^ rallye,
        String^ pilote, String^ categorie, String^ tempsTotal,
        int rank, int points)
    {
        this->idRallye = idRallye;
        this->idCategorie = idCategorie;
        this->idPilote = idPilote;
        this->Rallye = rallye;
        this->Pilote = pilote;
        this->Categorie = categorie;
        this->TempsTotal = tempsTotal;
        this->Rank = rank;
        this->Points = points;
    }
    

    // Getters and Setters
    int Classement::getIdRallye() {
        return idRallye;
    }

    void Classement::setIdRallye(int idRallye) {
        this->idRallye = idRallye;
    }

    int Classement::getIdCategorie() {
        return idCategorie;
    }

    void Classement::setIdCategorie(int idCategorie) {
        this->idCategorie = idCategorie;
    }

    int Classement::getIdPilote() {
        return idPilote;
    }

    void Classement::setIdPilote(int idPilote) {
        this->idPilote = idPilote;
    }

    String^ Classement::getRallye() {
        return Rallye;
    }

    void Classement::setRallye(System::String^ Rallye) {
        this->Rallye = Rallye;
    }

    String^ Classement::getPilote() {
        return Pilote;
    }

    void Classement::setPilote(System::String^ Pilote) {
        this->Pilote = Pilote;
    }

    String^ Classement::getCategorie() {
        return Categorie;
    }

    void Classement::setCategorie(System::String^ Categorie) {
        this->Categorie = Categorie;
    }

    String^ Classement::getTempsTotal() {
        return TempsTotal;
    }

    void Classement::setTempsTotal(System::String^ TempsTotal) {
        this->TempsTotal = TempsTotal;
    }

    int Classement::getRank() {
        return Rank;
    }

    void Classement::setRank(int Rank) {
        this->Rank = Rank;
    }

    int Classement::getPoints() {
        return Points;
    }

    void Classement::setPoints(int Points) {
        this->Points = Points;
    }
    List<Classement^>^ Classement::getClassementGeneral(int idRallye) {
        List<Classement^>^ listClassement = gcnew List<Classement^>();
        SqlConnection^ connection = DataAccess::Connection::getConnection();

        try {
            connection->Open();
            String^ query = "SELECT * FROM classementGeneral WHERE idRallye = @idRallye";
            SqlCommand^ command = gcnew SqlCommand(query, connection);
            command->Parameters->AddWithValue("@idRallye", idRallye);

            SqlDataReader^ reader = command->ExecuteReader();

            while (reader->Read()) {
                // Assurez-vous que les index et les types correspondent à votre base de données
                int idRallye = reader->GetInt32(0);
                int idCategorie = reader->GetInt32(1);
                int idpilote = reader->GetInt32(2);
                String^ rallye = reader->GetString(3);
                String^ nompilote = reader->GetString(4);
                String^ categorie = reader->GetString(5);
                String^ tempsTotal = reader->GetString(6);
                int rank = reader->GetInt32(7);
                int points = reader->GetInt32(8);
                Classement^ classement = gcnew Classement(idRallye, idCategorie, idpilote, rallye, nompilote, categorie, tempsTotal, rank, points);
                listClassement->Add(classement);
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

        return listClassement;
    }


    
    List<Classement^>^ Classement::getClassementParCategorie(int idRallye, int idCategorie) {
        List<Classement^>^ listClassement = gcnew List<Classement^>();
        SqlConnection^ connection = DataAccess::Connection::getConnection();

        try {
            connection->Open();
            String^ query = "SELECT * FROM  ResultCategorie WHERE idRallye = @idRallye AND idCategorieRanked= @idCategorie";
            SqlCommand^ command = gcnew SqlCommand(query, connection);
            command->Parameters->AddWithValue("@idRallye", idRallye);
            command->Parameters->AddWithValue("@idCategorie", idCategorie);

            SqlDataReader^ reader = command->ExecuteReader();

            while (reader->Read()) {
                // Assurez-vous que les index et les types correspondent à votre base de données
                int idRallye = reader->GetInt32(0);
                int idCategorie = reader->GetInt32(1);
                int idpilote = reader->GetInt32(2);
                String^ rallye = reader->GetString(3);
                String^ nompilote = reader->GetString(4);
                String^ categorie = reader->GetString(5);
                String^ tempsTotal = reader->GetString(6);
                int rank = reader->GetInt32(7);
                int points = reader->GetInt32(8);
                Classement^ classement = gcnew Classement(idRallye, idCategorie, idpilote, rallye, nompilote, categorie, tempsTotal, rank, points);
                listClassement->Add(classement);
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

        return listClassement;
    }
  
}

