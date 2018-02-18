#include "date.h"

template<class charT, class Traits>
std::basic_istream<charT, Traits> &operator>>(std::basic_istream<charT, Traits> &is, Date &dat)
{
  
  
  return is;
}

template<class charT, class Traits>
std::basic_ostream<charT, Traits> &operator<<(std::basic_ostream<charT, Traits> &os, const Date &dat)
{
  

  return os;
}