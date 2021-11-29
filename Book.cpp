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

string Book::getTitle()
{
   return title_;
}

void Book::setBookCode(char incomingChar)
{
   bookCode_ = incomingChar;
}

char Book::getBookCode()
{
   return bookCode_;
}

void Book::setAvailableCopies(int newNumberOfCopies)
{
   availableCopies_ = newNumberOfCopies;
}

int Book::getAvailableCopies()
{
   return availableCopies_;
}

bool Book::checkOutOneBook()
{
   if (availableCopies_ > 0)
   {
      availableCopies_ = availableCopies_ - 1;
      return true;
   }
   return false;
}

bool Book::returnOneBook()
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