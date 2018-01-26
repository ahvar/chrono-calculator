/**
  The analyzer header file declares the analyzer class and functions.
*/
#include "portfolio.h"
#include "../util/location.h"

string getFileNames();

void readFile( ifstream ifs )
{
  string line;
  while(ifs >> line)
    cout << line;


}

class Analyzer {
public:
  /** 
    Constructs an Analyzer with a portfolio of stocks.
    @param p the portfolio
  */
  Analyzer( Portfolio pf ) {  portfolio = pf; }
  
  /**
    Prints the 10, 50, 100, and 365 day price averages for a Stock of the given ticker (tkr). If the ticker is not found in the Analyzer's portfolio, an error
    message is printed to the console.
    
    @param tkr the ticker of the stock whose averages are output to the console
  */
  void prtStkAvgs( std::string tkr ); 

private:
  /** A portfolio of securities */
  Portfolio portfolio;  

};
