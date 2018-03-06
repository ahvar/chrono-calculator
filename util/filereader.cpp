/**
  The implementation file for filereader.h
*/
#include "filereader.h"


void readLine( std::string line )
{
  Stock *stock;
  Date *date;
  std::istringstream iss(line);
  std::string word;
  iss.exceptions(std::ios_base::badbit | std::ios_base::failbit);
  try {
    std::getline(iss,word,',');
      
  } catch(...) {
      if(iss.fail()) {
        std::cout << "Something unexpected happened while reading a line." << std::endl;
        continue;
      } else if(iss.bad())
        std::cout << "Something serious happened while reading a line." << std::endl;
    }
  }


}

void readFile( std::ostringstream &oss )
{

  std::ifstream ifs{oss.str()};
  std::string line;
  ifs.exceptions(std::ios_base::badbit | std::ios_base::failbit);
  ifs.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  while(ifs) {
    try {
      ifs >> line;
      readLine(line);
    } catch(...) {
      if(ifs.fail()) {
        std::cout << "Something unexpected happened while reading a file." << std::endl;
        continue;
      } else if (ifs.bad()) {
        std::cout << "Something serious happened while reading a file." << std::endl;
        exit(1);
      }
    }
  }
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
  ostringstream buffer;
  string name;
  if(argc > 1) {
    try {
      buffer.exceptions(ios_base::badbit);
      for(int i = 1; argv[i] ; i++) {
        buffer << argv[i];
        if(buffer.fail()) {
          cout << "An unexpected error occurred while reading file " << i << endl;
          buffer.clear(ios_base::goodbit);
          continue;
        }
        readFile( buffer );
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