#include "Categorie.h"

namespace Model
{
    // Constructeur par d�faut
    Categorie::Categorie()
    {
        // Initialisez les membres de votre classe ici si n�cessaire
        idCategorie = 0;
        intituler = nullptr;
    }

    // Constructeur avec param�tres
    Categorie::Categorie(int id, System::String^ intitule)
    {
        idCategorie = id;
        intituler = intitule;
    }

    // Getter pour idCategorie
    int Categorie::getIdCategorie()
    {
        return idCategorie;
    }

    // Setter pour idCategorie
    void Categorie::setIdCategorie(int id)
    {
        idCategorie = id;
    }

    // Getter pour intituler
    System::String^ Categorie::getIntituler()
    {
        return intituler;
    }

    // Setter pour intituler
    void Categorie::setIntituler(System::String^ intitule)
    {
        intituler = intitule;
    }
}
