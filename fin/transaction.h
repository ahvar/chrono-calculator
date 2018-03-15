/**
  Contains the transaction class records the exchange of a stock.
*/
#ifndef TRANSACTION_H_
#define TRANSACTION_H_
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
    @param p the exchange price
  */
  Transaction( Date &d, double p);

  /** Default constructor */
  Transaction(){}
  /**
    Transaction destructor
  */
  ~Transaction();

  friend std::ostream &operator<<(std::ostream &os, Transaction &t );

private:
  /** The date */
  Date date;
  /** Exchange price */
  double price;

};

#endif


