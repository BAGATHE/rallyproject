#pragma once

#include "Categorie.h"
#include <string>
namespace Model
{
    public ref class Pilote
    {
    private:
        int idPilote;
        System::String^ nom;
        Categorie^ categorie;

    public:
        // Constructeur par d�faut
        Pilote();

        // Constructeur avec param�tres
        Pilote(int id, System::String^ nom, Categorie^ cat);

        // Getter pour idPilote
        int getIdPilote();

        // Setter pour idPilote
        void setIdPilote(int id);

        // Getter pour nom
        System::String^ getNom();

        // Setter pour nom
        void setNom(System::String^ nom);

        // Getter pour categorie
        Categorie^ getCategorie();

        // Setter pour categorie
        void setCategorie(Categorie^ cat);
    };
}
