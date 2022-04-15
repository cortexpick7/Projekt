#include "table_of_books.h"
#include <iostream>
#include "read_csv.h"
#include "justify_text.hpp"

using namespace justifyText;
using namespace readCSV;
using namespace tableOfBooks;
using namespace std;

void table_of_books::show()
{
    ///Šablona tabulky pro seznam knih
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    justify_text jc;
    system("CLS");
    readCSVs readCSVs;
    string titul = "Zpet na hlavni(Stisknete cokoliv;)";
    int a = jc.justify_center(35, titul);
    for (int i = 0; i <= 70; i++ ) {
        if (i == a) {
            SetConsoleTextAttribute(h, 3);
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
    readCSVs.getAllBooks();
}
