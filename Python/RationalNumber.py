def gcd(x,y):
	"""Computes greatest common divisor of two values"""

	while y:
		z = x
		x = y
		y = z % y

	return x

class Rational:
		"""Representation of rational number"""

		def __init__(self, top = 1, bottom = 1 ):
			"""Initializes Rational instances"""

			#do not allow 0 denominator
			if bottom == 0:
				raise ZeroDivisionError, "Cannot have 0 denominator"

			# assign attriubte values
			self.numerator = abs( top )
			self.denominator = abs( bottom )
			self.sign =( top * bottom) / (self.numerator * self.denominator )
			self.simplify() # Rtional represented in reduced form


		# class interfacw method
		def simplify( self ):
			"""Simplify a Rtional number"""

			common = gcd( self.numerator, self.denominator )
			self.numerator /= common
			self.denominator /= common

		# overloaded unary operaator
		def __neg__(self ):
			"""overloaded negation operator"""

			return Rational(-self.sign * self.numerator, self.denominator )

		# overloade binary arithmetic operators
		def __add__( self, other):
			"""Overloaded subtraction operator"""
			return self + (-other)

		def __mul__(self, other):
			"""Overloaded multiplication operator"""
			return Rational( self.numerator * other.numerator,
				self.sign * self.denominator *
				other.sign * self.denominator )

		def __div__(self, other):
			"""Overloaded / division operator"""

			return Rational(self.numerator * other.denominator,
							self.sign * self.denominator * 
							other.sign * other.denominator )

		def __truediv__(self, other ):
			"""Overloaded / division operator."""

			return self.__div__( other )

		def __eq__(self, other):
			"""overloaded equality operator"""

			return (self - other). numerator == 0

		def __lt__(self, other):
			"""Overloaded less-than operator"""

			return (self - other),sign < 0

		def __gt__(self, other):
			"""Overloaded greater-than operator"""

			return (self - other).sign > 0

		def __le__(self, other):
			"""overloaded less-than or equal-to operator"""

			return (self < other ) or (self == other )

		def __ge__(self, other):
			"""Overloaded greater-than or equal-to operator"""
			return (self > other) or ( self == other)

		def __ne__ (self, other):
			"""Overloaded inequality operator"""

			return not (self == other )

		# overloaded built-in function abs"""

			return Rational(self.numerator, self.denominator )

		def __str__(self):
			"""String representation"""

			#determine sign display
			if self.sign == -1:
				signString = "-"
			else:
				signString = ""

			if self.numerator == 0:
				return "0"
			elif self.denominator == 1:
				return "%s%d" % (signString, self.numerator)
			else:
				return "%s%d/%d" % (signString, self.numerator, self.denominator)
		#overloaded coercion capability		
		def __int__(self):
			"""Overloaded integer representation"""

			return self.sign * divmod(self.numerator, self.denominator )[ 0 ]

		def __float__(self):
			"""Overloaded floating-point representation"""

			return self.sign * float (self.numerator) / self.denominator

		def __coerce__(self, other):
			"""Overloaded coercion. Can only coerce int to Rational"""

			if type(other) == type(1):
				return (self, Rational(other))
			else:
				return None

