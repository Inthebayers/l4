#include "childrenbook.h"
#include "book.h"

using namespace std;
//---------------------------------------------------------------------------
// Constructor
ChildrenBook::ChildrenBook() {
  author_ = "";
  year_ = 0;
}

//---------------------------------------------------------------------------
// Destrucor
ChildrenBook::~ChildrenBook() {}

//---------------------------------------------------------------------------
// buildBook

bool ChildrenBook::buildBook(istream &inFile) {
  string title = "";
  string author = "";
  int year;

  inFile.get();

  getline(inFile, author, ',');
  inFile.get(); // remove blank space
  getline(inFile, title, ',');
  inFile.get(); // remove blank space
  inFile >> year;
  setAuthor(author);
  setTitle(title);

  return (setYear(year));
}

//---------------------------------------------------------------------------
// create
Book *ChildrenBook::create() { return new ChildrenBook(); }

//---------------------------------------------------------------------------
// setAuthor
void ChildrenBook::setAuthor(string author) { author_ = author; }

//---------------------------------------------------------------------------
// getAuthor
string ChildrenBook::getAuthor() const { return author_; }

//---------------------------------------------------------------------------
// setYear
bool ChildrenBook::setYear(int year) {
  if (year > 0) {
    year_ = year;
    return true;
  }
  return false;
}

//---------------------------------------------------------------------------
// getYear
int ChildrenBook::getYear() const { return year_; }

//---------------------------------------------------------------------------
// display
// TODO: Add spacing
void ChildrenBook::display() const {
  cout << title_ << author_ << year_ << endl;
}

//---------------------------------------------------------------------------
// overloaded comparison operators
// Children sorted by title, then author
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// overloaded operator <
bool ChildrenBook::operator<(const Book &rhsBook) const {
  bool holder = false;

  // cast book to children's book
  const ChildrenBook &rhsBookCasted =
      static_cast<const ChildrenBook &>(rhsBook);

  // compare titles
  (getTitle() < rhsBookCasted.getTitle()) ? holder = true : holder = false;

  // if the book titles are the same compare authors
  if (getTitle() == rhsBookCasted.getTitle()) {
    (getAuthor() < rhsBookCasted.getAuthor()) ? holder = true : holder = false;
  }
  return holder;
}

//---------------------------------------------------------------------------
// overloaded operator>
bool ChildrenBook::operator>(const Book &rhsBook) const {
  bool holder = false;

  // cast book to children's book
  const ChildrenBook &rhsBookCasted =
      static_cast<const ChildrenBook &>(rhsBook);

  // compare titles, adjust bool as needed
  (getTitle() > rhsBookCasted.getTitle()) ? holder = true : holder = false;

  // if the book titles are the same compare authors
  if (getTitle() == rhsBookCasted.getTitle()) {
    (getAuthor() > rhsBookCasted.getAuthor()) ? holder = true : holder = false;
  }
  return holder;
}

//---------------------------------------------------------------------------
// overloaded operator==
bool ChildrenBook::operator==(const Book &rhsBook) const {
  bool holder = false;

  // cast rhs book to children's book
  const ChildrenBook &rhsBookCasted =
      static_cast<const ChildrenBook &>(rhsBook);

  // compare author, title, and year between two books
  if (rhsBookCasted.getAuthor() == getAuthor() &&
      rhsBookCasted.getTitle() == getTitle() &&
      rhsBookCasted.getYear() == getYear()) {
    holder = true;
  }
  return holder;
}

//---------------------------------------------------------------------------
// overloaded operator !=
bool ChildrenBook::operator!=(const Book &rhsBook) const {
  // use comparison operator to return value
  return !(*this == rhsBook);
}