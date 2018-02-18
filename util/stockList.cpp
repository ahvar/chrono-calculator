/**
  Implementation for stockList
*/
#include "stockList.h"

StockList::Node {

public:

  /**
    Constructs a Node with a Stock, pointers to the previous and successor Nodes in the list
    @param s the Stock
    @param p a pointer to the previous Node
    @param sc a pointer to the successor Node
  */
  StockList::Node::Node ( Stock s, Node *p, Node *sc ) : stock{s}, prev{p}, succ{sc} {}

  /** Default constructor */
  StockList::Node::Node(){}

private:
  /** The stock */
  Stock stock;
  /** A pointer to previous Node in the list */
  Node *prev;
  /** A pointer to the successor Node in the list */
  Node *succ;

}

StockList::StockList( Stock s, Node *prev, Node *succ )
{
  head = new Node( Stock stk{"","",0,0}, prev, succ );
  head->succ = new Node( Stk stk{"","",0,0}, head, NULL);
  head->prev = new Node( Stock stk{s}, NULL, head);
  head = head->prev;
  length = 3;
}

StockList::StockList( int x )
{

  head = new Node( Stock s{"","",0,0}, NULL, NULL );
  Node *ptr = head;
  for ( int i = 0; i < x; i++ ) {

    if ( i = 0 ) {
      ptr->succ = new Node( Stock s{"","",0,0},NULL,NULL);
      ptr->succ->prev = head;
      head->prev = NULL;
      ptr = head->succ;
    } else {
      ptr->succ = new Node( Stock s{"","",0,0},NULL,NULL);
      ptr->succ->prev = ptr->prev->succ;
      ptr->prev->succ = ptr->succ;
      ptr = ptr->succ;
      
    }

    length++;
  }
  return head;

}

Stock *StockList::add( Node *n )
{
  // first handle the case of when the list is empty
  if (isEmpty()) {
    head = n;
    length++;
    return head;
  } else if ( !sorted() ) {
    StockList::sortByPrice();  
  }
  Node *ptr = head;
  while( ptr ) {
    if (ptr->stock.value <= n->stock.value)
      break;
    ptr = ptr->succ;
  }
  // we reached the end of the list or it is the last node in the list
  if ( ptr == NULL || ptr->succ == NULL ) {
    return StockList::insertAtEnd(n);
  else if ( ptr == head ) {
    return StockList::insertAtFront(n);   
  } else {
    n->succ = ptr->prev->succ;
    n->prev = ptr->prev;
    ptr->prev->succ = n;
    ptr->prev = n;
    ptr->prev->prev->succ = n;
    length++;
  }
  return n;

}

Node *StockList::insertAtFront( Node *n )
{
  n->succ = head;
  head->prev = n;
  n->prev = NULL;
  head = n;
  return head;
}

StockList::Node *insertAtEnd( Node *n )
{
  Node *ptr = head;
  while (ptr->succ) 
    ptr = ptr->succ;
  ptr->succ = n;
  n->prev = ptr->prev->succ;
  length++;
  return n;

}

Node *find( double t, std::string nm )
{
  Node *ptr = head;
  while( ptr->succ ) {
    if( ptr->stock.value == t && ptr->stock.name == nm )
      break;
    ptr = ptr->succ;
  }
  return ptr;
}

StockList::Node *sortByPrice()
{
  while( !isSortedAscending() ) {

    if( length == 0 ) {
      return NULL;

    } else if ( length ==  1 ) {
      return head;

    } else if ( length == 2 ) {

      if  ( head->stock.value > head->succ->stock.value ) 
        head = head->succ;
      return head;

    } else if ( length >= 3 ) {
      Node *pivot = getLast();
      Node *curr = head;

      while(curr->succ) {

        if(curr->stock.value <= pivot->stock.value) { // node's stock value is less than pivot. move it to the left of pivot. 
                                                     //insert between pivot and previous node.
          pivot->prev->succ = curr->succ->prev;
          Node *pvPre = pivot->prev;
          pivot->prev = curr->succ-prev;
          curr->succ->prev->succ = pivot;
          pivot->prev->prev = pvPre->prev->succ;

        } else if ( curr->stock.value >= pivot->stock.value ) { // node's stock value is greater than pivot's. move it to the right of pivot

          if (pivot->succ == NULL) { // there are no nodes after the pivot
            curr->prev = pivot;
            pivot->succ = curr->succ->prev;
            curr = curr->succ;
          } else { // insert the node between the pivot and its successor node
            curr->prev = pivot;
            pivot->succ->prev = curr->succ->prev;
            curr->succ->prev->succ = pivot->succ;
            pivot->succ = curr->succ->prev;
            curr = curr->succ; 
          }
          curr->prev = NULL;

        }
    
     }

  }
 
}

StockList::Node *getLast()
{

  Node *ptr = head;
  while(ptr->succ != NULL)
    ptr = ptr->succ;
  return ptr;


}

bool StockList::isSortedAscending()
{

  Node *ptr = head;
  while(ptr->succ != NULL) {
    if( ptr->stock.value > ptr->succ->stock.value )
      return false;
    ptr = ptr->succ;
  }
  return true;

}






