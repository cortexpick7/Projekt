#include "justify_text.hpp"
#include <iostream>

using namespace justifyText;
using namespace std;

int justify_text::justify_center(int a, string b)
{
    ///Zarovnání testu na střed obrazovky
    return a - (b.length()/2);
}
