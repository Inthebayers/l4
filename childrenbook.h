//---------------------------------------------------------------------------
// childrenbook.h
//---------------------------------------------------------------------------
// Subclass of Book
// A children book object. Handles the creation and storage of a children's
// book, containing title, author, number of copies "owned" by the library,
// and copies of this book currently checked in.
//
// Assumptions:
//  -- initial character in input dictates 'C' for children
//  -- Comparison operators will only be used with other ChildrenBook
//  -- istream data will always be in the correct format
//
// Implementation:
//  -- data format from command data file handled in fill() method
//  -- data format from book data file handled in buildItem()
//
//---------------------------------------------------------------------------

#include "book.h"
#include <iostream>

class ChildrenBook : public Book {

  public:
    /** constructor
     * @brief Construct a new Children object. Creates new Children book with
     * @pre: assumes object needs to be created
     * @post: children object will be destroyed, with memory freed
     */
    ChildrenBook();

    /** destructor
     * @brief Destroy the Children Book object.
     * @pre: Assumes valid ChildrenBook object is created.
     * @post: ChildrenBook object will be deleted, with memory freed.
     */
    ~ChildrenBook();

    /** buildItem
     * @brief Builds the data for a blank book object. Handles the "filling out"
     * of the book being created.
     *
     * @param infile Incoming information from file.
     * @return true
     * @return false
     */
    bool buildItem(istream &infile);

    /** create
     * @brief Creates a dynamically allocated children book object, then
     returns a copy of that object for the factory to function properly.
     *
     * @return ChildrenBook copy of newly created book object
     * @post: new children book object is created and returned.
     */
    virtual Item *create();

    /** fill
     * @brief fills data for a childrenBook item from Command Data file format
     * @pre an empty ChildrenBook item
     * @post only author and title data fields are set
     */
    virtual void fill(istream &);

    /** diaplay
     * @brief displays the information of the current book in sort order
     * @pre a non-empty book object
     * @post contents displayed to console,
     * avaialble copies, title, author, year
     */
    virtual void display() const;

    /** errorDisplay
     * @brief handles the ouput of an invalid Childrenbook's - prints to console
     * @pre ChildrenBook object has title_ and author_ set
     * @post error messaged displayed
     */
    void errorDisplay() const;

    /** historyDisplay
     * @brief formats the output when ChildrenBook Item is displayed from patron
     * history list
     * @pre ChildrenBook Item previously added to patron history
     * @post data members printed to console in history format
     */
    void historyDisplay() const;

    /** displayBookHeader
     * @brief displays the categories and format of data for ChildrenBook list
     * @pre none
     * @post Children book item list header printed to cout
     */
    void displayBookHeader() const;

    /** getCopiesAvailable
     * @brief gets and returns the available copies of this object
     * @pre none
     * @post availableCopies_ returned
     * @return int of availableCopies_
     */
    int getCopiesAvailable() const;

    /** setAuthor
     * @brief sets the book author
     * @pre a new book object
     * @post book author stored in data member
     */
    void setAuthor(string author);

    /** getAuthor
     * @brief gets and returns the book author
     * @pre book object has set author
     * @post string of authro is returned
     */
    string getAuthor() const;

    /** setYear
     * @brief sets the year data member
     * @pre a new book object
     * @post a book object with a published year
     */
    bool setYear(int year);

    /** getYear
     * @brief returns the book published year
     * @pre a book object with set year
     * @post int year is returned
     */
    int getYear() const;

    /** changeAvailable
     * @brief increment or decrement availableCopies_
     * @pre Childrenbook to be checkedOut or returned by patron
     * @post availableCopies_ value changes by 1
     * @return bool true if successful
     */
    virtual bool changeAvailable(int num);

//---------------------------------------------------------------------------
// Overloaded Operators
//---------------------------------------------------------------------------

    /** operator<
     * Less than operator. Compares LHS and RHS for lesser value.
     * @param rhsItem rhs Book being passed in
     * @return true
     * @return false
     */
    bool operator<(const Item &rhsItem) const;

    /** operator>
     * Greater than operator. compares LHS and RHS for greater value.
     * @param rhsItem rhs Book being passed in for comparison
     * @return true
     * @return false
     */
    bool operator>(const Item &rhsItem) const;

    /** operator==
     * Equals operator. Determines if two Book objects are equal.
     *
     * @param rhsItem rhs Book being passed in for equals comparison
     * @return true
     * @return false
     */
    bool operator==(const Item &rhsItem) const;

    /** operator !=
     * Does not equals operator. Determines if two books are not equal.
     *
     * @param rhsItem
     * @return true
     * @return false
     */
    bool operator!=(const Item &rhsItem) const;

  private:
    // author of the book, last then first name
    string author_;

    // publishing year
    int year_;

    // default value for available and total copies
    static const int COPIES = 5;
};
