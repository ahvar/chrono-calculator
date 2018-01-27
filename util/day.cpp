#include "day.h"

Day::Day &operator++( Day &d, int ) 
{

  if ( d.today == Day::sunday )
    d.today = Day::monday;
  else if ( d.today == Day::monday )
    d.today = Day::tuesday;
  else if ( d.today == Day::tuesday )
    d.today = Day::wednesday;
  else if ( d.today == Day::wednesday )
    d.today = Day::thursday;
  else if ( d.today = Day::thursday )
    d.today = Day::friday;
  else if ( d.today = Day::friday )
    d.today = Day::saturday;
  else if ( d.today = Day::saturday )
    d.today = Day::sunday;

}

std::ostream &operator<<( std::ostream &out, Day &d )
{
  out << d.today << " " << d.hour << " " << "hours" << d.minute << " " << "minutes.";
  return out;

}


bool operator<( Day &d1, Day &d2 )
{
  int int1 = static_cast<int>(d1);
  int int2 = static_cast<int>(d2);
  if ( int1 < int2 )
    return true;
  else 
    return false;  
  

}


bool operator>( Day &d1, Day &d2 ) 
{

  int int1 = static_cast<int>(d1);
  int int2 = static_cast<int>(d2);
  if ( int1 > int2 )
    return true;
  else 
    return false;  

}