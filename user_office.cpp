#include "user_office.h"
#include <iostream>
#include "justify_text.hpp"
#include "read_csv.h"

using namespace readCSV;
using namespace justifyText;
using namespace userScreen;
using namespace std;

bool user_screen::show(string user)
{
    ///Šablona stránky uživatele
    system("CLS");
    string titul = "Vase pronajate knihy.";
    justify_text jc;
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    for(int i = 0; i <= 70; i++) {
        int a = jc.justify_center(35, titul);
            if (i == a) {
                SetConsoleTextAttribute(h, 7);
                cout << titul;
                SetConsoleTextAttribute(h, 15);
                i = titul.length() + a - 1;
            } else if (i == 1 || i == 70) {
                cout << "|";
            } else {
                 cout << " ";
            }
    }
    cout << endl;
    for (int k = 1; k <= 70; k++) {
        cout << "-";
    }
    cout << endl;

    readCSVs readCSVs;
    if (readCSVs.doesUserHasBooks(user) != true) {
        string titul2 = "Nemate knihy v pronajmu.";
        for(int i = 0; i <= 70; i++) {
        int a = jc.justify_center(20, titul2);
        if (i == a) {
            SetConsoleTextAttribute(h, 8);
            cout << titul2;
            SetConsoleTextAttribute(h, 15);
            i = titul2.length() + a - 1;
        } else if (i == 1 || i == 70) {
            cout << "|";
        } else {
             cout << " ";
        }
        cout << endl;
        return false;
    }
    } else {
        readCSVs.getRentedBooks(user);
    }
    return true;
}
