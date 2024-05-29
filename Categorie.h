#pragma once

#include <string>

namespace Model
{
    public ref class Categorie
    {
    private:
        int idCategorie;
        System::String^ intituler;

    public:
        // Constructeur par défaut
        Categorie();

        // Constructeur avec paramètres
        Categorie(int id, System::String^ intitule);

        // Getter pour idCategorie
        int getIdCategorie();

        // Setter pour idCategorie
        void setIdCategorie(int id);

        // Getter pour intituler
        System::String^ getIntituler();

        // Setter pour intituler
        void setIntituler(System::String^ intitule);
    };
}

