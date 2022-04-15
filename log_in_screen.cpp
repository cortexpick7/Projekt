#include "log_in.h"
#include <iostream>
#include "justify_text.hpp"

using namespace justifyText;
using namespace logInScreen;
using namespace std;

int log_in::show_login_screen(string a)
{
    ///Šablona přihlašovací stránky
    justify_text jc;
    int middle = 35;
    system("CLS");
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    string titul = ">>>>> Autorizace <<<<<";
    string jmeno = ">>>>> Uzivatelske jmeno: ";
    string password = ">>>>> Pin: ";
    string user = a;
    string zaverky = " <<<<<";
    string pass = "****";
    for (int i = 1; i <= 18; i++) {
        switch(i) {
        case 1:
            {
                for (int j = 1; j <= 70; j++) {
                    cout << "-";
                }
                cout << endl;
                break;
            }
        case 6:
            {
                int a = jc.justify_center(middle, titul);
                for (int p = 1; p <= 70; p++) {
                    if (p == a) {
                        SetConsoleTextAttribute(h, 3);
                        cout << titul;
                        SetConsoleTextAttribute(h, 15);
                        p = titul.length() + + a - 1;
                    } else if (p == 1 || p == 70) {
                        cout << "|";
                    } else {
                         cout << " ";
                    }
                }
                cout << endl;
                break;
            }
        case 9:
            {
                string celeJmeno = jmeno + user + zaverky;
                int a = jc.justify_center(middle, celeJmeno);
                for (int p = 1; p <= 70; p++) {
                    if (p == a) {

                        cout << jmeno;
                        SetConsoleTextAttribute(h, 4);
                        cout << user;
                        SetConsoleTextAttribute(h, 15);
                        cout << zaverky;
                        p = celeJmeno.length() + a - 1;
                    } else if (p == 1 || p == 70) {
                        cout << "|";
                    } else {
                         cout << " ";
                    }
                }
                cout << endl;
                break;
            }
        case 11:
            {
                string celeHeslo = password + pass + zaverky;
                int a = jc.justify_center(middle, celeHeslo);
                for (int p = 1; p <= 70; p++) {
                    if (p == a) {
                        cout << password;
                        SetConsoleTextAttribute(h, 4);
                        cout << pass;
                        SetConsoleTextAttribute(h, 15);
                        cout << zaverky;
                        p = celeHeslo.length() + a - 1;
                    } else if (p == 1 || p == 70) {
                        cout << "|";
                    } else {
                         cout << " ";
                    }
                }
                cout << endl;
                break;
            }
        case 18:
            {
                for (int k = 1; k <= 70; k++) {
                    cout << "-";
                }
                cout << endl;
            }
        default:
            {
                for (int x = 1; x <= 70; x++) {
                    if (x == 1 || x == 70) {
                        cout << "|";
                    } else {
                        cout << " ";
                    }
                }
                cout << endl;
                break;
            }
        }
    }
    return 0;
}



