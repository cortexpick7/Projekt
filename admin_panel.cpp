#include "admin_panel.h"
#include <iostream>
#include "first_screen.h"

using namespace firstScreen;
using namespace adminPanel;
using namespace std;

void admin_panel::show()
{
    ///Grafika panelu administrátora
    first_screen first_screen;
    string titul = ">>>>> Administracni panel <<<<<";
    string jedna = "1. Pridat knihu";
    string dva = "2. Odstranit knihu";
    string tri = "3. Pridat uzivatele";
    first_screen.show_screen(titul, jedna, dva, tri);
}
