//---------------------------------------------------------------------------
// main.cpp
//---------------------------------------------------------------------------

#include "library.h"
#include <fstream>
#include <iostream>

using namespace std;

//---------------------------------------------------------------------------
 /**
  * @brief
  * @pre
  * @post
  */


int main() {
    Library lib;
    ifstream books, patrons, commands;
    books.open("booksFile");
    lib.addBook(books); // initialize books
    patrons.open("patronsFile");
    lib.addPatron(patrons); // initialize patrons
    commands.open("commandFile");
    lib.commandHandler(commands); // initialize commands
    return 0;
}
