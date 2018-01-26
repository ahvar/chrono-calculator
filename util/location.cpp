#include "location.h"

std::ostream &operator<<( std::ostream &os, Location &l )
{
  os << l.add1 << " " << l.add2 << " " << l.city << " " << l.state << " " << l.zip << std::endl;
  os << "Latitude: " << l.lat << std::endl;
  os << "Longitude: " << l.lng << std::endl;
  os << "Environment: " << l.environ << std::endl;
  
  return os;

}

Location &Location::operator=( const Location &l )
{
  add1 = l.add1;
  add2 = l.add2;
  city = l.city;
  state = l.state;
  zip = l.zip;
  environ = l.environ;
  lat = l.lat;
  lng = l.lng;
  return *this;
}

bool operator==( const Location &l1, const Location &l2 )
{
  if ( l1.add1 == l2.add2 && l1.add2 == l2.add2 && l1.city == l2.city && l1.state == l2.state && l1.zip == l2.zip && l1.environ == l2.environ &&
    
    l1.lat == l2.lat && l1.lng == l2.lng )

      return true;

  return false;       

}


