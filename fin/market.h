/**
  A market provides a set of functions for creating and trading securities. 
*/
#include "../util/date.h"
#include "transaction.h"
 
class Market {

  /**
    Constructs a market.
    @param list a pointer to a list of stocks
  */
  Market( StockList *list );  

  /**
    Default constructor for Market class
  */
  Market(){}

  ~Market();

private:
  /** A list of Transactions */
  std::vector<Transaction> reg;
  



};