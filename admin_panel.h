#include <iostream>

using namespace std;
namespace adminPanel
{
    class admin_panel
    {
    public:
        void show();
        addBook(int id, string name, string author);
        deleteBook(int id);
        addUser(string name, string pass);
        deleteUser(string name);
    };
}
