/**
  Implementation file for trading day
  @file tradingDay.cpp
  @author Arthur Vargas (ahvargas92@gmail.com)
*/

#include "tradingDay.h"

TradingDay::TradingDay( Month mm, int dd, Year yy )
{

  if ( dd < 1 || 31 < dd )
    throw InvalidDate{};

  m = mm;
  d = dd;
  y = yy;

  

}

TradingDay::TradingDay()
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
 
void TradingDay::add_day( int n )
{
  for ( int i = 0; i < n; i++ )
    (*this)++;
}
  
TradingDay &TradingDay::operator++( int )
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


std::ostream &operator<<( std::ostream &os, const TradingDay &d )
{
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
  int num = static_cast<int>(mm);
  out << num;
  return out;
}

Month &operator++( Month &m, int )
{
  m = (m==Month::dec) ? Month::jan : Month(int(m)+1); 
  return m;
}

bool operator<( Month m1, Month m2 )
{
  int int1 = static_cast<int>(m1);
  int int2 = static_cast<int>(m2);
  if ( int1 < int2 )
    return true;
  else 
    return false;

}

bool operator>( Month m1, Month m2 )
{
  int int1 = static_cast<int>(m1);
  int int2 = static_cast<int>(m2);
  if ( int1 > int2 )
    return true;
  else 
    return false;

}