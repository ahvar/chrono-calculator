/**
  A custom list of securities.
*/

#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <istream>
#include <sstream>
#include <cstdio>
#include <ostream>
#include <cmath>
#include <stdexcept>
#include <vector>
#include "../fin/security.h"


class StockList{
  StockList(const Stock *s ) : head{s} { head->prev = NULL; head->succ = NULL; }
 
  StockList(const Stock &s) : head{s} { head.prev = NULL; head.succ = NULL; } 
  /**
    Constructs an empty StockList with the number of Stocks passed into the parameter. Stock price and volume are set at 0.
    @param i the number of Stocks in the list
  */
  StockList(int x);
 
  /**
    Inserts the Stock into a list sorted in ascending order according to the price specified by the string  parameter.

    @param n the Stock to be inserted
    @param p the price used for sorting the list
    @return a pointer to the inserted Security
  */
  Stock *insert( Stock *n, std::string p );

  /**
    Adds a Stock to the front of the list and returns a pointer to the Stock that was added.
    
    @param n the Stock to add
    @return a pointer to the newly added Stock
  */
  Stock *add( Stock *n );

  /**
    Locates the first stock in the list with the price point described by the string parameter
    @param t the price of the target Stock
    @param p the price point is either open, close, previous close, high, or low
    @return the target Stock
  */
  Stock *find( Stock *t, std::string p);

  /**
    Sorts the list by the price point described by the parameter. The different points are close, previous close, open, high and low. Be default the list is sorted
    by close.

    @param p description of the price point
    @return a pointer to the head
  */
  Stock *sortByPrice( std::string p );

  bool isEmpty() { if(size==0) return true; }

  Stock *insertAtFront( Stock *n );

  Stock *insertAtEnd
  


private:
  Stock *head;
  Stock *prev;
  Stock *succ;
  int length;
};