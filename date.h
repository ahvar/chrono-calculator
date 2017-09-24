/**
  Declares constants, data structures, classes, and functions for Date
  @file date2.cpp
  @author Arthur Vargas (ahvargas92@gmail.com)
*/
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <cstdlib>

#define ONEYEAR 365 // days in a year 
#define TWENTYFOUR 24
#define SIXTY 60

/** The Months */
enum class Month {
  jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};

/** Prefix increment operator 
    @param m the memory address of the month
    @return m the month
*/
Month operator++( Month &m, int );

/** 
  Overloading operator for printing Month 

  @param out the output stream
  @param mm the memory address of this month
  @return out the output stream
*/
std::ostream &operator<<( std::ostream &out, const Month &mm );

/** 
  The Year class defines the range of acceptable years to be used within Date
*/
class Year {

public:

  static const int min = 1800;
  static const int max = 2220;

  /** This class indicates that the Year is invalid */
  class InvalidYear{};

  /** The constructor for Year.
      @param x the current year
      @throw Invalid if the year is not between the min and max
  */
  Year( int yy );

  /** A default constructor sets the year at the min*/
  Year();

  /** Returns the current Year 
      @return y the year
  */
  int getYear() { return y; }

  /** Overloaded << operator to print the year */
  friend std::ostream &operator<<( std::ostream &out, const Year &yy );

private:
  /** An integer representing the current year */
  int y;

};

/**
  The Date class defines the data and operations for a standard date with values for day, month, and year
*/
class Date {

public: 
  
  /** The date is invalid */
  class InvalidDate{};

  /**
    Constructs an instance of the Date class
    @param m the month
    @param d the day
    @param y the year
  */
  Date( Month mm, int dd, Year yy );

  /** 
    Default constructor sets the date to 01/01/1800.
  */
  Date();
 
  /**
    Adds 'n' days to this date
    @param n the number of days to be added
  */
  void add_day( int n );

  /**
    Overloaded postfix increment operator to increment date
  */
  Date &operator++( int );

  /** Overloaded << operator to print the Date */
  friend std::ostream &operator<<( std::ostream &out, const Date &d );

private:

  /** The Month */
  Month m;
  /** The day */
  int d;
  /** The year. Must fall between 1800 - 2099. */
  Year y;
  /** counts the hours */
  int h;
  /** counts the seconds */
  int s;

};

