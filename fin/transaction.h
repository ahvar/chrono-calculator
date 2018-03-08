/**
  Contains the transaction class records the exchange of a stock.
*/
#ifndef TRANSACTION_H_
#define TRANSACTION_H_

#include "../util/stockList.h"
#include "../util/date.h"

/**
  The Transaction class represents the exchange of the Stock represented by the Stock private data field, the instance
  variable named 's', which occurred on the date represented by the private Date data field, the instance variable named
  'date'. 
*/ 
class Transaction {
	
public:  
  /**
    Constructs an instance of Transaction
    @param d reference to a Date
    @param s reference to a Stock
  */
  Transaction( Date &d, Stock &s );

  /** Default constructor */
  Transaction(){}
  /**
    Transaction destructor
  */
  ~Transaction();

private:
  /** The date */
  Date date;
  /** The Stock */
  Stock s;

};

#endif


