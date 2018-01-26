/**
  Implements the functions from the analyzer class.
*/
#include "analyzer.h"
#include <fstream>
#define CAH "../data/CAH.txt"
#define HOG "../data/HOG.txt"

using namespace std;

void prtStkAvgs( Stock tkr )
{


}

Market *parseLine( string l, Market *m )
{


}

string *getFileNames()
{
  string fn;
  cout << "Enter filename: ";
  while(cin) {
    cin >> fn;
    ifstream ifs(fn);
    if(!ifs) cout << "Can't open file." << endl;
    readFile(ifs);
  }


}

int main()
{
  cout << "Welcome to Squire!" << endl;
  cout << "Squire helps you analyze price data for different kinds of tradable financial assets. Follow the prompts to specify which data you want to look at."; 
  cout << endl;

  vector<FILE *> = getFileNames();
  filenames[0] = &CAH;
  filenames[1] = &HOG;
  Market mkt( filenames );
 
  while ( ifs >> line )
    parseLine(line, mkt);
  
  
  
  return 0;

}


