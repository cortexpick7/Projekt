#include "first_screen.h"
#include <iostream>
#include "justify_text.hpp"

using namespace justifyText;
using namespace firstScreen;
using namespace std;

void first_screen::show_screen(string titul, string jedna, string dva, string tri)
{
    ///Šablona pro grafiku menu
    justify_text jc;
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    int middle = 35;
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
                        p = titul.length() + a - 1;
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
                int a = jc.justify_center(middle, jedna);
                for (int w = 1; w <= 70; w++) {
                    if (w == a) {
                        cout << jedna;
                        w = jedna.length() + a - 1;
                    } else if (w == 1 || w == 70) {
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
                int a = jc.justify_center(middle, dva);
                for (int w = 1; w <= 70; w++) {
                    if (w == a) {
                        cout << dva;
                        w = dva.length() + a - 1;
                    } else if (w == 1 || w == 70) {
                        cout << "|";
                    } else {
                         cout << " ";
                    }
                }
                cout << endl;
                break;
            }
        case 13:
            {
                int a = jc.justify_center(middle, tri);
                for (int w = 1; w <= 70; w++) {
                    if (w == a) {
                        cout << tri;
                        w = tri.length() + a - 1;
                    } else if (w == 1 || w == 70) {
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
                break;
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
}
