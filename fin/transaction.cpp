/**
  The implementation for the Transaction class
*/

#include "transaction.h"

Transaction::Transaction( Date &date, double p )
{
	


}

Transaction::~Transaction()
{



}

std::ostream &operator<<(std::ostream &os, Transaction &t )
{
  os << t.date << " " << t.price << std::endl; 
  return os;
}
