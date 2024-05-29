#include "Pilote.h"

namespace Model
{
    // Constructeur par défaut
    Pilote::Pilote()
    {
        // Initialisez les membres de votre classe ici si nécessaire
        idPilote = 0;
        nom = nullptr;
        categorie = gcnew Categorie();
    }

    // Constructeur avec paramètres
    Pilote::Pilote(int id, System::String^ nom, Categorie^ cat)
    {
        idPilote = id;
        this->nom = nom;
        categorie = cat;
    }

    // Getter pour idPilote
    int Pilote::getIdPilote()
    {
        return idPilote;
    }

    // Setter pour idPilote
    void Pilote::setIdPilote(int id)
    {
        idPilote = id;
    }

    // Getter pour nom
    System::String^ Pilote::getNom()
    {
        return nom;
    }

    // Setter pour nom
    void Pilote::setNom(System::String^ nom)
    {
        this->nom = nom;
    }

    // Getter pour categorie
    Categorie^ Pilote::getCategorie()
    {
        return categorie;
    }

    // Setter pour categorie
    void Pilote::setCategorie(Categorie^ cat)
    {
        categorie = cat;
    }
}
