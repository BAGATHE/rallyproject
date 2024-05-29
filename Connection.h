#pragma once

using namespace System;
using namespace System::Data::SqlClient;

namespace DataAccess
{
    public ref class Connection
    {
    public:
       static SqlConnection^ getConnection();
    };
}
