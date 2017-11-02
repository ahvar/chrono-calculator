/**
  Header file for the filereader class, which reads price data from a text file and stores it into the respective value fields in stocks and securities classes.
*/

#include <cstdio>
#include <iostream>
#include <vector>
//#include <exception>
#include <cstdlib>
#include "../fin/security.h"

/**
  The FileReader class contains operations for reading data price data from a text file.
*/
class FileReader {
  /**
    A FileReader can be constructed from a list of strings, each representing a relative file path for price data of a given stock or security.
    @param sList a list of file paths
  */
  FileReader( std::vector<std::string *> f );

  /**
    The default constructor for FileReader
  */
  FileReader(){}

  /**
    Loads the price data and returns a list of stocks.  
    @throw exception if any problem reading files
    @return list of stocks
  */
  std::vector<Stock *> loadStocks();

  /**
    Returns a list of pointers to file streams
    @return files the list of file pointers
  */
  std::vector<FILE *> getFiles(){ return files; }

private:
  /** Pointer to an input stream to historical stock pricing*/
  std::vector<FILE *> files;
};


