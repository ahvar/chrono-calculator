/**
  The implementation file for filereader.h
*/
#include "filereader.h"
std::string delims = ",";
std::string dateDelim = "-";

void readLine( std::string &str, std::string &delims )
{
  std::vector<std::string> output;
  std::vector<std::string> date;
  double open, high, low, close, adjClose;
  long vol;
  for_each_token(str.cbegin(), str.cend(), delims.cbegin(), delims.cend(), [&output] (auto first, auto second) {
    if( first != second ) {
      output.emplace_back(first, second);
    }
  });
  for_each_token(output[0].cbegin(), output[0].cend(), dateDelim.cbegin(), dateDelim.cend(), [&date] (auto first, auto second) {
    if( first != second ) {
      date.emplace_back(first, second);
    }
  });
  open = stod(output[1]);
  high = stod(output[2]);
  low = stod(output[3]);
  close = stod(output[4]);
  adjClose = stod(output[5]);
  vol = stol(output[6]);
  std::cout << open << high << low << close << adjClose << vol << std::endl;
  
  /*
  double open, high, low, close, adjClose;
  long vol;
  Date date;
  
  std::istringstream iss(line);
  iss.exceptions(std::ios_base::badbit | std::ios_base::failbit);
  std::locale spaces(std::locale::classic(), new new_delimiter);
  iss.imbue(spaces);
  */

  try {
 
  } catch(...) {
    /*
      if(iss.fail()) {
        std::cout << "Something unexpected happened while reading a line." << std::endl;
      } else if(iss.bad()) {
        std::cout << "Something serious happened while reading a line." << std::endl;
      }
    */
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
      readLine(line, delims);
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
  string line;
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