/**
  The implementation for bank header file
*/

#include "bank.h"

std::ostream &operator<<( std::ostream &out, IB &ib )
{
  out << '\t' << ib.getName() << std::endl;
  for ( std::vector<Portfolio *>::iterator it = ib.getAllInvstmnt().begin(); it != ib.getAllInvstmnt().end(); it++ ) 
    out << *it << std::endl;  
  return out;

}
