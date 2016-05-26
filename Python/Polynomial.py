class Polynomial:
	"""Class to create Polynomial dictionary"""
	
	def __getitem__(self,key):
		"""overload key value"""

		return self.__polynomial1__[key]

	def __setitem__(self, key, value):
		"""Overloaded key-value assignment = creation"""

		self.__polynomial1__[key] = value

	def __delitem__(self,key):
		"""Overloaded key-value deletion"""

		del self.__polynomial1__[key]

	def __str__(self):
		"""Overloaded string representation"""

		return str(self.__polynomial1__)


	def __add__()
