class SingleList( list):

	#construcor
	def __init__(self, initialList = None):
		"""SingleList construcor takes initialList value.
		New SingleList object contains only unique values"""

		list.__init__(self)

		if initialList:
			self.merge(initialList)


	# utility method

	def _raiseIfNotUnique(self, value):
		"""utility method to raise an exception if value is in list"""

		if value in self:
			raise ValueError, "List already contains value %s" % value


	# overloaded sequence operation
	def __setitem__	(self, subscript, value):
		"""Sets value of a particular index. Raises exception if list already contains value"""

		# terminate method on non-unique value
		self._raiseIfNotUnique(value)

		return list.__setitem__(self, subscript,value)

	# overloaded mathematical operators
	def __add__(self, other):
		"""overloaded addition operator, returns new SingleList"""

		return SingleList(list.__add__(self, other))

	def __radd__(self, otherList):
		"""overloaded right addition"""

		return SingleList(list.__add__(self, other))


	def __iadd__(self, other):
		"""overloaded augmented assignment. Raises exception if list already contains values in otherList"""

		for value in other:
			self.append(value)

		return self

	def __mul__(self, value):
		"""overloaded multiplication operator. Cannot use multiplication on SingleList"""

		raise ValueError, "Cannot repeat values in SingleList"

	# __rmul__ and __imul__ have the same behaviour as __mul__
	__rmul__ = __imul__ = __mul__

	# overridden list methods
	def insert(self, subscript, value):
		"""Inserts value at specified subscript. Raises exception if value already contains value"""

		# terminates method on non-unique value
		self._raiseIfNotUnique(value)

		return list.insert(self, subscript, value)

	def append(self, value):
		"""Appends value to end of list. Raises exception if list already contains value"""

		# terminates method on non-unique value
		self._raiseIfNotUnique(value)

		return list.append(self, value)

	def extend(self, other):
	 	"""Adds onto list the value from another list. Raises exception if list already contains value"""

	 	for value in other:

	 		self.append(value)

	 # new SingleList method

	def merge(self, other):
	 	"""Merges list with unique values from other list"""

		# add unique values from other
		for value in other:

	 		if value not in self:
	 			list.append(self, value)
