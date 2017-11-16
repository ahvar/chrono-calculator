/**
  A market provides a set of functions for creating and trading securities. 
*/
#include <cstdio>
#include <iostream>
#include <string>
#include <fstream>
#include "../util/tradingDay.h"
 
class Market {

  /**
    Constructs a market.
    @param s a pointer to a list of stocks
    @param td a pointer to a list of trading days
  */
  Market( Stock *s, TradingDay *td );

  Market( std::vector<string> fn );	

  /**
    Default constructor for Market class
  */
  Market(){}

  addPriceData( FILE f* );

private:
  /** Trading Days */
  std::vector<TradingDay *> days;
  /** A list of scurities on the market */
  std::vector<Security *> listings;
  /** A 2D grid where price movement is tracked */
  std::vector < std::vector<double> > record;
  /** A list of pointers to file objects containing price history */
  std::vector<FILE *> files; 

}: