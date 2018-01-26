#include "portfolio.h"
#include "../util/location.h"


/**
  The FI is the base class for all types of financial institutions. It describes the functions and data values that all financial institutions have.
*/
class FI {

protected:
  /**
    Constructor for this FI
  */
  FI( std::string nm, std::vector<Location *> local ) : name(nm), locations(local) {}

  /**
    Default constructor for this financial institution
  */
  FI(){}

  /**
    Adds a physical location to this institution
    @param l the Location to be added to this FI
  */
  void addLocation( Location *l){ locations.push_back(l); }

  /**
    Returns a list of all physical locations for the financial institution
    @return a list of pointers to locations
  */
  std::vector<Location *> getAllLocations(){ return locations; }

  /**
    Sets the FI name to the String passed into the nm parameter
    @param nm the String to be set to FI name
  */
  void setName( std::string nm ){ name = nm; }

  /**
    Returns the name of the investment bank
    @return name the name of the bank
  */
  std::string getName(){ return name; }

  virtual void print() = 0;

private:
/** String representation of the institution's name */
std::string name;
/** A list of physical locations */
std::vector<Location *> locations;
  
};

/**
  The IB class represents an investment bank.
*/
class IB : public FI {

  /**
    Constructs the investment bank
    @param name the name of the IB
    @param locals a vector containing the locations for the IB
    @param pf a vector of portfolios managed on behalf of IB's customers
  */
  IB( std::string n, std::vector<Location *> l, std::vector<Portfolio *> pf ) : FI( n, l ) { investments = pf; } 

  /**
    Default constructor for this IB
  */
  IB();

  /**
    Get the list of portfolios contained at the investment bank.
    @return &investments a pointer to the first portfolio
  */
  std::vector<Portfolio *> getAllInvstmnt(){ return investments; }

  
  /**
    Overloads right shift operator for outputing information about the bank to the console.

    @param out a reference to the output stream
    @param ib a reference to the investment bank
  */
  friend std::ostream &operator<<( std::ostream &out, IB &ib );

  /**
    Prints the name of the bank and all of the Portfolios it contains.
  */
  void print(){ std::cout << this << std::endl; }

protected:
  /** A list of portfolios */
  std::vector<Portfolio *> investments;

};