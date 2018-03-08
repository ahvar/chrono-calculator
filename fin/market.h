/**
  A market provides a set of functions for creating and trading securities. 
*/
#include "../util/date.h"
 
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

  /**
    The addPriceData function accepts a pointer to a text file with historical price data.
    @param f the pointer to the file containing the price data
  */
  void addPriceData( FILE *f);

private:
  /** A list of Transactions */
  vector<Transaction> register;
  



};