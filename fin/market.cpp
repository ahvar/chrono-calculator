#include "market.h"

Market::Market()
{
  
  
}

using namespace std;

int main(int argc, char *argv[])
{ 
  Market *mkt = new Market();
  if(argc > 1) {

  	/** new FileReader created from the first filename in the argument vector. load the price data into the StockList */
  	FileReader *fr = new FileReader(argv[1]);
    fr->loadPrices(mkt->getList());

    try {
      //fr.buffer.exceptions(ios_base::badbit);
      for(int i = 2; argv[i] ; i++) {
        fr->setBuffer(argv[i]);
        fr->loadPrices(mkt->getList());
        /*
        if(buffer.fail()) {
          cout << "An unexpected error occurred while reading file " << i << endl;
          buffer.clear(ios_base::goodbit);
          continue;
        }
        std::cout << buffer.str() << std::endl;
        readFile( buffer );
        buffer.str("");
        buffer.clear();
        */
      }
    } catch(...) {
    	/*
      if(buffer.bad()) throw;
      else if (buffer.fail())
        cout << "There was a problem reading the file name" << endl;
        */
    }
  } else {
    cout << "Enter filename: " << endl;
    //getline(cin,name);
    //buffer >> name.str();
    while(!cin.fail()) {
      cout << "Enter filename: " << endl;
      //getline(cin,name);
    }
  }
  
  return 0;
}