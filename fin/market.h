/**
  A market provides a set of functions for creating and trading securities. 
*/
#include <cstdio>
#include <iostream>
#include <string>
#include <fstream>
#include "../util/tradingDay.h"
#include "../util/stockList.h"
 
class Market {

  /**
    Constructs a market.
    @param list a pointer to a list of stocks
    @param td a pointer to a list of trading days
  */
  Market( StockList *list );  

  /**
    Default constructor for Market class
  */
  Market(){}

private:
  /** A list of stocks on the market */
  StockList *sl; 

}: