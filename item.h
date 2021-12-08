//---------------------------------------------------------------------------
// item.h
//---------------------------------------------------------------------------
// An abstract class.
// An item class for the library to store different types of items.
// Current item types are book, but can be other types such as DVD, magazine, etc.
// 
// Assumptions:
// -- All items will have a unique char identifier
// -- all items will have a format
// 
// Implementation:
// -- bool array keeps track of known formats
// 
//---------------------------------------------------------------------------

#ifndef ITEM_H
#define ITEM_H
#include <iostream>
using namespace std;

class Item {
public:

    //constructor
    Item();

    //destuctor
    virtual ~Item();

//---------------------------------------------------------------------------
    /** buildItem
    * @brief creates item object reading from data file
    * @pre: A correctly formatted open data file
    * @post: a new item object 
    */
   virtual bool buildItem(istream& in) = 0;

   //---------------------------------------------------------------------------
    /** display
    * @brief prints the contents of the item to console,
    * pure virtual function
    * @pre implemented display() in child classes
    * @post book contents displayed to console
    */
   virtual void display() const = 0;
    //---------------------------------------------------------------------------
    
    //---------------------------------------------------------------------------
    /** errorDisplay
    * @brief handles the ouput of an invalid Item - prints to console
    * @post error messaged displayed
    */
   virtual void errorDisplay() const = 0;

   //---------------------------------------------------------------------------
   /** historyDisplay
   * @brief formats the output when Item is displayed from patron
   * history list
   * @pre Item previously added to patron history
   * @post data members printed to console in history format
   */
   virtual void historyDisplay() const = 0;

   //---------------------------------------------------------------------------
   /** displayBookHeader
   * @brief displays the categories and format of data for Item list
   * @pre none
   * @post Item list header printed to cout
   */
   virtual void displayBookHeader() const = 0;

   //---------------------------------------------------------------------------
   /** getCopiesAvailable
   * @brief gets and returns the available copies of this object
   * @pre none
   * @post availableCopies_ returned
   * @return int of availableCopies_
   */
   virtual int getCopiesAvailable() const = 0;

   //---------------------------------------------------------------------------
   /** create
    * @brief creates a new item object, pure virutal funciton
    * @pre implemented create() in child classes
    * @return returns a pointer to a new item object
    */
   virtual Item *create() = 0;

 
    //---------------------------------------------------------------------------
    /** fill
    * @brief fills data for an item from Command Data file format
    * @pre an empty item
    * @post relevant data fields are set
    */
   virtual void fill(istream&) = 0;

   //---------------------------------------------------------------------------
   /** getType
   * @brief gets and returns itemtpye code
   * @pre a non-empty Item object
   * @return char of Item type
   */
   char getType() const;

   //---------------------------------------------------------------------------
   /** setFormat
   * @brief sets the Item format type
   * @post format_ is set to a valid Char
   * @return bool true if successful 
   */
   virtual bool setFormat(char format);

   //---------------------------------------------------------------------------
   /** changeAvailable
   * @brief increment or decrement availableCopies_
   * @pre Childrenbook to be checkedOut or returned by patron
   * @post availableCopies_ value changes by 1
   * @return bool true if successful
   */
   virtual bool changeAvailable(int num) = 0;

   //---------------------------------------------------------------------------
   // Overloaded Operators
   //---------------------------------------------------------------------------

     /**
    * Less than operator. Compares LHS and RHS for lesser value.
    * @param rhsBook rhs item being passed in
    * @return true
    * @return false
    */
   virtual bool operator<(const Item &rhsItem) const = 0;

    /**
    * Greater than operator. compares LHS and RHS for greater value.
    * @param rhsItem rhs Item being passed in for comparison
    * @return true
    * @return false
    */
   virtual bool operator>(const Item &rhsItem) const = 0;

   /**
     * Equals operator. Determines if two Item objects are equal.
     *
     * @param rhsItem rhs Item being passed in for equals comparison
     * @return true
     * @return false
     */
   virtual bool operator==(const Item &rhsItem) const = 0;

   /**
     * Does not equals operator. Determines if two items are not equal.
     * @param rhsItems
     * @return true
     * @return false
     */
   virtual bool operator!=(const Item &rhsItem) const = 0;

protected:

    // Item type code
    char itemType_; 

    // format type code
    char format_;

    static const int FORMATS = 26;

    // array of knwon and valid format types
    bool validFormat[FORMATS] = { false };
};

#endif // !ITEM_H
