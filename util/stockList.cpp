/**
  Implementation for securitiesList.h
*/
#include "securitiesList.h"


StockList::StockList( int x )
{
  head = new Stock("", "", 0, 0);
  Stock *ptr = head;
  for ( int i = 0; i < x; i++ ) {

    if ( ptr == head ) {
      head->succ = new Stock("","",0,0);
      head->succ->prev = head;
      head->prev = NULL;
      ptr = head->succ;
    } else {
      
      ptr->succ = new Stock("","",0,0);
      ptr->succ->prev = ptr;
      
    }
  }

}

Stock *StockList::add( Stock *n )
{
  // first handle the case of when the list is empty
  if (isEmpty()) {
    head = n;
    length++;
    return head;
  } else {

    Stock *ptr = head;
    while( n->value > ptr->value && ptr != NULL ) {
      ptr = ptr->prev;
    }
    // we reached the end of the list
    if ( ptr == NULL ) {
      return StockList::insertAtEnd(n);
    // if the price of the first stock is less than or equal to price of the stock being added
    else if ( ptr == head ) {
      return StockList::insertAtFront(n);   
    } else {
        n->succ = ptr;
        ptr->prev->succ = n;
        n->prev = ptr->prev->succ;
        ptr->prev = n;
        length++;
        return n;
    }
  }


}

Stock *StockList::insertAtFront( Stock *n )
{
  n->succ = head;
  head->prev = n;
  n->prev = NULL;
  head = n;
  return head;

}

StockList::Stock *insert( Stock *n, std::string price )
{
  if ( !ascending(this,price) ) sortAscending(this, price);

  Stock *ptr = head;
  if(ptr->close >= n->close) {
    return insertAtFront(n);
  } else {
    while(ptr->close < n->close)
      ptr = ptr->succ;
    if(ptr->succ == NULL) {
      return insertAtEnd(n);
    } else {
      n->succ = getStock(ptr->close);
      ptr->prev->succ = n;
      n->prev = p->prev;
      getStock(ptr->close)->prev = n;
    }
    length++;
  if(p==NULL)
  n->succ = p;

}


Stock *find( double t, std::string nm )
{
  double point;
  
  Stock *ptr = head;
  if( p.compare("close") == 0 )
    point = t->close;
  else if ( p.compare("open") == 0 )
    point = t->open;
  else if ( p.compare("previous close") == 0 )
    point = t->prevClose;
  else if ( p.compare("high") == 0 )
    point = t->high;
  else if ( p.compare("low") == 0 )
    point = t->low;
  else
    // throw error

  if(ptr


}




Stock *sortByPrice( std::string p )
{
    



}




