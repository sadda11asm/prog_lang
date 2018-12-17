
#include "listtest.h"

#include <random>
#include <chrono>
#include <algorithm>
#include "timer.h"

std::list< std::string >
listtest::randomstrings( size_t nr, size_t s )
{
   static std::default_random_engine gen( 
      std::chrono::system_clock::now( ). time_since_epoch( ). count( ) );

   static std::string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ012345689";
   static std::uniform_int_distribution<int> distr( 0, alphabet. size( ) - 1 );


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

std::list<std::string> listtest::readfile( std::istream& input ) 
{
	std::list<std::string> result;
	std::string str;
	char c;
	while (input.get(c).good()) {
		if(isalpha(c)){
			str.push_back(c);
		} 
		else if(str.size()) {
			result.push_back(str);
			str = "";
		}
	}
        return result;
}


std::ostream& operator << ( std::ostream& out, const std::list< std::string > & l ) 
{ 
	out<< "{ ";
	for(std::list<std::string> :: const_iterator
		p = l.begin();
		p != l.end();
		++p )
	{
		if( p != l.begin())
			out<<", ";
		out<<"\""<< *p <<"\"";	
	}
	return out<<" }\n";
}

void listtest::sort_move( std::list< std::string > & l )
{
	timer t("list sort_move", std::cout);
	for(std::list<std::string> :: iterator
		p = l.end(); p != l.begin(); --p) {
		for(std::list<std::string> :: iterator
			it1 = l.begin(), it2 = ++l.begin(); 
			it2 != p;
			++it1, ++it2 ) {
			if( (*it2) < (*it1) ) {
				std::iter_swap(it1, it2);
			}				
		}
	}
}

void listtest::sort_assign( std::list< std::string > & l )
{
	timer t("list sort_assign", std::cout);
	for(std::list<std::string> :: iterator
		p = l.end(); p != l.begin(); --p) {
		for(std::list<std::string> :: iterator
			it1 = l.begin(), it2 = ++l.begin(); 
			it2 != p;
			++it1, ++it2 ) {
			if( (*it2) < (*it1) ) {
				std::string temp = *it1;
				*it1 = *it2;
				*it2 = temp;
			}				
		}
	}
}


