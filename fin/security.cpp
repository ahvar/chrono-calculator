#include "security.h"

Stock::~Stock()
{
  

}

Security::~Security()
{


}


Security::Security( Transaction &t )
{
  

}

Security::Security( Transaction *t )
{

	
}

Security::Security( double price )
{ 
  Date d(01,01,2016);
  Transaction *t = new Transaction(d,price);
  addHigh(t);

}

void Security::addHigh( Transaction *t )
{
  Transaction &trans = *t;
  high.push_back( trans );

}

void Security::addOpen( Transaction *t )
{
  Transaction &trans = *t;
  open.push_back(trans);

}
  
void Security::addClose( Transaction *t )
{
  Transaction &trans = *t;
  close.push_back(trans);

}
  
void Security::addLow( Transaction *t )
{
  Transaction &trans = *t;
  low.push_back(trans);

}
  
void Security::addAdjClose( Transaction *t )
{
  Transaction &trans = *t;
  adjClose.push_back(trans);
} 

void Security::addVolume( int vol )
{


}

std::ostream &operator<<( std::ostream &os, Stock &s )
{
  os << s.getName() << " " << s.getTicker() << std::endl;

  for(std::vector<Transaction>::iterator hit = s.high.begin(); hit != s.high.end(); ++hit )
  	os << *hit << std::endl;
  for(std::vector<Transaction>::iterator oit = s.open.begin(); oit != s.open.end(); ++oit )
  	os << *oit << std::endl;
  for(std::vector<Transaction>::iterator cit = s.close.begin(); cit != s.close.end(); ++cit )
  	os << *cit << std::endl;
  for(std::vector<Transaction>::iterator lit = s.low.begin(); lit != s.low.end(); ++lit )
  	os << *lit << std::endl;
  for(std::vector<Transaction>::iterator ait = s.adjClose.begin(); ait != s.adjClose.end(); ++ait )
  	os << *ait << std::endl;
  return os;
}

