	
#include <iostream>
#include <fstream> 
#include <stdexcept>
#include <list>
#include <map> 
#include <unordered_map> 
#include <vector> 
#include <sstream>
#include "string.h"


int main( int argc, char* argv [ ] )
{
   

	

	string s1 = "Saddam";
	std::cout<<"-------------"<<"\n";
	string s2 = "hallo";
	std::cout<<"-------------"<<"\n";
	std::swap( s1, s2 );
	std::cout<<"-------------"<<"\n";
	std::cout << ( s1 + ", " + s2 ) << "\n";
	std::cout<<"-------------"<<"\n";
	std::cout << string( "this is a string" ) << "\n";
	std::cout<<"-------------"<<"\n";
	s2 = ( s1 + "!" );

	std::cout<<"\nNEXT\n";
	string zz = "zz";
	std::cout << "before:\n";
	string max = greater( greater( "aa", string( "b" ) + string( "c" )),
	greater( zz, string( "cc" )));
	std::cout << "after:\n";
	std::cout << "max = " << max << "\n";
   	return 0;
}




/*string s1 = "good";
   string s2 = " evening";
   s1+=s1;
   try {
   	std::cout<<s1<<std::endl;
   } catch (std::exception &ex) {
	std::cout<<ex.what()<<std::endl;
   }   
   string a = "aaaa";
   string b = "";
   std::cout<<(s1==s2)<<std::endl;
   std::cout<<(a<b)<<std::endl;
   if (s1!=s2) {
	std::cout<<1<<std::endl;
   }
*/

