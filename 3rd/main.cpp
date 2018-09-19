
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
   string s1 = "good";
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
   return 0;
}


