#include "market.h"


Market::Market( std::vector<string> fn )
{
  
  for( int i = 0; i < (int) fn.size(); i++ ) {
    std::ifstream ifs{ fn[i] };
    if(!ifs) std::error( "Unable to open file", fn[i] );
    addPriceData( ifs );
    ifs.close();
  }

}

Market::addPriceData( FILE *f )
{

  files.push_back(f);

}