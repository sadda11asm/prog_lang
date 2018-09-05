
#include "rational.h"
#include "matrix.h"

int main( int argc, char* argv [ ] )
{

   rational r1( 2, 6 );
   rational r2( 4, 3 ); 
   rational r3( 5,6 );
   rational r4( 1, 2 );
	//rational r5( -2, 7 );
	//std::cout<<r5<<"\n";
   matrix m1 = { { {1,2}, {-2,7} }, { {1,3}, {2,8} } };
   std::cout << m1 << "\n";

   matrix m2 = { { {-1,3}, {2,5} }, { { 2,7 }, { -1,7 } } };
   std::cout << m2 << "\n";
	

   matrix m3 = { { {1,5}, {2,3} }, { { 2,7 }, { -2,3 } } };

   matrix m4 = m1 * m2; //1 & 2
   matrix m5 = m4*m3;
   matrix m6 = m2*m3;   //2 & 3
   matrix m7 = m1*m6;
	std::cout <<"FIRST!"<<"\n";
   std::cout << m5 << "\n";
   std::cout << m7 <<"\n";
   //std::cout << m1. inverse( ) << "\n";

	std::cout <<"SECOND!a"<<"\n";
	matrix m8 = m3*m1; // 3 & 1
	std::cout << m1*(m2+m3)<<"\n"<<m1*m2+m1*m3<<"\n";
	std::cout <<"SECOND!b"<<"\n";
	std::cout << m3*(m2+m1)<<"\n"<<m3*m2+m1*m3<<"\n";

	std::cout <<"THIRD!"<<"\n";
	std::cout<<m3*(m2*5)<<"\n"<<m3*m2*5<<"\n";
	std::cout <<"FOURTH!"<<"\n";
	std::cout<<m1.determinant()*m2.determinant()<<"\n"<<m4.determinant()<<"\n";

   std::cout << m1. determinant( ) << "\n";

   std::cout << m1. adjugate( ) << "\n";
   std::cout << m1. inverse( ) * m1 << "\n";
   std::cout << m1 * m1. inverse( ) << "\n";

}

