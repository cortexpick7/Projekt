#include <iostream>
#include <windows.h>
#include "first_screen.h"
#include "justify_text.hpp"
#include "log_in.h"
#include "read_csv.h"
#include "user_office.h"
#include "admin_panel.h"
#include "table_of_books.h"

using namespace tableOfBooks;
using namespace adminPanel;
using namespace userScreen;
using namespace readCSV;
using namespace justifyText;
using namespace firstScreen;
using namespace std;
using namespace logInScreen;

int main()
{
    /// Vytváření proměnných
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    readCSVs readCSVs;
    user_screen userScreen;
    first_screen firstScreen;
    log_in logInScreen;
    admin_panel admin_panel;
    table_of_books table_of_books;
    string titul = ">>>>> Administracni panel knihovny <<<<<";
    string jedna = "1. Admin panel";
    string dva = "2. Regal";
    string tri = "3. Administracni panel uzivatele";
    string jmenoUzivatele;
    int mainScreen = 1;
    int udalostGeneral = 0;
    int udalostSmall = 0;


    while (mainScreen == 1) {
        switch(udalostGeneral) {
        case 1: {   ///Panel administrátora
                string heslo;
                logInScreen.show_login_screen("ADMIN");
                cout << "Vase heslo: ";                                                     /// Administrátor může přidávat a odstraňovat knihy z kartotéky
                cin >> heslo;                                                               /// a přidávat do systému nové uživatele.

                while (heslo != "1234") {
                    cout << "Vase heslo: ";
                    cin >> heslo;
                }
                system("CLS");
                int udalostInside = 0;
                while (udalostInside == 0) {
                    admin_panel.show();
                    cout << "Zvolte udalost: ";
                    cin >> udalostInside;
                    cout << endl;
                }
                switch(udalostInside) {
                case 1:
                {
                    string name, author;
                    cout << "Jmeno autora/ky: ";
                    std::getline(std::cin >> std::ws, author);
                    cout << endl;
                    cout << "Nazev knihy: ";
                    std::getline(std::cin >> std::ws, name);
                    cout << endl;
                    readCSVs.addBook(name, author);
                    cout << "Kniha byla pridana!";
                    cout << endl;
                    cout << "Zvolte dalsi udalost: ";
                    cout << endl;
                    cout << "(1) Vratit se na hlavni stranku.";
                    cout << endl;
                    cout << "(2) Zpet do administrativy.";
                    cout << endl;
                    cout << "(3) Ukoncit prace.";
                    cout << endl;
                    cin >> udalostSmall;
                    switch(udalostSmall) {
                        case 1:
                            {
                                system("CLS");
                                udalostGeneral = 0;
                                break;
                            }
                        case 2:
                            {
                                system("CLS");
                                udalostGeneral = 1;
                                break;
                            }
                        case 3:
                            {
                                system("CLS");
                                mainScreen = 0;
                                break;
                            }
                        default:
                        {
                            system("CLS");
                            mainScreen = 0;
                            break;
                        }
                    }
                    name = "";
                    author = "";
                    break;
                }
                case 2:
                    {
                        string id;
                        table_of_books.show();
                        cout << "Uvedte ID knihy: ";
                        cin >> id;
                        readCSVs.deleteBook(id);
                        cout << "Kniha byla odtranena!" << endl;
                        cout << "Zvolte dalsi udalost: " ;
                        cout << "Zvolte dalsi udalost: ";
                        cout << endl;
                        cout << "(1) Vratit se na hlavni stranku.";
                        cout << endl;
                        cout << "(2) Zpet do administrativy.";
                        cout << endl;
                        cout << "(3) Ukoncit prace.";
                        cout << endl;
                        cin >> udalostSmall;
                        switch(udalostSmall) {
                        case 1:
                            {
                                system("CLS");
                                udalostGeneral = 0;
                                break;
                            }
                        case 2:
                            {
                                system("CLS");
                                udalostGeneral = 1;
                                break;
                            }
                        case 3:
                            {
                                system("CLS");
                                mainScreen = 0;
                                break;
                            }
                        }
                        break;
                    }
                case 3:
                    {
                        string name, password;
                        cout << "Uvedte jmeno uzivatele: ";
                        cin >> name;
                        cout << endl;
                        cout << "Uvedte heslo uzivatele: ";
                        cin >> password;
                        cout << endl;
                        readCSVs.addUser(name, password);
                        cout << "Uzvitael pridan do systemu!" << endl;
                        cout << "Zvolte dalsi udalost: ";
                        cout << endl;
                        cout << "(1) Vratit se na hlavni stranku.";
                        cout << endl;
                        cout << "(2) Zpet do administrativy.";
                        cout << endl;
                        cout << "(3) Ukoncit prace.";
                        cout << endl;
                        cin >> udalostSmall;
                        switch(udalostSmall) {
                        case 1:
                            {
                                system("CLS");
                                udalostGeneral = 0;
                                break;
                            }
                        case 2:
                            {
                                system("CLS");
                                udalostGeneral = 1;
                                break;
                            }
                        case 3:
                            {
                                system("CLS");
                                mainScreen = 0;
                                break;
                            }
                        default:
                        {
                            system("CLS");
                            mainScreen = 0;
                            break;
                        }
                        }
                            break;
                    }

                }
                break;
            }
        case 2: {   ///Regál s knihami
            string input;                                                       ///V této části se zobrazují všechny knihy, které jsou v knihovně.
            table_of_books.show();
            cout << "Uvedte cokoliv pro vraceni na hlavni stranku: ";
            cin >> input;
            system("CLS");
            udalostGeneral = 0;
            break;
        }
        case 3: {   ///Uživatelský panel
            string user, password;
            cout << "Vase uzivatelske jmeno: ";
            cout << endl;
            cin >> user;                                                        ///Uživateli se zobrazí seznam knih, které má vypůjčené
            while (readCSVs.readUsernames(user) != true) {                      ///může vypůjčenou knihu vrátit nebo si vypůjčit novou.
                SetConsoleTextAttribute(h, 5);
                cout << "Nespravne jmeno uzivatele!" << endl;
                SetConsoleTextAttribute(h, 15);
                cout << "Vase uzivatelske jmeno: ";
                cin >> user;
                cout << endl;
            }
            logInScreen.show_login_screen(user);
            cout << "Vase heslo: ";
            cout << endl;
            cin >> password;
            while(readCSVs.readPasswords(password, user) != true) {
                SetConsoleTextAttribute(h, 5);
                cout << "Nespravne heslo!" << endl;
                SetConsoleTextAttribute(h, 15);
                cout << "Vase heslo: ";
                cin >> password;
                cout << endl;
            }
            int udalost3 = 0;
            string id;
            userScreen.show(user);
            cout << "Vyberte dalsi operace: " << endl;
            cout << "(1) Pronajem knihy. " << endl;
            cout << "(2) Vraceni knihy. " << endl;
            cout << "(3) Zpet na hlavni stranku. " << endl;

            cin >> udalost3;
            while (udalost3 != 3) {
                if (udalost3 == 1)
                {
                    table_of_books.show();
                    cout << "Vyberte knihu dle id" << endl;
                    cin >> id;
                    readCSVs.bookRental(1, id, user);
                    SetConsoleTextAttribute(h, 2);
                    cout << "Kniha pronajata!" << endl;
                    SetConsoleTextAttribute(h, 15);
                    userScreen.show(user);
                    cout << "Vyberte dalsi operace: " << endl;
                    cout << "(1) Pronajem knihy. " << endl;
                    cout << "(2) Vraceni knihy. " << endl;
                    cout << "(3) Zpet na hlavni stranku. " << endl;
                    cin >> udalost3;
                } else if (udalost3 == 2) {
                    userScreen.show(user);
                    cout << "Vyberte knihu dle id" << endl;
                    cin >> id;
                    readCSVs.bookRental(2, id, user);
                    SetConsoleTextAttribute(h, 2);
                    cout << "Kniha vracena!" << endl;
                    SetConsoleTextAttribute(h, 15);
                    userScreen.show(user);
                    cout << "Vyberte dalsi operace: " << endl;
                    cout << "(1) Pronajem knihy. " << endl;
                    cout << "(2) Vraceni knihy. " << endl;
                    cout << "(3) Zpet na hlavni stranku. " << endl;
                    cin >> udalost3;
                }
            }
            system("CLS");
            udalost3 = 0;
            udalostGeneral = 0;
            userScreen.show(user);
            break;
        }
        default: {
                system("CLS");
                firstScreen.show_screen(titul, jedna, dva, tri);
                cout << "Zvolte udalost: ";
                cin >> udalostGeneral;
                break;
            }
        }
    }
    return 0;
}

