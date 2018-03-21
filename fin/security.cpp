#include "security.h"

Stock::~Stock()
{
  

}

Security::~Security()
{
  for(Transaction *ptr = &(high[0]); ptr ; ptr++ )
    delete ptr;
  for(Transaction *ptr = &(open[0]); ptr ; ptr++ )
    delete ptr;
  for(Transaction *ptr = &(low[0]); ptr ; ptr++ )
    delete ptr;
  for(Transaction *ptr = &(close[0]); ptr ; ptr++ )
    delete ptr;
  for(Transaction *ptr = &(adjClose[0]); ptr ; ptr++ )
    delete ptr;
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
  Transaction t(d,price);
  addHigh(t);

}

void Security::addHigh( Transaction &t )
{
  high.push_back(t);
}

void Security::addOpen( Transaction &t )
{
  open.push_back(t);
}
  
void Security::addClose( Transaction &t )
{
  close.push_back(t);
}
  
void Security::addLow( Transaction &t )
{
  low.push_back(t);
}
  
void Security::addAdjClose( Transaction &t )
{
  adjClose.push_back(t);
} 

void Security::addVolume( int vol )
{


}

std::ostream &operator<<( std::ostream &os, Stock &s )
{
  os << s.getName() << " " << s.getTicker() << std::endl;
  int i = 0;
  while( i < (int) s.getHighPriceList().size()-1 ) {
  	os << s.getOpenPriceList()[i] << std::endl;
  	os << s.getHighPriceList()[i] << std::endl;
  	os << s.getLowPriceList()[i] << std::endl;
  	os << s.getClosePriceList()[i] << std::endl;
  	os << s.getAdjClosePriceList()[i] << std::endl;
  	i++;
  }
  return os;
}

