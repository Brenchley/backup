class SingleList:

	def __init__(self,initialList = None):
		"""Initializes SingleList instance"""

		self.__list = [] # internal list, contains no duplicates

		#process list passed to __init__, if necessary
		if initialList:

			for value in initialList:

				if value not in self.__list:
					self.__list.append(value) #add original value

	def __str__(self):
		"""Overloaded string representatioin"""

		tempString = ""
		i = 0

		# build output string 
		for i in range(len( self ) ):
			tempString += "%12d" % self.__list[i]

			if (i + 1) % 4 == 0: # 4 numbers per row of output
				tempString+="\n"

		if i % 4 != 0:# add newline, if necessary
			tempString += "\n"

		return tempString


	def __len__(self):
		"""Overloaded lenghth of the list"""

		return len(self.__list)

	def __getitem__(self, index):
		"""Overloaded sequence element access"""

		return self.__list[index]

	def __setitem__(self, index, value):
		"""Overloaded sequence  element assignment"""

		if value in self.__list:
			raise ValueError, "List already contains value %s" % str( value )

		self.__list[index] = value

		# overloaded equality operators
		def __eq__(self, other):
			"""Overloaded == operator"""

			if len(self) != len(other):
				return 0 # list of different sizes

			for i in range (0, len(self)):
				if self.__list[i] != other.__list[i]:
					return 0

			return 1
		def __ne__(self, other):
			"""Overloaded != and <> operators"""
			return not (self == other)


	def append(self, element):

		if element in self.__list:
			raise ValueError, "List already contains value %s" % str(element)


		self.__list.append(element)

	def count(self,element):

		return self.__list.count(element)

	def index(self,element):

		return self.__list.index(element)
 
	def insert(self,index,element):

		self.__list.insert(index,element)


	def pop(self):
		
		self.__list.pop()

	def remove(self,element):

		self.__list.remove(element)


	def  reverse(self):

		return self.__list.reverse()

	def sort(self):

		return self.__list.sort()



