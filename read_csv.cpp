#include <iostream>
#include <fstream>
#include "read_csv.h"
#include <sstream>
#include "justify_text.hpp"
#include <string>
#include "first_screen.h"
#include <stdio.h>
#include <mutex>

using namespace firstScreen;
using namespace justifyText;
using namespace std;
using namespace readCSV;

bool readCSVs::readPasswords(string pass, string user)
{
    ifstream ip("./database/usersPasswords.csv");

    if(!ip.is_open()) return false;
    string line, userName, passWord;

    while(ip.good())                                                                    /// Ověřování hesla true = Správné heslo
    {                                                                                   ///                 false = Nesprávné heslo
        getline(ip, line);
        stringstream s(line);
        getline(s, userName, ';');
        getline(s, passWord, '\n');
        if (user == userName) {
            if (pass == passWord) {
                return true;
                ip.close();
            } else {
                continue;
            }
        }
    }
    return false;
    ip.close();
}

bool readCSVs::readUsernames(string user)
{
    ifstream ip("./database/usersPasswords.csv");                                                               /// Vyhledání uživatele v systému  true = Uživatel v systému
                                                                                                                ///                                false = Uživatel není v systému
    if(!ip.is_open()) cout << "ERROR: nepovedlo se otevrit";
    string line, userName, passWord;

    while(ip.good())
    {
        getline(ip, line);
        stringstream s(line);
        getline(s, userName, ';');
        getline(s, passWord, '\n');
            if (user == userName) {
                return true;
                ip.close();
            } else {
                continue;
            }
    }
    return false;
    ip.close();
}

bool readCSVs::getAllBooks() {
    justify_text jc;
    ifstream ip("./database/books.csv");                                                    //nahrat tabule ze vsemi knihama  true = knihy nahrany
    if(!ip.is_open()) return false;                                                         //                                false = nepovedlo se otevrit soubor
    string line, author, name, id, status, uzivatel;

    while(ip.good())
    {
        HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
        line = "";
        author = "";
        name = "";
        id = "";
        getline(ip, line);
        stringstream s(line);
        getline(s, author, ';');
        getline(s, name, ';');
        getline(s, id, ';');
        getline(s, status, ';');
        getline(s, uzivatel, '\n');
        if (id != "") {
            for (int i = 1; i <= 70; i++)
            {
                string bookInfo = "|" + id + "|----|" + author + "|----|" + name + "|----|";
                if (i == 1 || i == 70) {
                    cout << "|";
                } else if ( i == 2) {
                    cout << bookInfo;
                if (status == "pronajato") {
                    SetConsoleTextAttribute(h, 4);
                    cout << status;
                    SetConsoleTextAttribute(h, 15);
                } else {
                    SetConsoleTextAttribute(h, 2);
                    cout << status;
                    SetConsoleTextAttribute(h, 15);
                }
                i = bookInfo.length() + status.length() + 2;
                    cout << "|";
                } else {cout << "-";}
            }
            cout << endl;
            for (int i = 1; i <= 70; i++)
            {
                cout << "-";
                if (i == 70) {
                    cout << endl;
                    break;
                }
            }
        }

    }
    ip.close();
    return true;
}

int readCSVs::getLastBookId() {
    int lastRow;
    ifstream ip("./database/books.csv");                                    /// Získat ID posledního prvku, aby bylo možné přiřadit ID novému prvku.
    if(!ip.is_open()) return 0;                                             /// Nelze otevřít soubor
    string line, author, name, id, status, uzivatel;                        /// vrací ID poslední položky v databázi
    while(ip.good())
    {
        getline(ip, author, ';');
        getline(ip, name, ';');
        getline(ip, id, ';');
        getline(ip, status, ';');
        getline(ip, uzivatel, '\n');

        stringstream ss;
        ss << id;
        ss >> lastRow;
    }
    ip.close();
    return lastRow;
}

bool readCSVs::addBook(string name, string author) {
    ofstream ip;                                                                              /// Přidání knihy do databáze
    ip.open("./database/books.csv", fstream::app | fstream::out);                             /// true - kniha přidána, false - nepodařilo se přidat
    if(!ip.is_open()) return false;
    string status, uzivatel;
    uzivatel = "nikdo";
    status = "Volno";
    int a = getLastBookId() + 1;
    stringstream ss;
    ss << a;
    string id = ss.str();
    string fullLine = author + ";" + name + ";" + id + ";" + status + ";" + uzivatel + "\n";
    ip << fullLine;
    ip.close();
    return true;
}

