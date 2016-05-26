
class Complex:
	"""Complex numbers pf the form realPart + imaginaryPart * i"""

	def __init__(self, real = 0, imaginary = 0 ):
		"""Assign values to realPart and imaginaryPart"""

		self.realPart = real
		self.imaginaryPart = imaginary

	def __add__(self,other):
		"""Returns the sum of two Complex instances"""

		real = self.realPart + other.realPart
		imaginary = self.imaginaryPart + other.imaginaryPart

		#Creat and return new complexNumber
		return Complex( real, imaginary)

	def __sub__(self, other):
		"""Returns the difference of two Complex instances"""

		real = self.realPart - other.realPart
		imaginary = self.imaginaryPart - other.imaginaryPart

		#create and return new complexNumber
		return Complex(real, imaginary)

	def __str__(self):

		return "%s %s" % (self.realPart, self.imaginaryPart)


def test():

	soph = Complex(23,34)

	print soph

if __name__== "__main__":
	test()