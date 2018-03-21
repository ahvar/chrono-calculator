/**
  The implementation for the Transaction class
*/

#include "transaction.h"

Transaction::Transaction( Date d, double p )
{
  date = d; 
  price = p;
}

Transaction::~Transaction()
{
 
}

std::ostream &operator<<(std::ostream &os, Transaction &t )
{
  os << t.date << " " << std::setw(5) << t.price << std::endl; 
  return os;
}
