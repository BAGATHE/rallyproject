#pragma once
#include <string>
#include "Rallye.h"
using namespace System::Collections::Generic;

namespace Model
{
    public ref class Saison
    {
    private:
        int idSaison;
        int annee;
        List<Rallye^>^ rallyes;

    public:
        // Constructeur avec param�tres
        Saison(int idSaison, int annee);

        // M�thode pour ajouter un Rallye � la liste
        void addRallye(Rallye^ rallye);

        // Getter pour idSaison
        int getIdSaison();

        // Getter pour annee
        int getAnnee();

        // Getter pour la liste de Rallye
        List<Rallye^>^ getRallyes();

        // M�thode pour obtenir toutes les saisons depuis la base de donn�es
        static List<Saison^>^ getAllSaisons();
    };
}
