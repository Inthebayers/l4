//---------------------------------------------------------------------------
// periodicalbook.h
//---------------------------------------------------------------------------
// A periodical book object. Handles the creation and storage of a periodical
// book, containing title, author, number of copies "owned" by the library,
// and copies of this book currently checked in.
//
// Assumptions:
//  -- initial character in input dictates 'p' for periodical
//---------------------------------------------------------------------------
#include "book.h"
#include <iostream>

class PeriodicalBook : public Book {
    /**
     * @brief Output operator overload for PeriodicalBook object. Dictates
     * output formatting and functionality for a periodical book.
     *
     * @return ostream& containing information to be output in a formatted style
     * @pre: Assumes valid FictionBook object being passed in.
     * @post: Data not changed, but is output.
     */
    friend ostream& operator<<(ostream&, const PeriodicalBook&);

public:
    /**
     * @brief Construct a new Periodical Book object.
     *
     * @param title of book being created
     * @param year book being created was written/published
     * @param month book being created was written/published
     */
    PeriodicalBook(string title, int year, int month);

    //---------------------------------------------------------------------------
        /**
         * @brief Destroy the Periodical Book object.
         *
         * @pre: Assumes valid created object to be destroyed
         * @post: Periodical object will be deleted and memory freed
         */
    ~PeriodicalBook();

    //---------------------------------------------------------------------------
        /** create
         * @brief Creates a periodical book object, then returns a copy of that
         * object for the factory to function properly.
         *
         * @return PeriodicalBook copy of newly created book object
         * @post: new periodical book object is created and returned.
         */
    virtual Book* create();

    /** setMonth
     * @brief sets the publishing month data of the periodical
     * @pre a new periodical book object
     * @post month data member set
     */
    void setMonth();

    /** getMonth
     * @brief returns the publishing month of the periodical
     * @return month int from 1 -12
     */
    int getMonth() const;

    /** setYear
     * @brief sets the publishing year data of the periodical
     * @pre a new periodical book object
     * @post year data member set
     */
    void setYear();

    /** getYear
     * @brief returns the publishing year of the periodical
     * @return year int
     */
    int getYear() const;



private:
    // month periodical was written/published
    int month;
    // year periodical was written/published
    int year;
};
