/**
  The implementation file for filereader.h
*/
#include "filereader.h"

void readFile( char *fn )
{
  std::ifstream ifs(fn);
  ifs.exceptions(std::ios_base::badbit | std::ios_base::failbit);
  ifs.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

Stock *FileReader::loadPrices()
{
  return NULL;
     

  

}

bool FileReader::isWhitespace( char c ) 
{
  for(char w : white)
    if(c == w) return true;
  return false;

}

FileReader::operator bool()
{
  return !(source.fail() || source.bad()) && source.good(); 
}


std::string &operator>>(std::string &input, FileReader &fr)
{
  
  return input;
}

std::string &operator<<(std::string &output, const FileReader &fr)
{
  
  return output;
}

bool FileReader::defineWhitespace()
{
  std::vector<std::string> vs;
  std::string line;
  while( getline(source,line) && !source.bad() ) {
    for (char &ch : line) { 
      if ( ch == ',')
        ch = ' ';
    }
    std::stringstream in{line};
    for(std::string word; in >> word;)
      vs.push_back(word);
    //for(std::vector<std::string>::iterator it = vs.begin(); it != vs.end(); ++it)
      //std::cout << ' ' << *it;
    //std::cout << '\n' << std::endl;
  }
  return true;
}

using namespace std;

int main(int argc, char *argv[])
{
  istringstream buffer;
  string name;
  if(argc > 1) {
    try {
      buffer.exceptions(ios_base::badbit);
      for(int i = 1; argv[i] ; i++) {
        buffer.getline( argv[i],strlen(argv[i]) );
        if(buffer.fail()) {
          cout << "An unexpected error occurred while reading the " << i << "th" << "file name." << endl;
          buffer.clear(ios_base::goodbit);
          continue;
        }
        readFile( argv[i] );
      }
    } catch(...) {
      if(buffer.bad()) throw;
      else if (buffer.fail())
        cout << "There was a problem reading the file name" << endl;
    }
  } else {
    cout << "Enter filename: " << endl;
    getline(cin,name);
    //buffer >> name.str();
    while(!cin.fail()) {
      cout << "Enter filename: " << endl;
      getline(cin,name);
    }
  }
  
  return 0;
}