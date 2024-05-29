#pragma once

#include <string>
#include "Connection.h"

using namespace System;
using namespace System::Data;
using namespace System::Collections::Generic;
using namespace System::Data::SqlClient;
using namespace System::Windows::Forms;

namespace Model {
    public ref class Classement {
    private:
        int idRallye;
        int idCategorie;
        int idPilote;
        System::String^ Rallye;
        System::String^ Pilote;
        System::String^ Categorie;
        System::String^ TempsTotal;
        int Rank;
        int Points;

    public:
        // Constructor
        Classement(int idRallye, int idCategorie, int idPilote, System::String^ Rallye,
            System::String^ Pilote, System::String^ Categorie, System::String^ TempsTotal,
            int Rank, int Points);

        // Getters and Setters
        int getIdRallye();
        void setIdRallye(int idRallye);

        int getIdCategorie();
        void setIdCategorie(int idCategorie);

        int getIdPilote();
        void setIdPilote(int idPilote);

        System::String^ getRallye();
        void setRallye(System::String^ Rallye);

        System::String^ getPilote();
        void setPilote(System::String^ Pilote);

        System::String^ getCategorie();
        void setCategorie(System::String^ Categorie);

        System::String^ getTempsTotal();
        void setTempsTotal(System::String^ TempsTotal);

        int getRank();
        void setRank(int Rank);

        int getPoints();
        void setPoints(int Points);

        static List<Classement^>^ getClassementGeneral(int idRallye);
        static List<Classement^>^ getClassementParCategorie(int idRallye, int idCategorie);
    };
}

