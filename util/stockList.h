/**
  StockList is a doubly linked list of Stocks. It provides basic functionality for constructing a list of stocks,
  adding, removing, and sorting stocks by price. Overloaded constructors enable a few different options for construction.
  The Node class contains a Stock, a pointer to the previous Node, and a pointer to the successor Node. The Node class is
  nested in StockList, giving StockList access to Node's members.  
*/
#ifndef STOCKLIST_H_
#define STOCKLIST_H_

#include <stdexcept>
#include "../fin/security.h"

class StockList {
  
private:

  /** A list node has a Stock and pointers to its successor node and previous node */
  class Node {
  public:
    /**
      Constructs a Node containing a Stock ('stock') and two pointers to Nodes for
      the previous and successor Nodes in the StockList.

      @param s the Stock
      @param p a pointer to the previous Node
      @param sc a pointer to the successor Node
    */
    Node( Stock *s, Stock *p, Stock *sc);

    Node( Stock *s );

    /** The default constructor for Node */
    Node(){}
    /**
      Sets the stock instance variable with parameters name, ticker, price, and quantity.

      @param s a pointer to the stock
    */
    void setStock( Stock *s);
    /** The stock */  
    Stock stock;
    /** Pointer to the previous Node */
    Node *prev;
    /** Pointer to the successor Node */
    Node *succ;
  };
  /** List length */
  int length;
  /** The first node in the list */
  Node *head;

public:

  /**
    Constructs a new StockList with parameter s. It creates the head to contain s and sets the previous and successor
    Nodes to NULL.

    @param s the contained in head node
  */
  StockList( Stock *s );

  /**
    Constructs a StockList with three Nodes. Assigns one Node's Stock to the parameter s, a previous Node pointer to the 
    parameter prev, and the successor Node pointer to the parameter succ. Head is assigned to the new Node. 
    The length is set to 3.

    @param s the Stock for this Node
    @param prev the pointer to the previous Node
    @param succ the pointer to the successor Node
  */ 
  StockList( Stock *s, Stock *s1, Stock *s2);

  /**
    Default constructor for a StockList.
  */
  StockList(){}

  /** Destructor for StockList */
  ~StockList();

  /**
    Add Stock s to the front of the list.

    @param s the Stock to be added to the front of the list
    @return true if the s is successfully added, false otherwise
  */
  bool addToFront( Stock *s );


  bool addToEnd();


  bool insert();



  /**
    Locates the first stock in the list with the price point described by the string parameter
    @param t the Transaction
    @param nm the name of the stock
    @return a pointer to the Node
  */
  Node *find( Transaction t, std::string nm);

  /**
    Verifies that the list contains no elements.
    @return true if there are no elements in the list
  */
  bool isEmpty();

  /**
    Returns a pointer to the last Stock in the list
    @return pointer to last Node in the list
  */
  Node *getLast();

  int getLength() { return length; }

  Node *getFirst() { return head; }

  friend std::ostream &operator<<( std::ostream &os, StockList &sl );
  

};

#endif  