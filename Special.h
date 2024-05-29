#pragma once

#include <string>
#include <vector>
#include "Course.h"
using namespace System::Collections::Generic;

namespace Model
{
    public ref class Special
    {
    private:
        int idSpecial;
        System::String^ intituler;
        List<Course^>^ courses;

    public:
        // Constructeur avec param�tres
        Special(int idSpecial, System::String^ intituler);

        // M�thode pour ajouter une Course � la liste
        void addCourse(Course^ course);

        // Getter pour idSpecial
        int getIdSpecial();

        // Getter pour intituler
        System::String^ getIntituler();

        // Getter pour la liste de courses
        List<Course^>^ getCourses();

        static List<Special^>^ getAllSpecials();
    };
}

