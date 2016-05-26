class SimpleDictionary:
	"""Class to make an instance behave like a dictionary"""

	#mapping special methods
	def __getitem__(self, key):
		"""Overloaded key_VAlue access"""

		return self.__dict__[key]

	def __setitem__(self, key, value):
		"""Overloaded key-value assignment =creation"""

		self.__dict__[key] = value

	def __delitem__(self,key):
		"""Overloaded key-value deletion"""

		del self.__dict__[key]

	def __str__(self):
		"""Overloaded srting representation"""

		return str(self.__dict__)

	# common mapping methods
	

	def get(self, key):

		return self.__dict__.get(key)

	def has_key(self, key):

		return self.__dict__.has_key(key)

	def update(self, otherMapping):

		self.__dict__.update(otherMapping)

	def clear(self):

		self.__dict__.clear()

	def keys(self):
		"""Returns list of keys in dictionary"""

		return self.__dict__.keys()

	def values(self):
		"""Returns list of values in dictionary"""
		return self.__dict__.values()

	def item(self):
		"""Returns list of items in dictionary"""

		return self.__dict__.items()

	def copy(self):

		return self.__dict__.copy()