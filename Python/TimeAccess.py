class Time:
	"""Class Time with customized attrbute access"""

	def __init__(self, hour = 0, minute = 0, second =0):
		"""Time constructor initialzed each data member to zero"""

		#each stetment invokes __setattr__
		self.hour = hour
		self.minute = minute
		self.second = second

	def __setattr__(self, name, value):
		"""Assigns s value to an attribute"""

		if name == "hour":
			if 0 <= value < 24:
				self.__dict__["_hour"] = value
			else:
				raise ValueError, "Invalid hour value: %d" % value

		elif name == "minute" or name == "second":

			if 0 <= value < 60:
				self.__dict__["_" + name ] = value
			else:
				raise ValueError, "Invalid %s value: %d" % (name, value)

		else:
			self.__dict__[ name ]= value

	def __getattr__(self, name):
		"""Performs lookup for unrecognized attribute name"""

		if name == "hour":
			return self._hour
		elif name == "minute":
			return self._minute
		elif name == "second":
			return self._second
		else:
			raise AttributeError, name

	def __str__( self ):
		"""Return Time object string in military format"""

		#attribute acces does not call __getattr__
		return "%.2d:%.2d:%.2d" % (self._hour, self._minute, self._second )


def test():

	time1 = Time(4,23,43)
	print time1
	print time1.hour, time1.minute, time1.second

	

if __name__ == "__main__":
	test()