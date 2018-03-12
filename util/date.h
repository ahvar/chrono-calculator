/**
  Declares constants, data structures, classes, and functions for Day
  @file day.cpp
  @author Arthur Vargas (ahvargas92@gmail.com)
*/
#ifndef DATE_H_
#define DATE_H_

#include <limits>
#include <ctime>
#include <istream>
#include <fstream>
#include <sstream>
#include <ostream>

/**
  The Day class defines a day within the particular month of a given year
*/
class Date {

public:

  /** Constucts an instance of Day class with a name, number, hour, and minute.
      @param d is the day of the month
      @param m the month
      @param y the year
  */
  Date( int d, int m, int y ) { tm_date.tm_mday = d; tm_date.tm_mon = m-1; tm_date.tm_year = y-1900; }

  /**
    The default contructor for Date
  */
  Date(){}
  
  /** Date destructor */
  ~Date(){}

  /** TODO: other useful constructors, getters, setters */


  friend std::ifstream &operator>>(std::ifstream &is, Date &dat);

  friend std::ostream &operator<<(std::ostream &os, const Date &dat);
  
private:

  tm tm_date;

};

#endif
