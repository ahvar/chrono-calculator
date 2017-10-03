/**
  Declares constants, data structures, classes, and functions for Day
  @file day.cpp
  @author Arthur Vargas (ahvargas92@gmail.com)
*/

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <cstdlib>
#include "list.h"
#define THIRTYDAYS 30
#define THIRTYONEDAYS 31

/**
  The Day class defines a day within the particular month of a given year
*/
class Day {

public:

  /** Constucts an instance of Day class with a name, number, hour, and minute.
      @param n the name of the day in the week
      @param num the number of the day in the month
      @param h the hour in the day
      @param m the minute in the hour
  */
  Day( Name n, int n, Hour h, Minute m ) {   today{n}, num{n}, hour{h}, minute{m} };

  /** Constructs an instance of the Day class with a name and number. The hour and minute are both set to zero.
      @param n the name of the day in the week
      @param num the number of the day in the month
      @param h the hour in the day
      @param m the minute in the hour
  */
  Day( Name n, int n ) { today{n}, num{n}, hour{0}, minute{0} };
  
  

private:
  /** the day in the month of a given year */
  int num;
  /** the hour in the day based on a 24-hour clock */
  Hour hour;
  /** the minute in an hour */
  Minute minute;
  /** the day of the week */
  enum Name today { saturday = 6, sunday , monday = 1, tuesday, wednesday, thursday, friday };
  /** a list of ongoing projects */
  List projects; 

};

/** Prefix increment operator
    @param d a reference to the day
    @return d return a reference to the day
*/
Day &operator++( Day &d, int );

/** Overloading right shift operator to print
    the day.
    @param d a reference to the day in the week
    @out a referencee to a output stream
    @return a reference to an output stream
*/
std::ostream &operator<<( std::ostream &out, Day &d );

/** Less than operator for day class
    @param d1 a reference to one of the days
    @param d2 a reference to one of the days
    @return true if d1 is less than d2
*/
Day &operator<( Day &d1, Day &d2 );

/** Greater than operator for day class
    @param d1 a reference to one of the days
    @param d2 a reference to one of the days
    @return true if the d1 is greater than d2
*/
Day &operator>( Day &d1, Day &d2 );