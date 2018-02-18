/**
  StockList is a doubly linked list of Stocks. It provides basic functionality for constructing a list of stocks,
  adding, removing, and sorting stocks by price. Overloaded constructors enable a few different options for construction.
  The Node class contains a Stock, a pointer to the previous Node, and a pointer to the successor Node. The Node class is
  nested in StockList, giving StockList access to Node's members.  
*/

#include <fstream>
#include <istream>
#include <sstream>
#include <ostream>
#include <stdexcept>
#include <vector>
#include "../fin/security.h"

class StockList {
  
private:

  /** A list node has a Stock and pointers to its successor node and previous node */
  class Node;
  /** List length */
  int length;
  /** The first node in the list */
  Node *head;

public:

  /**
    Constructs a StockList with a single node and assigns the head to the node passed into the parameter n.

    @param n the head Node in the list
  */
  StockList( Node *n ) { head = n; }
 
  /**
    Constructs a StockList with one Nodes and assigns the head to the reference passed into the parameter n
    @param n a reference to the head Node in the list
  */
  //StockList( Node &n ) { head = n; }

  /**
    Constructs an empty StockList with the number of Stocks passed into the parameter. Stock price and volume are set at 0.
    @param i the number of Stocks in the list
  */
  StockList(int x);

  /**
    Constructs a StockList with three Nodes. Assigns one Node's Stock to the parameter s, a previous Node pointer to the 
    parameter prev, and the successor Node pointer to the parameter succ. Head is assigned to the new Node. 
    The length is set to 3.

    @param s the Stock for this Node
    @param prev the pointer to the previous Node
    @param succ the pointer to the successor Node
  */ 
  StockList( Stock s, Node *prev, Node *succ );

  /**
    Default constructor for a StockList.
  */
  StockList(){}

  /**
    Adds this Node at the end of a StockList.

    @param n the Node to be inserted
    @return the head Node
  */
  Node *insertAtEnd( Node *n );

  /**
    Adds a Stock to the front of the list and returns a pointer to the Stock that was added.
    
    @param n the Stock to add
    @return a pointer to the newly added Stock
  */
  Node *add( Node *n );

  /**
    Locates the first stock in the list with the price point described by the string parameter
    @param t the price of the target Stock
    @param p the price point is either open, close, previous close, high, or low
    @return the target Stock
  */
  Node *find( Node *t, std::string p);

  /**
    Sorts the list by the price point described by the parameter. The different points are close, previous close, open, high and low. Be default the list is sorted
    by close.

    @param p description of the price point
    @return a pointer to the head
  */
  Node *sortByPrice( std::string p );

  /**
    Verifies that the list contains no elements.
    @return true if there are no elements in the list
  */
  bool isEmpty() { if(length==0) return true; }

  /**
    Add a Node to the front of the list and assigns the head to this Node.

    @param n the Node to be added to the front of the list
    @return a pointer to the head
  */
  Node *insertAtFront( Node *n );

  /**
    Returns a pointer to the last Node in the list
    @return pointer to the last Node
  */
  Node *getLast();

  /**
    Returns true if the list is currently sorted in ascending order by stock price.
    @return true if sorted in ascending order
  */
  bool isSortedAscending();
  

};