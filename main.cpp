//---------------------------------------------------------------------------
// main.cpp
//---------------------------------------------------------------------------

#include "library.h"
#include <fstream>
#include <iostream>

using namespace std;

int main() {
    Library l;
    ifstream books, patrons, commands;
    books.open("booksFile");
    l.addBook(books); // initialize books
    patrons.open("patronsFile");
    l.addPatron(patrons); // initialize patrons
    commands.open("commandFile");
    l.commandHandler(commands); // initialize commands
    return 0;
}
