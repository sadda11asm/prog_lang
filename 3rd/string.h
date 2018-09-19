
#ifndef STRING_INCLUDED 
#define STRING_INCLUDED 1

#include <iostream> 
#include <cstring>

// p is always allocated, and len is the size of the string.

struct string
{
   size_t len;
   char *p; 


   	using iterator = char* ;
	using const_iterator = const char* ;
	const_iterator begin( ) const { return p; }
	const_iterator end( ) const { return p + len; }
	iterator begin( ) { return p; }
	iterator end( ) { return p + len; }
   // Default constructor currently switched off.
   // You may switch it on if you want. 

#if 0
   string( )
      : len{0},
        p{nullptr}
   {
      std::cout << "this is the default constructor\n";
   }
#endif

   string( const char* c )
      : len{ strlen(c) },
        p{ new char[ len ] }
   {
      for( size_t i = 0; i < len; ++ i )
         p[i] = c[i];
   }

   string( const string& s )
      : len{ s. len },
        p{ new char[ len ] } 
   {
      for( size_t i = 0; i < len; ++ i )
         p[i] = s.p[i];
  
      std::cout << "copy constructor\n";
   }

   char operator [] (size_t i) const {
   	if (i>=len || i<0) throw std::runtime_error("Out of the bounds!");
	return p[i]; 
   }

   char& operator [] (size_t i) {
	if (i>=len || i<0) throw std::runtime_error("Out of the bounds");
	return p[i];
   }

   size_t size() const {
   	return len;
   }
   string& operator = ( const string& s )
   {
      // Not only for efficiency, but also for assignment:

      if( len != s. len )
      {
         delete[] p;
         p = new char[ s. len ];
         len = s. len; 
      }
      for( size_t i = 0; i != len; ++ i )
         p[i] = s.p[i];

      std::cout << "assignment operator\n";
      return *this;
   }

   ~string( )
   {
      std::cout << "its the desctructor\n";

      delete[] p; 
   }

   string& operator += ( char c );
	

};

string& operator += ( string& s1, const string& s2 );

std::ostream& operator << ( std::ostream& out, const string& s );

string operator + ( string s1, const string& s2 );

bool operator == ( const string& s1, const string& s2 );
bool operator < ( const string& s1, const string& s2 );
   // add others as inline.

inline bool operator != ( const string& s1, const string& s2) {
   	return !(s1==s2);
}

inline bool operator > ( const string& s1, const string& s2 ) {
	if (s1==s2) return false;
	return !(s1<s2);
}

inline bool operator <= ( const string& s1, const string& s2) {
	if (s1==s2) return true;
	return (s1<s2);
}

inline bool operator >= ( const string& s1, const string& s2) {
	if (s1==s2) return true;
	return (s1>s2);
}
#endif


