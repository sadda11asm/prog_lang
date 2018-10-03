
#include <fstream>
#include <iostream>
#include <random>
#include <map>
#include <unordered_map>

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


struct case_insensitive_hash {
	size_t operator ( ) ( const std::string& s ) const {
		size_t hash = 0;
		for (size_t i = 0; i<s.length();i++) {
			char c = std::tolower(s[i]);
			hash+=i*(c-'a'+1);
		}	
		return hash;
	}
};

struct case_insensitive_equality {
	bool operator ( ) ( const std::string& s1, const std::string& s2 ) const {
		if (s1.length() != s2.length()) return false;
		size_t smallest = (s1.length()< s2.length()) ? s1.length() : s2.length();
		for (size_t i = 0; i < smallest;i++) {
			char c1 = std::tolower(s1[i]);
			char c2 = std::tolower(s2[i]);
			if (c1!=c2) return false;
		}	
		return true;
	}
};
struct case_insensitive_cmp {
	bool operator( ) ( const std::string& s1, const std::string& s2 ) const {
		size_t smallest = (s1.length()< s2.length()) ? s1.length() : s2.length();
		for (size_t i = 0; i < smallest;i++) {
			char c1 = std::tolower(s1[i]);
			char c2 = std::tolower(s2[i]);
			if (c1<c2) return true;
			if (c1>c2) return false;		
		}	
		return s1.length()<s2.length();
	}
	// Return true if s1 < s2, ignoring case of the letters.
	
};


std::unordered_map< std::string, unsigned int,case_insensitive_hash, case_insensitive_equality > hashed_frequencytable( const std::vector< std::string > & text ) {
	std::unordered_map< std::string, unsigned int, case_insensitive_hash, case_insensitive_equality> m;
	for (size_t i=0; i<text.size(); i++) {
		//if (m.find(text[i])==m.end()) m[text[i]] = 0;
		m[text[i]]++;
	}
	return m;
}
std::map< std::string, unsigned int, case_insensitive_cmp > frequencytable( const std::vector< std::string > & text ) {
	std::map< std::string, unsigned int, case_insensitive_cmp> m;
	for (size_t i=0; i<text.size(); i++) {
		//if (m.find(text[i])==m.end()) m[text[i]] = 0;
		m[text[i]]++;
	}
	return m;
}

std::ostream& operator << ( std::ostream& stream, 
const std::map< std::string, unsigned int, case_insensitive_cmp > & freq ) {
	for (auto & x: freq) {
		stream<<x.first<<" "<<x.second<<std::endl;	
	}
	return stream;
}

std::ostream& operator << ( std::ostream& stream, 
const std::unordered_map< std::string, unsigned int,case_insensitive_hash, case_insensitive_equality > & freq) {
	for (auto & x: freq) {
		stream<<x.first<<" "<<x.second<<std::endl;	
	}
	return stream;
}

std::string mostfrequent (std::map< std::string, unsigned int, case_insensitive_cmp > m) {
	unsigned int maxf = 0;
	std::string val;	
	for (auto & x: m) {
		if (x.second>maxf) {
			val = x.first;
			maxf = x.second;
		}
	}
	std::cout<<"\nfrequency: "<<maxf<<std::endl;
	return val;
} 


int main( int argc, char* argv [] )
{
	//INPUT FROM THE FILE

	std::vector< std::string > vect;

	std::ifstream inp{"input.txt"};
	vect = vectortest::readfile(inp);

   	//std::cout << vect << "\n";

	//std::vector<std::string > check = { "A", "a", "th", "AA", "aA", "Aa", "this", "THIS" };
	std::map<std::string, unsigned int, case_insensitive_cmp> frequency = frequencytable(vect);

	std::cout << frequency;


	std::cout << "magnus : " << frequency["magnus"] << "\n";

	std::cout << "hominum : " << frequency["hominum"] << "\n";

	std::cout << "memoria : " << frequency["memoria"] << "\n";

	std::cout << "et : " << frequency["et"] << "\n";

	std::cout<< "Most frequent " << mostfrequent(frequency) << std::endl;

	
	case_insensitive_cmp c;
	std::cout << c( "a", "A" ) << c( "a","b" ) << c( "A", "b" ) << "\n";

	case_insensitive_hash h;
	std::cout << h( "xxx" ) << " " << h( "XXX" ) << "\n";
	std::cout << h( "Abc" ) << " " << h( "abC" ) << "\n";

	case_insensitive_equality e;
	std::cout << e( "xxx", "XXXX" ) << "\n";
	//vector_sort();
	//list_sort();

   return 0;
}

