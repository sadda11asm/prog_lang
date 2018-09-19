
#include "string.h"

// as usual: Take the functions out one by one when you write them.




string operator + ( string s1, const string& s2 ){
	s1+=s2;
	return s1;
}

string& string::operator += ( char c ) {
	len++;
	char* t = new char[len];
	for (size_t i=0;i<len-1;i++) 
		t[i]=p[i];
	t[len-1] = c;
	delete[] p;
        p = t;
	return *this;
}


string& operator += ( string& s1, const string& s2)  {
	size_t len2 = s2.len;
	for (size_t i=0; i<len2;i++) {
		s1+=s2[i];

	}
	return s1;
}
std::ostream& operator << ( std::ostream& out, const string& s )
{
	for( char c : s )
	out << c;
	return out;
}

bool operator == (const string& s1, const string& s2)  {
	if (s1.len!=s2.len) return false;
	for(size_t i =0;i<s1.len;i++) {
		if (s1[i]!=s2[i]) return false;	
	}
	return true;
}

bool operator < ( const string& s1, const string& s2 ) {
	size_t i = 0;
	if (s1.len==0 && s2.len==0) return false;
	if (s1.len==0) return true;
	if (s2.len==0) return false;
	while (s1[i]==s2[i]) {
		i++;	
	}
	return s1[i]<s2[i];
}


const string& greater( const string& s1, const string& s2 ) {
	if (s2>s1) return s2;
	return s1;
}



