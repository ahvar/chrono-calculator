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
  dailyHigh.push_back( trans );

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
  return os;
}

