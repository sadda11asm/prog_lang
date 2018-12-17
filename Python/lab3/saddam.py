from matrix import *
from vector import *
from rational import *

def tests():

	m1 = Matrix(Rational(1, 2), Rational(1, 3), Rational(-2, 7), Rational(2, 8))
	m2 = Matrix(Rational(-1, 3), Rational(2, 7), Rational(2, 5), Rational(-1, 7))
	print("Matrix m1 is :")
	print(m1)
	print("Matrix m2 is :")
	print(m2)	
	multi = m1@m2
	
	print("\nMULTIPLICATION\n")
	print("The Matrix m1*m2 is:")
	print(multi)
	
	print("\nCOMPUTING INVERSE\n")
	m1inv = m1.inverse()
	print("The inverse of m1 is:")
	print(m1inv)
	# Let take any matrix m3:
	m3 = Matrix(Rational(1, -3), Rational(2, 1), Rational(-2, -2), Rational(9, 3))
	print("The matrix m3 is: ")
	print(m3)
	
	print("\nCHECKING THE (m1 × m2) × m3 = m1 × (m2 × m3) \n")
	a1 = m1@m2
	a2 = m2@m3
	print("this is m1×m2: ")
	print(a1)
	print("this is m2×m3: ")
	print(a2)
	print("this is (m1×m2)×m3: ")
	res1 = a1@m3
	print(res1)
	print("this is m1×(m2×m3): ")
	res2 = m1@a2
	print(res2)
	print("this is (m1×m2)×m3 - m1×(m2×m3): ")
	print(res1 - res2)
	
	print("\nCHECKING THE multiplication with addition is distributive \n")
	print(" this is m1×(m2+m3): ")
	a1 = m1@(m2+m3)
	print(a1)
	print(" this is m1×m2+ m1×m3: ")
	a2 = m1@m2 + m1@m3 
	print(a2)
	print(" this is the difference between m1×(m2+m3) and m1×m2+ m1×m3: ")
	print(a1-a2)
	print(" this is (m1+m2)×m3: ")
	a1 = (m1+m2)@m3	
	print(a1)
	print(" this is m1×m3 + m2×m3: ")
	a2 = m1@m3 + m2@m3 
	print(a2)
	print(" this is the difference between m1×(m2+m3) and m1×m2+ m1×m3: ")
	print(a1-a2)
	
	print("\nCHECKING THE matrix multiplication corresponds to composition of application \n")
	v = Vector(3, -1)
	print ("this is vector v: ")
	print(v)
	print ("this is m2(v): ")
	a1 = m2(v)
	print(a1)
	print ("this is m1(m2(v)): ")
	b1 = m1(a1)
	print(b1)
	print ("this is m1×m2: ")
	a2 = m1@m2
	print(a2)
	print ("this is (m1×m2)(v): ")
	b2 = a2(v)
	print(b2)
	print("this is difference between m1(m2(v)) and (m1×m2)(v): ")
	print(b1 - b2)

	print("\nCHECKING THE  determinant commutes over multiplication \n")
	a1 = m1.determinant()
	a2 = m2.determinant()
	b1 = a1*a2
	a3 = m1@m2
	b2 = a3.determinant()
	print ("this is det(m1): ")
	print(a1)
	print ("this is det(m2): ")
	print(a2)
	print ("this is det(m1).det(m2) ")
	print(b1)
	print ("this is det(m1×m2): ")
	print(b2)
	print ("this is difference between det(m1).det(m2) and det(m1×m2): ")
	print(b1-b2)

	print("\nCHECKING THE inverse of matrix is indeed inverse \n")
	a1 = m1@m1inv
	a2 = m1inv@m1
	print("this is m1inv×(m1): ")
	print(a1)
	print("this is inv(m1)×m1: ")
	print(a2)
	print("So, they are both equal to identity matrix of size 2 ")			
