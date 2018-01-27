/**
  Header file for the filereader class, which reads price data from a text file and stores it into the respective value 
  fields in stocks and securities classes.
*/
#ifndef FILEREADER_H_
#define FILEREADER_H_

#include <vector>
//#include <exception>
#include "../fin/security.h"

/**
  The FileReader class reads historical price data from text files and stores it in different data structures.
*/
class FileReader {
  /**
    A FileReader can be constructed from a list of strings, each representing a relative file path for price data of a 
    given stock or security.
    @param f a pointer to FILE
  */
  FileReader( std::FILE *f );
  
  /**
    A FileReader can be constructed from a list of strings, each representing a filename or filepath.
    @param s a list of filenames
  */
  FileReader( std::vector<std::string> s );

  /**
    The default constructor for FileReader
  */
  FileReader(){}

  /**
    Loads the price data and returns a list of stocks.  
    @throw exception if any problem reading files
    @return list of stocks
  */
  Stock *loadPrices();

  /**
    Returns a list of pointers to file streams
    @return files the list of file pointers
  */
  std::FILE *getFiles(){ return files; }

  /**
    Sets the list of file pointers to FileReader's value field 'files'.
    @param fp pointer to the first element in a list of file pointers
  */
  void setFiles( FILE *fp ) { files = fp; } 

  /**
    Reads a text file with price data
    @param f a pointer to the file object
  */
  void readFile( FILE *f );

private:
  /** Pointer to an input stream to historical stock pricing*/
  std::vector<FILE *> files;
  /** price data */
  std::vector<string> data;
};


#endif