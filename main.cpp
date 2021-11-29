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
    lib.buildBooks(books); // initialize books
    patrons.open("patronsFile");
    lib.buildPatrons(patrons); // initialize patrons
    commands.open("commandFile");
    lib.commandHandler(commands); // initialize commands
    return 0;
}

void testBooks() {
    Library lib;
    ifstream books;
    books.open"data4books.txt";

}