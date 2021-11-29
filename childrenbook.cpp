#include "childrenbook.h"
#include "book.h"

using namespace std;

ChildrenBook::ChildrenBook()
{
    author_ = "";
    year_ = 0;
}

//---------------------------------------------------------------------------
   /**
    * @brief Destroy the Children Book object.
    *
    * @pre: Assumes valid ChildrenBook object is created.
    * @post: ChildrenBook object will be deleted, with memory freed.
    */
ChildrenBook::~ChildrenBook()
{
}
//---------------------------------------------------------------------------
 /** create
  * @brief Creates a children book object, then returns a copy of that object
  * for the factory to function properly.
  *
  * @return ChildrenBook copy of newly created book object
  * @post: new children book object is created and returned.
  */
Book* ChildrenBook::create()
{
    return new ChildrenBook();
}

/** setAuthor
 * @brief sets the book author
 * @pre a new book object
 * @post book author stored in data member
 */
void ChildrenBook::setAuthor(string author)
{
    author_ = author;
}

/** getAuthor
 * @brief gets and returns the book author
 * @pre book object has set author
 * @post string of authro is returned
 */
string ChildrenBook::getAuthor() const
{
    return author_;
}

/** setYear
 * @brief sets the year data member
 * @pre a new book object
 * @post a book object with a published year
 */
void ChildrenBook::setYear(int year) {
    year_ = year;
}

/** getYear
 * @brief returns the book published year
 * @pre a book object with set year
 * @post int year is returned
 */
int ChildrenBook::getYear() const {
    return year_;
}

/**
     * Less than operator. Compares LHS and RHS for lesser value.
     * @param rhsBook rhs Book being passed in
     * @return true
     * @return false
     */
bool ChildrenBook::operator<(const Book& rhsBook) const {
    bool holder = false; 

    // cast book to children's book 
    const ChildrenBook& rhsBookCasted = static_cast<const ChildrenBook&>(rhsBook);

    // compare titles
    (getTitle() < rhsBookCasted.getTitle()) ? holder = true : holder = false;

    // if the book titles are the same compare authors
    if (getTitle() == rhsBookCasted.getTitle()) {
        (getAuthor() < rhsBookCasted.getAuthor()) ? holder = true : holder = false;
    }
    return holder;
}

/**
 *
 * Greater than operator. compares LHS and RHS for greater value.
 * @param rhsBook rhs Book being passed in for comparison
 * @return true
 * @return false
 */
bool ChildrenBook::operator>(const Book& rhsBook) const {
    bool holder = false;

    // cast book to children's book 
    const ChildrenBook& rhsBookCasted = static_cast<const ChildrenBook&>(rhsBook);

    // compare titles, adjust bool as needed
    (getTitle() > rhsBookCasted.getTitle()) ? holder = true : holder = false;

    // if the book titles are the same compare authors
    if (getTitle() == rhsBookCasted.getTitle()) {
        (getAuthor() > rhsBookCasted.getAuthor()) ? holder = true : holder = false;
    }
    return holder;
}

/**
 * Equals operator. Determines if two Book objects are equal.
 *
 * @param rhsBook rhs Book being passed in for equals comparison
 * @return true
 * @return false
 */

bool ChildrenBook::operator==(const Book& rhsBook) const {
    bool holder = false; 

    // cast rhs book to children's book
    const ChildrenBook& rhsBookCasted = static_cast<const ChildrenBook&>(rhsBook);

    // compare author, title, and year between two books 
    if (rhsBookCasted.getAuthor() == getAuthor() && rhsBookCasted.getTitle() == getTitle() && rhsBookCasted.getYear() == getYear()) {
        holder = true; 
    }
    return holder;
}

/**
 * Does not equals operator. Determines if two books are not equal.
 *
 * @param rhsBook
 * @return true
 * @return false
 */
bool ChildrenBook::operator!=(const Book& rhsBook) const {
    // use comparison operator to return value
    return !(*this == rhsBook);
}

// TODO: Add spacing
void ChildrenBook::display() const {
    cout << title_ << author_ << year_ << endl;
}