bool readCSVs::deleteBook(string bookId) {
    remove("./database/books1.csv");
    string fullLine, fullLine1, author, name, id, status, uzivatel, line;
    fstream ip;
    fstream op;                                                                                        /// Odstraní vybranou knihu podle ID
    ip.open("./database/books.csv");
    op.open("./database/books1.csv", ofstream::out);

    if(!ip.is_open()) {
        return false;
    }
    while(ip.good())
    {
        getline(ip, line);
        stringstream s(line);
        getline(s, author, ';');
        getline(s, name, ';');
        getline(s, id, ';');
        getline(s, status, ';');
        getline(s, uzivatel, '\n');
        stringstream ss, sss;
        int idInt, bookIdInt;
        ss << id;
        sss << bookId;
        ss >> idInt;
        sss >> bookIdInt;
        if (author != "") {
            if (idInt != bookIdInt) {
            string fullLine = author + ";" + name + ";" + id + ";" + status + ";" + uzivatel + "\n";
            op << fullLine;
            } else {
            cout << "deleted" << endl;
        }
        }

    }
    ip.close();
    remove("./database/books.csv");
    op.close();
    rename("./database/books1.csv", "./database/books.csv");

    return true;
}

bool readCSVs::bookRental(int operation, string bookId, string uzivatelskeJmeno) {
    string fullLine, author, name, id, status, uzivatel, line;
    fstream ip, iip; //write
    fstream op, oop; //read
    remove("./database/books1.csv");
    op.open("./database/books.csv");                                                                    /// Pronajme knihu(operace = 1) nebo ji vrátí(operace = 2)
    ip.open("./database/books1.csv", fstream::app | fstream::out);

    if(!op.is_open()) {
        return false;
    }
     while(op.good())
    {
        getline(op, line);
        stringstream s(line);
        getline(s, author, ';');
        getline(s, name, ';');
        getline(s, id, ';');
        getline(s, status, ';');
        getline(s, uzivatel, '\n');
        stringstream ss, sss;
        int idInt, bookIdInt;
        ss << id;
        sss << bookId;
        ss >> idInt;
        sss >> bookIdInt;
        if (operation == 1) {
            if (author != "") {
                if (idInt == bookIdInt) {
                    string fullLine = author + ";" + name + ";" + id + ";pronajato;" + uzivatelskeJmeno + "\n";
                    ip << fullLine;
                } else {
                    string fullLine = author + ";" + name + ";" + id + ";" + status + ";" + uzivatel + "\n";
                    ip << fullLine;
                }
            }
        } else if (operation == 2) {
            if (author != "") {
                if (idInt == bookIdInt) {
                    string fullLine = author + ";" + name + ";" + id + ";volno;nikdo\n";
                    ip << fullLine;
                } else {
                    string fullLine = author + ";" + name + ";" + id + ";" + status + ";" + uzivatel + "\n";
                    ip << fullLine;
                }
            }
        } else {
            return false;
        }
    }
        op.close();
        ip.close();
        remove("./database/books.csv");
        rename("./database/books1.csv", "./database/books.csv");
        return true;
}


bool readCSVs::getRentedBooks(string inputUzivatel) {
    justify_text jc;
    ifstream ip("./database/books.csv");                                                    /// Zobrazí seznam knih, které si uživatel vypůjčil.
    if(!ip.is_open()) return false;
    string line, author, name, id, status, uzivatel;
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    int count = 0;
    while(ip.good())
    {
        getline(ip, line);
        stringstream s(line);
        getline(s, author, ';');
        getline(s, name, ';');
        getline(s, id, ';');
        getline(s, status, ';');
        getline(s, uzivatel, '\n');

        if (uzivatel == inputUzivatel) {
            count++;
            string bookInfo = "-|" + id + "|----|" + author + "|----|" + name + "|----";
            for (int i = 1; i <= 70; i++)
            {

                if (i == 1 || i == 70) {
                    cout << "|";
                } else if ( i == 2) {
                    cout << bookInfo;
                i = bookInfo.length() + 1;
                } else {cout << "-";}
            }
            cout << endl;
            for (int i = 1; i <= 70; i++)
            {
                cout << "-";
                if (i == 70) {
                    cout << endl;
                }
            }
        }
    }
    ip.close();
     if (count == 0) {
            return false;
    }
    return true;
}



bool readCSVs::addUser(string name, string password) {
    ofstream ip("./database/usersPasswords.csv", std::ofstream::out | std::ofstream::app);  ///Přidání uživatele do systému
    if(!ip.is_open()) return false;
    string fullString = name + ";" + password + "\n";
    ip << fullString;
    ip.close();
    return true;
}

bool readCSVs::doesUserHasBooks(string user) {
    ifstream ip("./database/books.csv");                            /// Kontrola, zda má uživatel pronajaté knihy
    if(!ip.is_open()) return false;
    string line, author, name, id, status, uzivatel;
    int count = 0;
    while(ip.good())
    {
        getline(ip, line);
        stringstream s(line);
        getline(s, author, ';');
        getline(s, name, ';');
        getline(s, id, ';');
        getline(s, status, ';');
        getline(s, uzivatel, '\n');
        if (uzivatel == user) {
            count++;
        }
    }
    ip.close();
    if (count == 0) {
        return false;
    } else {
        return true;
    }
}
