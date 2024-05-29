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
        // Constructeur avec paramètres
        Saison(int idSaison, int annee);

        // Méthode pour ajouter un Rallye à la liste
        void addRallye(Rallye^ rallye);

        // Getter pour idSaison
        int getIdSaison();

        // Getter pour annee
        int getAnnee();

        // Getter pour la liste de Rallye
        List<Rallye^>^ getRallyes();

        // Méthode pour obtenir toutes les saisons depuis la base de données
        static List<Saison^>^ getAllSaisons();
    };
}
