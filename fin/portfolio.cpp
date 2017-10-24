#include "portfolio.h"

std::ostream &operator<<( std::ostream &out, Portfolio &ptfo )
{
  out << "Total: " << ptfo.total << std::endl;
  for ( int i = 0; i < (int) ptfo.stocks.size(); i++ )
    out << *(ptfo.stocks[i]) << std::endl;
  return out;
}