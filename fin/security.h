/**
  Defines the classes for different types of tradable financial assets. At the most basic level, a Security has a value
  and a market capitalization. Security is an abstract class and is the base class for Stock.
*/
#include <iostream>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cmath>

/**
 The Security class represents any kind of tradable financial asset 
*/
class Security {

protected:

  /**
    Constructor for Security. Only classes derived from Security are able to call it.
    @param v the value of the security in USD
  */
  Security( double v ) : value(v){} 

  /** 
    Default constructor for a security. Only classes derived from Security can call the default constructor for Security
  */
  Security(){};

  /**
    Returns the market capitalization for this security
    @return mktcap the market capitalization
  */
  virtual double getMktCap(){ return mktcap; }

  /**
    Returns the value for this security
    @return value the value of the security
  */
  double getValue(){ return value; }

  /**
    Prints detail about the Security
  */
  virtual void print() = 0;


  /** The value in USD */
  double value; 
  /** Market Capitalization */
  double mktcap;
};


/**
  A security that can be bought and sold. The stock has a name, a ticker, and a quantity of shares. The Stock can
  be bought by a trader or investment firm and the Stock can print out the issuing company.
*/
class Stock : public Security {

public:

  /** 
    Constructs a Stock with a name, ticker, and number of outstanding shares. The constructor sets the name and 
    ticker to the appropriate fields and calls thevissueOutstanding function to grow the share vector.

    @param nm the name of the company
    @param tkr the ticker of the company
    @param price the 
    @param qty the number of share to be issued by this stock
  */
  Stock( std::string nm, std::string tkr, double price, int qty ) :  Security( price ) { 
    name = nm;
    ticker = tkr;
    shares = qty;
  }

  /** Default constructor */
  Stock(){}

  /** 
    The destructor for the Stock class
  */
  ~Stock();

  /** 
    Adds a share at the current price to the list of shares and increments 'shares'.
    @param price the price of the share
  */
  void addShare( double p );

  /**
    A financial institution buys x number of shares of this stock.
    @param fi a pointer to the financial institution buying the shares
    @param x the number of shares to purchase
    @return true if the FI was able to buy the shares, false otherwise
  */
  bool buyStock( Security *s, int x );
  
  /** 
    Removes a share from the front, decrements the count of 'shares', and returns the price of the share.
    @return double the price 
  */
  double removeShare();

  /**
    Increases the total shares outstanding by the quantity passed in as an argument. Recalculates the market capitalization.

    @param qty the number of shares to be issued
    @return a reference to the vector of shares
  */  
  void issueShares( int qty );
 
  /** 
    Prints the name, ticker, stock price, and market cap
  */
  void print() { std::cout << this << std::endl; }

  /** 
    Overloads the right shift operator to output the Stock name, ticker, and the number of shares outstanding, to the console.
  
    @param out reference to ostream
    @param st reference to Stock to be output
    @return out reference to ostream
  */
  friend std::ostream &operator<<( std::ostream &out, Stock &st );

private:
  /** The name of the stock */
  std::string name;
  /** The ticker for the stock */
  std::string ticker;
  /** The number of shares currently */
  int shares;

  /** Enum of stock names */
  enum class StockName { CAH, HOG, DXTR, ARQL }; 

};
