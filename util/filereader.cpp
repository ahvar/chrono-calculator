/**
  The implementation file for filereader.h
*/
#include "filereader.h"

FileReader( std::vector<std::string *> f )
{
  files = new FILE *();
  for ( std::vector<std::string *>::iterator it = f.begin(); it != f.end(); it++ ) {
    files = fopen(*it, "r");
    if ( files == NULL ) {
      std::cout << "Can't open " << *it << std::endl;
      exit(EXIT_FAILURE);
    }
    files++;
  }


}


std::vector<Stock *> FileReader::load()
{
  

}