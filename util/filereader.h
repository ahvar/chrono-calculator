/**
  Header file for the filereader class, which reads price data from a text file and stores it into the respective value 
  fields in stocks and securities classes.
*/
#ifndef FILEREADER_H_
#define FILEREADER_H_

//#include <exception>
#include <cstdio>
#include <string>
#include <iterator>
#include <cstring>
#include <iostream>
#include <locale>
#include <ios>
#include <algorithm>
#include "stockList.h"
#include "date.h"

template <class InputIt, class ForwardIt, class BinOp>
void for_each_token(InputIt first, InputIt last, ForwardIt s_first, ForwardIt s_last, BinOp binary_op)
{
  while(first != last) {
    const auto pos = std::find_first_of(first, last, s_first, s_last);
    binary_op(first, pos);
    if( pos == last ) break;
    first = std::next(pos);
  }

}


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

  /** FileReader destructor */
  ~FileReader(){}
  
  FileReader( std::string s ) { buffer.str(s); }

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
    Sets the buffer to the filename represented in the string named 's'..
    @param s the filename
  */
  void setBuffer( std::string s ){ buffer.flush(); buffer.str(s); }

  /**
    Loads the price data and returns a list of stocks.  
    @throw exception if any problem reading files
    @return list of stocks
  */  
  StockList &loadPrices( StockList &list );

  /**
    Reads the file attached to the input file stream called source. 
  */
  bool defineWhitespace();

  void askForName( std::string &s );

  void askForSymbol( std::string &s );
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
  std::ifstream source;
  /** buffer to hold a line of input */
  std::ostringstream buffer;
  /** an array of strings */
  std::vector<std::string> words;
  /** user-defined whitespace characters */
  std::string white;
  /** is the stream case sensitive */
  bool sensitive;
};


#endif