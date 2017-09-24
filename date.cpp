/**
  Implementation file for date
  @file date.cpp
  @author Arthur Vargas (ahvargas92@gmail.com)
*/

#include "date.h"

Date::Date( Month mm, int dd, Year yy )
{

  if ( dd < 1 || 31 < dd )
    throw InvalidDate{};

  m = mm;
  d = dd;
  y = yy;

}

Date::Date()
{

  m = Month::jan;
  d = 1;
  y = Year::min;
}

Year::Year( int yy )
{
  if ( yy < min || max < yy )
    throw InvalidYear{};
  y = yy;

}

Year::Year()
{
  y = min;

}
 
void Date::add_day( int n )
{
  for ( int i = 0; i < n; i++ )
    (*this)++;
}
  
Date &Date::operator++( int )
{
  if ( ( d == 30 && m == Month::apr ) || ( d == 30 && m == Month::jun ) || ( d == 30 && m == Month::sep ) ||
    
    ( d == 28 && m == Month::feb ) || ( d == 31 && m == Month::jan ) || ( d == 31 && m == Month::mar ) || 

    ( d == 31 && m == Month::may ) || ( d == 31 && m == Month::jul ) || ( d == 31 && m == Month::aug ) || 

    ( d == 31 && m == Month::oct ) || ( d == 31 && m == Month::nov ) ) {

    d = 1;
    m++;
    
  } else if ( d == 30 && m == Month::dec ) {

    m++;
    d = 1;
    y = y.getYear() + 1;
    

  }

  //month = (month == 12 && day == 30 ) ? 1 : ( month = month + 1 );

  return *this;

}

std::ostream &operator<<( std::ostream &os, const Date &d )
{
  // this may not work because << is not overloaded for printing classes year
  // m is an enum so it has one of only a set of integer values
  os << d.m << "/" << d.d << "/" << d.y;
  return os;

}

std::ostream &operator<<( std::ostream &out, const Year &yy )
{
  out <<  yy.y;
  return out;
}

std::ostream &operator<<( std::ostream &out, const Month &mm )
{
  out << mm;
  return out;
}

Month operator++( Month &m, int )
{
  m = (m==Month::dec) ? Month::jan : Month(int(m)+1); 
  return m;
}