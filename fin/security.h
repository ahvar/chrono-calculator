/**
  Defines the classes for different types of tradable financial assets.
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
  A security that can be bought and sold. The stock has a name, a ticker, and a quantity of shares.
*/
class Stock : public Security {
  struct Share {
    /** Share price */
    double price;
    /** Pointer to the next share */
    Share *next;
  }
  Share *head;

public:
  /** 
    Constructs a Stock with a name, ticker, and number of outstanding shares. The constructor sets the name and ticker to the appropriate fields and calls the
    issueOutstanding function to grow the share vector.
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
    Adds a share at this price to the stock
    @param price the price of the share
  */
  void addShare( double price );
  
  /** 
    Removes a share from the front
    @return double the price 
  */
  double removeShare();

  
  /**
    Increases the total shares outstanding by the quantity passed in as an argument. Recalculates the market capitalization.

    @param qty the number of shares to be issued
    @return a reference to the vector of shares
  */  
  void issueShares( int qty ) { shares += qty; mktcap = mktcap * shares; }
 
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


};
