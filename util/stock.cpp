/** 
  The implementation of functions declared in the stock classes
*/

vector<Share> &issueOutstanding( int qty )
{
  
  return vShrs;
}


std::ostream &operator<<( std::ostream &out, Stock &st )
{
  double mktcap = 0;
  for ( Share s : st )
    mktcap += s.price;
  out << st.name + " (" + st.ticker + "): " + '\t' + "Mkt Cap: " + mktcap + '\n';
  return out;
}

std::ostream &operator<<( std::ostream &out, Portfolio &ptfo )
{
  out << "Total: " << ptfo.total << '\n';
  for ( Stock s : ptfo )
    out << s << '\n';
  return out;
}