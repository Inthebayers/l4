//---------------------------------------------------------------------------
// book.h
//---------------------------------------------------------------------------
// A book object. Handles the creation and storage of a
// book, containing title, author, number of copies "owned" by the library,
// and copies of this book currently checked in. Parent class of fictionbook,
// periodicalbook, and childrenbook.
//
//---------------------------------------------------------------------------
#pragma once
#include <iostream>
#include "book.h"
using namespace std;

//---------------------------------------------------------------------------
// constructor
Book::Book()
{
    title_ = "";
    bookCode_ = '';
}

//---------------------------------------------------------------------------
// setTitle
void Book::setTitle(string title)
{
   title_ = incomingTitle;
}

//---------------------------------------------------------------------------
// getTitle
string Book::getTitle() const
{
   return title_;
}

//---------------------------------------------------------------------------
// setBookCode
void Book::setBookCode(char incomingChar)
{
   bookCode_ = incomingChar;
}

//---------------------------------------------------------------------------
// getBookCode
char Book::getBookCode() const
{
   return bookCode_;
}

//---------------------------------------------------------------------------
// setAvailableCopies
void Book::setAvailableCopies(int newNumberOfCopies)
{
   availableCopies_ = newNumberOfCopies;
}

//---------------------------------------------------------------------------
// getAvailableCopies
int Book::getAvailableCopies() const
{
   return availableCopies_;
}

//---------------------------------------------------------------------------
// checkOut
bool Book::checkOut()
{
   if (availableCopies_ > 0)
   {
      availableCopies_ = availableCopies_ - 1;
      return true;
   }
   return false;
}

//---------------------------------------------------------------------------
// returnToLibrary
bool Book::returnToLibrary()
{
   if (availableCopies_ < totalCopies_)
   {
      availableCopies_ += 1;
   }
}

//---------------------------------------------------------------------------
// setTotalCopies
bool Book::setTotalCopies(int newTotalCopyAmount)
{
   if (newTotalCopyAmount > 0)
   {
      totalCopies_ = newTotalCopyAmount;
   }
}

//---------------------------------------------------------------------------
// getTotalCopies
int Book::getTotalCopies() {
   return totalCopies_;
}