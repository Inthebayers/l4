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
* @return
*/

int main() {


    Library lib;
    ifstream books;
    ifstream patrons;
    patrons.open("repeatpatrons.txt");
    lib.buildPatrons(patrons);
   
    //ifstream books, patrons, commands;
    books.open("data4books.txt");
    lib.buildItem(books); // initialize books
       
    ifstream commands;
    commands.open("data4commands.txt");
    lib.runCommands(commands);

    return 0;
}