#include "Special.h"
#include "Connection.h"
#include "Course.h"

using namespace System;
using namespace System::Data;
using namespace System::Collections::Generic;
using namespace System::Data::SqlClient;
using namespace System::Windows::Forms;
using namespace DataAccess;
namespace Model
{
    // Constructeur avec paramètres
    Special::Special(int idSpecial, System::String^ intituler)
    {
        this->idSpecial = idSpecial;
        this->intituler = intituler;
        this->courses = gcnew List<Course^>();
    }

    // Méthode pour ajouter une Course à la liste
    void Special::addCourse(Course^ course)
    {
        courses->Add(course);
    }

    // Getter pour idSpecial
    int Special::getIdSpecial()
    {
        return idSpecial;
    }

    // Getter pour intituler
    System::String^ Special::getIntituler()
    {
        return intituler;
    }

    // Getter pour la liste de courses
    List<Course^>^ Special::getCourses()
    {
        return courses;
    }

    List<Special^>^ Special::getAllSpecials()
    {
        List<Special^>^ listSpecial = gcnew List<Special^>();

        SqlConnection^ connection = DataAccess::Connection::getConnection();

        try {
            connection->Open();
            String^ query = "SELECT * FROM Special";
            SqlCommand^ command = gcnew SqlCommand(query, connection);
            SqlDataReader^ reader = command->ExecuteReader();

            while (reader->Read()) {
                Special^ special = gcnew Special(reader->GetInt32(0),reader->GetString(1));
                listSpecial->Add(special);
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

        return listSpecial;
    }



}
