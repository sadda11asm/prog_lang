
#include <fstream>
#include <iostream>
#include <random>

#include "listtest.h"
#include "vectortest.h"
#include "timer.h"


void vector_sort() {
	for (int nr= 10000; nr<50000; nr+=10000) {
	   std::cout<<"nr is equal to: "<<nr<<"\n";
	   std::vector< std::string > vect;
	   vect = vectortest::randomstrings(nr, 50);
	   //SORTING WITH MOVE

  	   vectortest::sort_move( vect );
 	   //std::cout << " Sorting with std::swap took: "<<d.count()<<" seconds\n";

	   //SORTING WITH USUAL ASSIGNMENT
	   vectortest::sort_assign( vect );
	   //std::cout << " Sorting with usual assignment took: "<<d.count()<<" seconds\n";
	   
	   //SORTING WITH QUICK SORT
	   vectortest::sort_std( vect );
	   //std::cout << " Sorting with std::sort: "<<d.count()<<" seconds\n";
   	}
}

void list_sort() {
	for (int nr= 1000; nr<10000; nr+=1000) {
	   std::cout<<"nr is equal to: "<<nr<<"\n";
	   std::list< std::string > l;
	   l = listtest::randomstrings(nr, 50);
	   //SORTING WITH MOVE

  	   listtest::sort_move( l );
 	   //std::cout << " Sorting with std::swap took: "<<d.count()<<" seconds\n";

	   //SORTING WITH USUAL ASSIGNMENT
	   listtest::sort_assign( l );
	   //std::cout << " Sorting with usual assignment took: "<<d.count()<<" seconds\n";
	   
	 
   	}
}



int main( int argc, char* argv [] )
{
	//INPUT FROM THE FILE

	std::vector< std::string > vect;

	std::ifstream inp{"input.txt"};
	vect = vectortest::readfile(inp);

   	std::cout << vect << "\n";

   // Or use timer:

	vector_sort();
	list_sort();

   return 0;
}

