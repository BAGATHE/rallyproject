#include "connection.h"
using namespace System::Data::SqlClient;
namespace DataAccess
{
    SqlConnection^ Connection::getConnection()
    {
        // Définir la chaîne de connexion à la base de données SQL Server
        String^ connectionString = "Data Source=localhost\\SQLEXPRESS01; Database=rallye_project ; Integrated Security=True";

        try
        {
            // Créer une instance de SqlConnection en utilisant la chaîne de connexion
            SqlConnection^ connection = gcnew SqlConnection(connectionString);
            // Retourner la connexion
            return connection;
        }
        catch (SqlException^ e)
        {
            // Gérer les exceptions SQL
            Console::WriteLine("Error connecting to SQL Server: {0}", e);
            return nullptr;
        }
    }
}
