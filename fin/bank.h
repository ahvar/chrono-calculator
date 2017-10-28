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
  FI( std::String nm, std::vector<Location> local ) : name(nm), locations(local) {}

  /**
    Default constructor for this financial institution
  */
  FI(){}

  /**
    Adds a physical location to this institution
    @param l the Location to be added to this FI
  */
  addLocation( Location l);

  /**
    Sets the FI name to the String passed into the nm parameter
    @param nm the String to be set to FI name
  */
  setName( std::String nm ) : name(nm){}

  virtual void print() = 0;

private:
/** String representation of the institution's name */
std::String name;
/** A list of physical locations */
std::vector<Location> locations;
  
}

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
  IB( std::String name, std::vector<Location> locals, std::vector<Portfolio *>Portfolio pf ) : IF( name, locals) { investments = pf; }

  /**
    Default constructor for this IB
  */
  IB();

  /**
    Overloads right shift operator for outputing information about the bank to the console.
    @param out a reference to the output stream
    @param ib a reference to the investment bank
  */
  friend std::ostream &operator<<( std::ostream &out, IB &ib );

protected:
  /** A list of portfolios */
  vector<Portfolio *> investments;

};