#include "security.h"
/** 
  The implementation file for security.h
*/

std::ostream &operator<<( std::ostream &out, Stock &st )
{
  out << st.name << " (" << st.ticker << ")" << ": " << st.value << '\t' << "Mkt Cap: ";
  printf("$%f\n", st.mktcap);
  return out;
}

void addShare( double price )
{



}

double removeShare()
{

  return 0;
}