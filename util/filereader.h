/**
  Header file for the filereader class, which reads price data from a text file and stores it into the respective value 
  fields in stocks and securities classes.
*/
#ifndef FILEREADER_H_
#define FILEREADER_H_

#include <vector>
//#include <exception>
#include <cstdio>
#include <sstream>
#include <cstring>
#include <iostream>
#include <fstream>
#include <limits>
#include <ios>
#include "../fin/security.h"

/**
  The FileReader class reads historical price data from text files and stores it in different data structures.
*/
class FileReader {
  
public:
  /**
    Construct FileReader from an input file stream.
    @param f reference to input file stream
  */
  //FileReader( std::fstream &f );

  /**
    Default constructor
  */
  FileReader(){}

  FileReader( std::string name ) { source.open(name, std::ios_base::in); sensitive = true; }

  /**
    Defines the characters to ignore when reading the input stream.
    @param s a reference to the string of characters classified as whitespace
  */
  void whitespace( const std::string &s ) { white = s; }

  /**
    Add character to be classified as whitespace to the existing set.
    @param c the character to be added to the user-defined set of whitespace
  */
  void addWhite(char c) { white += c; }

  /** 
    Returns true if 'c' is in the set of user-defined whitespace characters.
    .
    @param c the character that is either whitespace or  not
    @return true if 'c' is a whitespace character
  */
  bool isWhitespace( char c );

  /**
    Sets the sensitive data field to 'b'.
    @param b the boolean value to assign to data field called sensitive
  */
  void caseSensitive( bool b) { sensitive = b; }

  /**
    Returns the data field called 'sensitive'.

    @return sensitive the sensitive data field
  */
  bool isCaseSensitive() { return sensitive; }

  operator bool();
  
  /**
    Loads the price data and returns a list of stocks.  
    @throw exception if any problem reading files
    @return list of stocks
  */
  Stock *loadPrices();

  /**
    Sets the list of file pointers to FileReader's value field 'files'.
    @param fp pointer to the first element in a list of file pointers
  */
  void setFiles( FILE *fp ) {  } 

  /**
    Reads a text file with price data
    @param fn reference to string representation of filename
  */  
  void readFile( char *fn );

  /**
    Reads the file attached to the input file stream called source. 
  */
  bool defineWhitespace();
  /**
    Overloads the left shift operator to read into the FileReader.
    @param ifs reference input filestream
    @param file string representation of the file name
    @return reference to the input file stream
  */
  friend std::string &operator>>(std::string &input, FileReader &fr);

  /** 
    Overloads the right shift operator to write FileReader contents
    to file.
    @param ofs reference to output file stream
    @param file string representing the name of the file
    @return 
  */
  friend std::string &operator<<(std::string &output, const FileReader &fr);

private:
  
  /** Reference to i/o file stream*/
  std::fstream source;
  /** buffer to hold a line of input */
  std::istringstream buffer;
  /** an array of strings */
  std::vector<std::string> words;
  /** user-defined whitespace characters */
  std::string white;
  /** is the stream case sensitive */
  bool sensitive;
};


#endif