
#include "listtest.h"
#include "timer.h"

#include <random>
#include <chrono>
#include <algorithm>


std::list< std::string > listtest::randomstrings( size_t nr, size_t s )
{
   static std::default_random_engine gen( 
      std::chrono::system_clock::now( ). time_since_epoch( ). count( ) );
         // Narrowing long int into int, but that is no problem.

   static std::string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ012345689";
   static std::uniform_int_distribution<int> distr( 0, alphabet. size( ) - 1 );
      // More narrowing.

   std::list< std::string > res;

   for( size_t i = 0; i < nr; ++ i )
   {
      std::string rand;
      for( size_t j = 0; j < s; ++ j )
      {
         rand. push_back( alphabet[ distr( gen ) ] );  
      }

      res. push_back( std::move( rand ));
   }
   return res;
}
void listtest::sort_move( std::list< std::string > & l )
{
	for (std::list<std::string> :: iterator it = l.begin();it!=l.end();it++) {
			std::list<std::string>::iterator it2;
		for (it2 = l.begin();it2!=it;it2++) {
			if (*it2>*it) {
				std::swap(*it, *it2);			
			}
		}	
	}
}




std::list<std::string> 
listtest::readfile( std::istream& input ) 
{
	std::list<std::string> v;
	std::string s;
	char c;
	while (input.get(c).good()) {	
		if (!isalpha(c)) {
			if (s.size()!=0) {
				v.push_back(s);
				s ="";			
			}	
		} else 	s+=c; 		
	}
	return v;
}

std::ostream& operator << ( std::ostream& out, const std::list< std::string > & l ) 
{
	out<<"{";
	for (auto it=l.begin();it!=l.end();it++) {
		if (it!=l.begin()) {
			out<<",";		
		}	
		out<<*it<<" ";
	} 	
	out<<" }";
	return out;
}


void listtest::sort_assign( std::list< std::string > & v ) {
	timer("sort_assign", std::cout);
	std::list<std::string>::iterator it;
	for (it = v.begin();it!=v.end();it++) {
		std::list<std::string>::iterator it2;
		for (it2 = v.begin();it2!=it;it2++) {
			if( *it2 > *it ) {
				std::string s = *it;
				*it = *it2;
				*it2 = s;
			}
		}
	}
}




