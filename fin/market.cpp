#include "market.h"

Market::Market()
{
  StockList *s = new StockList();
  StockList &sl = *s;
  list = sl;
}

Market::Market( StockList *l )
{
  StockList &lst = *l;
  list = lst;

}

using namespace std;

int main(int argc, char *argv[])
{ 
  Market *mkt = new Market();
  FileReader fr;
  
  if(argc > 1) {

    try {

      for(int i = 1; argv[i] ; i++) {
      	
        fr.setBuffer(argv[i]);
        fr.loadPrices(mkt->getList());
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
  
  //std::cout << mkt->getList() << std::endl;
  return 0;
}