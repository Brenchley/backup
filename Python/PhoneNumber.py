class PhoneNumber:
	"""Simple class to represent pone number in USA format"""
	def __init__(self, number):
		"""Accepts string in form (xxx) xxx-xxxx"""

		self.areaCode = number[1:4] #3-digit area code
		self.exchange = number[6:9] #3-digit excange code
		self.line = number[10:14] #4-digit line code

	def __str__(self):
		"""Informal string representation"""

		return "(%s) %s-%s" % (self.areaCode, self. exchange, self.line )

def test():
	#obtain phone nub=mber from user

	newNumber =raw_input("Enter phone number in the form (123) 456-7890:\n")

	phone = PhoneNumber(newNumber)
	print "The phone number is: ",
	print phone

if __name__ == "__main__":
	test()

