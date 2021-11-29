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

Book::Book()
{
}

void Book::setTitle(string incomingTitle)
{
   title_ = incomingTitle;
}

string Book::getTitle() const
{
   return title_;
}

void Book::setBookCode(char incomingChar)
{
   bookCode_ = incomingChar;
}

char Book::getBookCode() const
{
   return bookCode_;
}

void Book::setAvailableCopies(int newNumberOfCopies)
{
   availableCopies_ = newNumberOfCopies;
}

int Book::getAvailableCopies() const
{
   return availableCopies_;
}

   //---------------------------------------------------------------------------
   /**
      * @brief Handles the field management required to check out a book.
      *
      * @return true if check out was successful
      * @return false if check out was not sucessful
      *
      * @pre: Assumes book has amount to check out
      * @post: Book will remove 1 copy of itself from the library stores
      */
bool Book::checkOut()
{
   if (availableCopies_ > 0)
   {
      availableCopies_ = availableCopies_ - 1;
      return true;
   }
   return false;
}

bool Book::returnToLibrary()
{
   if (availableCopies_ < totalCopies_)
   {
      availableCopies_ += 1;
   }
}

bool Book::setTotalCopies(int newTotalCopyAmount)
{
   if (newTotalCopyAmount > 0)
   {
      totalCopies_ = newTotalCopyAmount;
   }
}

int Book::getTotalCopies() {
   return totalCopies_;
}