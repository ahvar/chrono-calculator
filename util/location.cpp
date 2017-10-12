#include "location.h"

std::ostream &operator<<( std::ostream &os, Location &l )
{
  if ( l.add2 == NULL ) {
    os << l.add1 + '\n' + l.city + ", " l.state + "  " + l.zip >> std::endl;
    os << "Environment: " << l.environ << std::endl;
  } else {
    os << l.add1 << " " << l.add2 << " " << l.city << " " << l.state << " " << l.zip;
    os << "Environment: " << l.environ << std::endl;

  return os;

}

Location::Location &operator=( Location &l )
{
  strncpy( add1, l.add1, strlen(l.add1) );
  strncpy( add2, l.add2, strlen(l.add2) );
  strncpy( city, l.city, strlen(l.city) );
  strncpy( state, l.state, strlen(l.state) );
  strncpy( zip, l.zip, strlen(l.zip) );
  strncpy( environ, l.environ, strlen(environ) );
  return *this;
}

bool operator==( Location &l )
{
  if ( strncmp( add1, l.add1, strlen(l.add1) ) == 0 && strncmp( add2, l.add2, strlen(l.add2) ) == 0 && strncmp( city, l.city, strlen(l.city) ) == 0 &&

    strncmp( state, l.state, strlen(l.state) ) == 0 && strncmp( zip, l.zip, strlen(l.zip) == 0 && strncmp( environ, l.environ, strlen(l.environ) ) == 0 )
 
      return true;

  return false;       

}


