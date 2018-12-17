def gcd(n, m):
	if n == 0 and m == 0 :
		raise ArithmeticError( "gcd(0,0) does not exist" )
	if n < 0:
		n = abs(n)
	if m < 0:
		m = abs(m)
	if n == 0:
		return m
	if m == 0: 
		return n
	if n <= m:
		return gcd(n, m-n)
	return gcd(m, n-m)

from numbers import *
class Rational( Number ) :
	def normalize(self):
		x = gcd(self.num, self.denum)
		self.num = self.num//x
		self.denum = self.denum//x
		if self.num < 0 and self.denum < 0:
			self.num = abs(self.num)
			self.denum = abs(self.denum)
			return
		if self.denum < 0:
			self.denum = abs(self.denum)
			self.num = 0 - abs(self.num)
			return 
		return
	def __init__( self, num, denum = 1) :
		self. num = num
		self. denum = denum
		self. normalize( )
	def __repr__( self ):
		if self.denum == 1:
			return "{}". format( self. num )
		return "{}/{}". format( self.num, self.denum )
	def __neg__( self ) :
		return Rational(0 - self.num, self.denum)
	def __add__( self, other ) :
		if not isinstance(other, Rational) :
			other = Rational(other, 1)
		denum_gcd = gcd(self.denum, other.denum)
		quot1 = self.denum//denum_gcd
		quot2 = other.denum//denum_gcd
		num, denum = quot2*self.num + other.num*quot1, (other.denum*self.denum)//denum_gcd
		ans = Rational(num,denum)		
		ans. normalize( )
		return ans
	def __sub__( self, other) :
		if not isinstance(other, Rational) :
			other = Rational(other, 1)
		denum_gcd = gcd(self.denum, other.denum)
		quot1 = self.denum//denum_gcd
		quot2 = other.denum//denum_gcd
		num, denum = quot2*self.num - other.num*quot1, (other.denum*self.denum)//denum_gcd
		ans = Rational(num, denum)		
		ans. normalize( )
		return ans
	def __radd__ ( self, other ) :
		return self+other
	def __rsub__ ( self, other ) :
		if not isinstance(other, Rational) :
			other = Rational(other, 1)
		denum_gcd = gcd(self.denum, other.denum)
		quot1 = self.denum//denum_gcd
		quot2 = other.denum//denum_gcd
		num, denum = other.num*quot1 - quot2*self.num, (other.denum*self.denum)//denum_gcd
		ans = Rational(num, denum)		
		ans. normalize( )
		return ans
	def __mul__( self, other ) :
		if not isinstance(other, Rational) :
			other = Rational(other, 1)
		num, denum = self.num*other.num, self.denum*other.denum
		ans = Rational(num, denum)		
		ans. normalize( )
		return ans
	def __truediv__( self, other ) :
		if not isinstance(other, Rational) :
			other = Rational(other, 1)
		num, denum = self.num*other.denum, self.denum*other.num
		ans = Rational(num, denum)
		ans. normalize( )
		return ans
	def __rmul__( self, other ) :
		return self*other	
	def __rtruediv__( self, other ) :
		if not isinstance(other, Rational) :
			other = Rational(other, 1)
		num, denum = self.denum*other.num, self.num*other.denum
		ans = Rational(num, denum)		
		ans. normalize( )
		return ans




	
