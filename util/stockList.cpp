/**
  Implementation for stockList
*/
#include "stockList.h"

StockList::Node::Node( Stock *s )
{ 
  Node *n = new Node();
  n->setStock(s); 
}

StockList::Node::Node( Stock *s, Stock *s1, Stock *s2 )
{
  Node n;
  Node *ptr = &n;
  n.succ = new Node();
  n.succ->prev = ptr;
  n.prev = new Node();
  n.prev->succ = ptr;
}

void StockList::Node::setStock( Stock *s )
{
  stock.setName(s->getName());
  stock.setTicker(s->getTicker());
  //stock.setDailyHigh(s->setDailyHigh());
  stock.setQuantity(s->getQuantity());
}

StockList::StockList( Stock *s, Stock *p, Stock *sc )
{
  head = new Node( s );
  head->succ = new Node( p );
  head->prev = new Node( sc );
  head = head->prev;
  length = 3;
}

StockList::StockList( Stock *s )
{
  Node n;
  n.setStock(s);
  head = &n;

}

StockList::~StockList()
{
  Node *ptr = head;
  Node *temp;
  while( ptr != NULL) {
    temp = ptr;
    ptr = ptr->succ;
    delete temp;
  }
}

bool StockList::addToFront( Stock *s )
{
  if ( head == NULL && length == 0 ) {
    head = new Node();
    head->setStock(s);
    length++;
    return true;
  } else if ( head && length > 0 ) {
    head->prev = new Node(s);
    head->prev->succ = head;
    head = head->prev;
    length++;
    return true;
  }
  return false;
}

StockList::Node *StockList::find( Transaction t, std::string nm )
{
  Node *ptr = head;
  /*
  while( ptr->succ ) {
    if( ptr->stock.getRecord() == t && ptr->stock.getName() == nm )
      break;
    ptr = ptr->succ;
  }
  */
  return ptr;
}

StockList::Node *StockList::getLast()
{

  Node *ptr = head;
  while(ptr->succ != NULL)
    ptr = ptr->succ;
  return ptr;

}


bool StockList::isEmpty()
{
  if(length==0)
    return true;
  return false;
}

Stock &StockList::stockAt( int i )
{
  Node *ptr = head;
  if( i <= length ) {
    int idx = 0;
    while( idx != i-1  ) {
      ptr = ptr->succ;
      idx++;
    }
  }
  return ptr->stock;

}

std::ostream &operator<<( std::ostream &os, StockList &sl )
{
  StockList::Node *ptr = sl.getFirst();
  while( ptr ) {
    os << ptr->stock << std::endl;
    ptr = ptr->succ;
  }
  return os;

}





