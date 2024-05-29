#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;

int main(array<System::String^>^ args)
{
    // Initialise l'application Windows Forms
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    // Crée une instance de MyForm et l'affiche
    rallyecpp::MyForm^ form = gcnew rallyecpp::MyForm();
    Application::Run(form);

    return 0;
}
