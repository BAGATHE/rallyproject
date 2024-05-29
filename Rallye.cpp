#include "Rallye.h"
#include "Special.h"
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
    Rallye::Rallye(int idRallye,String^ intituler)
    {
        this->idRallye = idRallye;
        this->intituler = intituler;
        this->specials = gcnew List<Special^>();
    }

    // Méthode pour ajouter un Special à la liste
    void Rallye::addSpecial(Special^ special)
    {
        specials->Add(special);
    }

    // Getter pour idRallye
    int Rallye::getIdRallye()
    {
        return idRallye;
    }

    // Getter pour intituler
    System::String^ Rallye::getIntituler()
    {
        return intituler;
    }

    // Getter pour la liste de Special
    List<Special^>^ Rallye::getSpecials()
    {
        return specials;
    }

    List<Rallye^>^ Rallye::getAllRallyes() {
        List<Rallye^>^ listRallye = gcnew List<Rallye^>();

        SqlConnection^ connection = DataAccess::Connection::getConnection();

        try {
            connection->Open();
            String^ query = "SELECT * FROM Rallye";
            SqlCommand^ command = gcnew SqlCommand(query, connection);
            SqlDataReader^ reader = command->ExecuteReader();

            while (reader->Read()) {
                Rallye^ rallye = gcnew Rallye(reader->GetInt32(0),reader->GetString(1));
                listRallye->Add(rallye);
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

        return listRallye;
    }


}
