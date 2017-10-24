#include "security.h"
#include <vector>

/**
  Portfolio is a container for containing securities.
*/
class Portfolio {

public:
  
  /** 
    Constructs a portfolio from the list of stocks.
    
    @param list a list of pointers to Stocks.
  */
  Portfolio( std::vector<Stock *> list) : stocks(list){}

  /** Default constructor */
  Portfolio(){}

  /** 
    Overloads the right shift operator to output the Portfolio name, each stock in the portfolio, and the total amount invested, to the console.
     
    @param out reference to ostream
    @param ptfo reference to Portfolio to be output
    @return out reference to ostream
  */
  friend std::ostream &operator<<( std::ostream &out, Portfolio &ptfo );

private:
  /** The total value in the portfolio */
  double total;
  /** A list of stocks */
  std::vector<Stock *> stocks;

};