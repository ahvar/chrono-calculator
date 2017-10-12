/**
  Location
  @file location.h
  @author Arthur Vargas (ahvargas92@gmail.com)
*/
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <cstdlib>

class Location {

public:

  /** 
    Constructs a location.

    @param a1 the address
    @param a2 the second part of the address (if there is one)
    @param c the name of the city
    @param s the state
    @param z the zip code
    @param e the environment
  */
  Location( std::string a1, std::string a2, std::string c, std::string s, std::string z, std::string e ) {
    add1 = a1; 
    add2 = a2; 
    city = c; 
    state = s; 
    zip = z; 
    environ = e;
  }

  /** 
    Constructs a location.
    @param a1 the address line
    @param c the city
    @param s the state
    @param z the zip code
    @param e the environment
  */
  Location( std::string a1, std::string c, std::string s, std::string z, std::string e  ) {
    add1 = a1; 
    city = c; 
    state = s; 
    zip = z; 
    environ = e;
  }
  /**
   The default constructor for the location
  */
  Location( ){}

  /**
    Prints all the location data fields to standard output
  */
  void print() { std::cout << this << std::endl; }

  /**
    The overloaded stream operator prints all the location data fields to standard output
    @param os a reference to the standard output stream
    @param l a reference to location to be output
    @return standard output stream
  */
  friend std::ostream &operator<<( std::ostream &os, Location &l );

  /**
    Overloaded assignment operator. Uses the strncpy function to copy the field from 'l' to the corresponding field of the assigning location (i.e. the operand on
    the left-hand side). The location passed into the function is the right-hand side operand.
    @param l a reference to the location
    @return this location 
  */
  Location &operator=( Location &l );

  /**
    Overloaded equality operator. Uses the strncmp function to compare each location data field. The length of the character array of a given data field in l1
    determines how many characters are compared.
    @param l1 a reference to the location
    @param l2 a reference to the location
    @return true if all of the data fields in a location are equivalent, false otherwise
  */
  bool operator==( Location &l );

private:
  /** The first line in the address */
  std::string add1;
  /** The second line in the address, if there is one */
  std::string add2;
  /** The city */
  std::string city;
  /** The abbreviation for the state */
  std::string state;
  /** The zip code */
  std::string zip;
  /** The environment. Either urban or rural */
  std::string environ;

};

