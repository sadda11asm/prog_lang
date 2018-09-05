
#include "rational.h"

// Complete these methods:
 

int rational::gcd( int n1, int n2 ) {
	int a = std::abs(n1);
	int b = std::abs(n2);
	while(b>=1) {
		a=a%b;
		int x = a;
		a = b;
		b = x;	
	}	
	return a;
}

void rational::normalize( ) {
	int comdiv = gcd(num, denum);
	num/=comdiv;
	denum/=comdiv;
	if (denum<0) {
		num = -num;
		denum = -denum;	
	}
}

rational operator - ( rational r ) {
	return rational(-r.num, r.denum);
}

rational operator + ( const rational& r1, const rational& r2 ){
	int newnum = r1.num*r2.denum+r2.num*r1.denum;
	int newdenum = r1.denum*r2.denum;
	return rational(newnum, newdenum);
}

rational operator - ( const rational& r1, const rational& r2 ){
	int newnum = r1.num*r2.denum-r2.num*r1.denum;
	int newdenum = r1.denum*r2.denum;
	return rational(newnum, newdenum);
}

rational operator * ( const rational& r1, const rational& r2 ){
	int newnum = r1.num*r2.num;
	int newdenum = r1.denum*r2.denum;
	return rational(newnum, newdenum);
}

rational operator / ( const rational& r1, const rational& r2 ){
	int newnum = r1.num*r2.denum;
	int newdenum = r1.denum*r2.num;
	return rational(newnum, newdenum);
}

bool operator == ( const rational& r1, const rational& r2 ) {
	if (r1.num == r2.num && r1.denum == r2.denum) return true;
	return false;
}
bool operator != ( const rational& r1, const rational& r2 ) {
	if (r1.num!=r2.num || r1.denum!=r2.denum) return true;
	return false;
}

std::ostream& operator << ( std::ostream& out, const rational& r ) {
	if (r.denum == 1) out<<r.num;
	else out<<r.num<<"/"<<r.denum;
	return out;
}


