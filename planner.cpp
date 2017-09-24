/**
  The planner class 
*/

#include "date.h"
#include <cstdio>
#include <cstdlib>

using namespace std;

vector<Date> calendar;

int main()
{
  
  Date d { Month::feb, 01, Year{1988} };
  cout << " this is Holly's birthday " << endl;
  return 0;


}