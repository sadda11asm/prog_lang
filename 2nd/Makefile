main: main.o rational.o matrix.o
	g++ -o main main.o rational.o matrix.o -std=c++11

main.o : main.cpp rational.h matrix.h vector.h
	g++ -o main.o -c main.cpp -std=c++11

rational.o : rational.cpp rational.h
	g++ -o rational.o -c rational.cpp -std=c++11

matrix.o : matrix.cpp matrix.h rational.h
	g++ -o matrix.o -c matrix.cpp -std=c++11
