/**
  A market provides a set of functions for creating and trading securities. 
*/
#ifndef MARKET_H_
#define MARKET_H_
#include "../util/stockList.h"
#include "../util/filereader.h"
 
class Market {

public:
  /**
    Constructs a market.
    @param list a pointer to a list of stocks
  */
  Market( StockList *list );  

  /**
    Default constructor for Market class
  */
  Market();

  ~Market();

  StockList &getList() { return list; }

private:
  /** A list of Stocks */
  StockList list;
  
};

#endif