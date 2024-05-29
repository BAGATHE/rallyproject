#pragma once

#include "Pilote.h"
using namespace System;
namespace Model
{
    public ref class Course
    {
    private:
        int idCourse;
        int idSaison;
        int idRallye;
        int idSpecial;
        Pilote^ pilote;
        System::String^ chronometre;

    public:
        // Constructeur par défaut
        Course();

        // Constructeur avec paramètres
        Course(int idCourse,int Saison,int idRallye, int idSpecial, Pilote^ pilote, System::String^ chronometre);

        // Getter pour idCourse
        int getIdCourse();

        // Setter pour idCourse
        void setIdCourse(int id);
        // Getter pour idRallye
        int getIdSaison();

        // Setter pour idRallye
        void setIdSaison(int id);

        // Getter pour idRallye
        int getIdRallye();

        // Setter pour idRallye
        void setIdRallye(int id);

        // Getter pour idSpecial
        int getIdSpecial();

        // Setter pour idSpecial
        void setIdSpecial(int id);

        // Getter pour pilote
        Pilote^ getPilote();

        // Setter pour pilote
        void setPilote(Pilote^ pilote);

        // Getter pour chronometre
        System::String^ getChronometre();

        // Setter pour chronometre
        void setChronometre(System::String^ chrono);

        //Insertion Course
        static void insert_course(int idSaison,int idRallye, int idSpecial, int idPilote, String^ chrono);
    };
}
