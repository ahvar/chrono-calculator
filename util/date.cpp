#include "date.h"

std::istream &operator>>(std::istream &is, Date &dat)
{
	
  int tmp;
  is >> tmp; dat.tm_date.tm_year = tmp;
  is.ignore();
  is >> tmp; dat.tm_date.tm_mon = tmp;
  is.ignore();
  is >> dat.tm_date.tm_mday;
  
  return is;
}

std::ostream &operator<<(std::ostream &os, const Date &dat)
{

  os << dat.tm_date.tm_mon << "-" << dat.tm_date.tm_mday << "-" << dat.tm_date.tm_year;
  	
  return os;
}