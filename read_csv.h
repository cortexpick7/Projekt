#include <iostream>

using namespace std;
namespace readCSV
{
    class readCSVs
    {
    public:
        bool readPasswords(string pass, string user);
        bool readUsernames(string user);
        bool getAllBooks();
        bool addBook(string name, string author);                                                 //TODO сделать функции frontend ... DONE!!!
        int getLastBookId();
        bool deleteBook(string id);
        int createCSV();
        bool writeCsvFile();
        bool bookRental(int operation, string id, string uzivatelskeJmeno);
        bool getRentedBooks(string inputUzivatel);
        bool addUser(string name, string password);
        bool doesUserHasBooks(string user);
    };
}
