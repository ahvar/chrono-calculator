/**
  The implementation file for filereader.h
*/
#include "filereader.h"

FileReader::FileReader( std::vector<std::string *> s )
{
  std::vector<std::FILE *> fptr;
  for ( std::vector<std::string *>::iterator it = s.begin(); it != s.end(); it++ ) {
    fptr = fopen(*it, "r");
    if ( fptr == NULL ) {
      std::cout << "Can't open " << *it << std::endl;
      std::exit(EXIT_FAILURE);
    }
    fptr.push_back(fptr);
    fptr++;
    
  }
  FileReader::setFiles( fptr );
  std::fclose(fptr);
}

void readFile( FILE *f )
{
  std::string s = new std::string(50);


}

Stock *FileReader::loadPrices()
{
  FILE *fptr = FileReader::getFiles();
  for ( std::vector<std::FILE *>::iterator it = FileReader::getFiles().begin(); it != FileReader::getFiles().end(); it++ )
     

  

}