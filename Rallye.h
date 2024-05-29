#pragma once

#include <string>
#include <vector>
#include "Special.h"
using namespace System::Collections::Generic;

namespace Model
{
    public ref class Rallye
    {
    private:
        int idRallye;
        int idSaison;
        System::String^ intituler;
        List<Special^>^ specials;

    public:
        // Constructeur avec param�tres
        Rallye(int idRallye, System::String^ intituler);

        // M�thode pour ajouter un Special � la liste
        void addSpecial(Special^ special);

        // Getter pour idRallye
        int getIdRallye();

        // Getter pour intituler
        System::String^ getIntituler();

        // Getter pour la liste de Special
        List<Special^>^ getSpecials();

        //liste de Rallye dans la base
        static List<Rallye^>^ getAllRallyes();
    };
}
