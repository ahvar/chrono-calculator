/**
  Defines the classes for different types of tradable financial assets. At the most basic level, a Security has a value
  and a market capitalization. Security is an abstract class and is the base class for Stock.
*/
#ifndef SECURITY_H_
#define SECURITY_H_

#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include "transaction.h"

/**
 The Security class represents any kind of tradable financial asset 
*/
class Security {

public:

  /**
    Constructor for Security. Only classes derived from Security are able to call it.
    @param r a list of Transactions for this security
  */
  Security(  std::vector<Transaction> r ) : high(r){} 

  Security( Transaction &t );

  Security( Transaction *t );

  Security( double price );

  /** 
    Default constructor for a security. Only classes derived from Security can call the default constructor for Security
  */
  Security(){};

  virtual ~Security();

  /**
    Returns the market capitalization for this security
    @return mktcap the market capitalization
  */
  virtual double getMktCap(){ return mktcap; }

  void addHigh( Transaction *t );

  std::vector<Transaction> &getHighPriceList() { return high; }

  void addOpen( Transaction *t );

  std::vector<Transaction> &getOpenPriceList() { return open; }
  
  void addClose( Transaction *t );

  std::vector<Transaction> &getClosePriceList() { return close; }
  
  void addLow( Transaction *t );

  std::vector<Transaction> &getLowPriceList() { return low; }
  
  void addAdjClose( Transaction *t ); 

  std::vector<Transaction> &getAdjClosePriceList() { return adjClose; }

  void addVolume( int vol );


  /**
    Prints detail about the Security
  */
  virtual void print() = 0;

protected:

  /** The highest transaction price per day */
  std::vector<Transaction> high; 
  /** The opening transaction price per day */
  std::vector<Transaction> open;
  /** The closing transaction price per day */
  std::vector<Transaction> close;
  /** The lowest transaction price per day */
  std::vector<Transaction> low;
  /** The adjacent closing price per day */
  std::vector<Transaction> adjClose;

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
  Stock( std::string nm, std::string tkr, std::vector<Transaction> r, int qty ) :  Security( r ) { 
    name = nm;
    ticker = tkr;
    shares = qty;
  }

  Stock( Transaction *t ) : Security( t ){ Transaction &trans = *t; high.push_back( trans ); }

  Stock( Transaction &t ) : Security( t ){ high.push_back( t ); }

  Stock( std::string nm, std::string tkr, double price ) : Security( price ) { name = nm; ticker = tkr; }

  /** Default constructor */
  Stock(){}

  /** 
    The destructor for the Stock class
  */
  ~Stock();

  /** 
    Adds a Transaction to the record
    @param t the Transaction
  */
  void addTransaction( Transaction &t );
  
  /** 
    Removes a share from the front, decrements the count of 'shares', and returns the price of the share.
    @return double the price 
  */
  bool removeTransaction();

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
    Sets the stock name to nm.
    @param nm the name of the stock
  */
  void setName( std::string nm) { name = nm; }


  /**
    Returns the name of the company for this stock.
    @param name the name of the company
  */
  std::string getName() { return name; }
  
  /**
    Sets the ticker to the ticker symbol passed in to parameter tkr
    @param tkr the ticker symbol used for this stock on the exchange
  */
  void setTicker( std::string tkr) { ticker = tkr; }

  /**
    Returns a string representation of ticker symbol.
    @return ticker the ticker
  */
  std::string getTicker() { return ticker; }

  /**
    Sets the quantity to the parameter q
    @param q the number of shares issued for this stock
  */
  void setQuantity( int q ) { shares = q; }

  /**
    Returns the number of shares
    @return shares the number of shares for this stock
  */
  int getQuantity() { return shares;}

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

#endif
