
#include "vectortest.h"
#include "timer.h"
#include <random>
#include <chrono> 
#include <algorithm>
#include <cctype>


std::vector< std::string >
vectortest::randomstrings( size_t nr, size_t s )
{
   static std::default_random_engine gen( 
      std::chrono::system_clock::now( ). time_since_epoch( ). count( ) );
         // Narrowing long int into int, but that is no problem.

   static std::string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ012345689";
   static std::uniform_int_distribution<int> distr( 0, alphabet. size( ) - 1 );
      // More narrowing.

   std::vector< std::string > res;

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
         
std::vector<std::string> 
vectortest::readfile( std::istream& input ) 
{
	std::vector<std::string> v;
	std::string s;
	char c;
	while (input.get(c).good()) {	
		if (!isalpha(c)) {
			if (s.size()!=0) {
				v.push_back(s);
				s. clear( );			
			}	
		} else 	s+=c; 		
	}
	return v;
}

std::ostream& operator << ( std::ostream& out, const std::vector< std::string > & vect ) 
{
	out<<"{";
	for (size_t i=0;i<vect.size();i++) {
		out<<" "<<vect[i];
		if (i!=vect.size()-1) {
			out<<",";		
		}	
	} 	
	out<<" }";
	return out;
}

void vectortest::sort_move( std::vector< std::string > &v ) {
	timer("sort_move", std::cout);
	for( size_t j = 0; j < v. size( ); ++ j )
	{
		for( size_t i = 0; i < j; ++ i ) {
			if( v[i] > v[j] )
				std::swap( v[i], v[j] );
		}
	}
}
void vectortest::sort_std( std::vector< std::string > & v) {
	timer("sort_std", std::cout);
	std::sort( v. begin( ), v. end( ));
}

void vectortest::sort_assign( std::vector< std::string > & v ) {
	timer("sort_assign", std::cout);
	for( size_t j = 0; j < v. size( ); ++ j )
		for( size_t i = 0; i < j; ++ i ) {
			if( v[i] > v[j] ) {
				std::string s = v[i];
				v[i] = v[j];
				v[j] = s;
			}
		}
}

