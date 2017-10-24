#include "security.h"
/** 
  The implementation file for security.h
*/

std::ostream &operator<<( std::ostream &out, Stock &st )
{
  out << st.name << " (" << st.ticker << ") " << ": " << st.value << "Mkt Cap: " << st.mktcap << std::endl;
  //out << st.name + " (" + st.ticker + "): " + '\t' + st.value + "Mkt Cap: " + st.mktcap + '\n';
  return out;
}