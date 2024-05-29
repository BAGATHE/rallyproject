#include "connection.h"
using namespace System::Data::SqlClient;
namespace DataAccess
{
    SqlConnection^ Connection::getConnection()
    {
        // D�finir la cha�ne de connexion � la base de donn�es SQL Server
        String^ connectionString = "Data Source=localhost\\SQLEXPRESS01; Database=rallye_project ; Integrated Security=True";

        try
        {
            // Cr�er une instance de SqlConnection en utilisant la cha�ne de connexion
            SqlConnection^ connection = gcnew SqlConnection(connectionString);
            // Retourner la connexion
            return connection;
        }
        catch (SqlException^ e)
        {
            // G�rer les exceptions SQL
            Console::WriteLine("Error connecting to SQL Server: {0}", e);
            return nullptr;
        }
    }
}
