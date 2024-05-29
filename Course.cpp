#include "Course.h"
#include "Connection.h"
using namespace System;
using namespace System::Data;
using namespace System::Collections::Generic;
using namespace System::Data::SqlClient;
using namespace System::Windows::Forms;
using namespace DataAccess;

namespace Model
{
    // Constructeur par défaut
    Course::Course()
    {
        // Initialisez les membres de votre classe ici si nécessaire
        idCourse = 0;
        idSaison = 0;
        idRallye = 0;
        idSpecial = 0;
        pilote = nullptr;
        chronometre = nullptr;
    }

    // Constructeur avec paramètres
    Course::Course(int idCourse,int idSaison ,int idRallye, int idSpecial, Pilote^ pilote, System::String^ chronometre)
    {
        this->idCourse = idCourse;
        this->idSaison = idSaison;
        this->idRallye = idRallye;
        this->idSpecial = idSpecial;
        this->pilote = pilote;
        this->chronometre = chronometre;
    }

    // Getter pour idCourse
    int Course::getIdCourse()
    {
        return idCourse;
    }

    // Setter pour idCourse
    void Course::setIdCourse(int id)
    {
        idCourse = id;
    }

    // Getter pour idSaison
    int Course::getIdSaison()
    {
        return idSaison;
    }

    // Setter pour idSaison
    void Course::setIdSaison(int id)
    {
        idSaison = id;
    }

    // Getter pour idRallye
    int Course::getIdRallye()
    {
        return idRallye;
    }

    // Setter pour idRallye
    void Course::setIdRallye(int id)
    {
        idRallye = id;
    }

    // Getter pour idSpecial
    int Course::getIdSpecial()
    {
        return idSpecial;
    }

    // Setter pour idSpecial
    void Course::setIdSpecial(int id)
    {
        idSpecial = id;
    }

    // Getter pour pilote
    Pilote^ Course::getPilote()
    {
        return pilote;
    }

    // Setter pour pilote
    void Course::setPilote(Pilote^ pilote)
    {
        this->pilote = pilote;
    }

    // Getter pour chronometre
    String^ Course::getChronometre()
    {
        return chronometre;
    }

    // Setter pour chronometre
    void Course::setChronometre(String^ chrono)
    {
        chronometre = chrono;
    }
    void Course::insert_course(int idSaison,int idRallye,int idSpecial, int idPilote, String^ chrono) {
        SqlConnection^ connection = DataAccess::Connection::getConnection();

        try {
            connection->Open();
            String^ query = "INSERT INTO Course (idSaison, idRallye, idSpecial, idPilote, chrono) VALUES (@idSaison,@idRallye, @idSpecial, @idPilote, @chrono)";

            SqlCommand^ command = gcnew SqlCommand(query, connection);
            command->Parameters->AddWithValue("@idSaison", idSaison);
            command->Parameters->AddWithValue("@idRallye", idRallye);
            command->Parameters->AddWithValue("@idSpecial", idSpecial);
            command->Parameters->AddWithValue("@idPilote", idPilote);
            command->Parameters->AddWithValue("@chrono", chrono);

            command->ExecuteNonQuery();

            MessageBox::Show("Course insérée avec succès", "Message", MessageBoxButtons::OK, MessageBoxIcon::Information);
        }
        catch (Exception^ ex) {
            MessageBox::Show("Erreur lors de l'insertion de la Course : " + ex->Message, "Message", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
        finally {
            if (connection->State == ConnectionState::Open) {
                connection->Close();
            }
        }
    }

}
