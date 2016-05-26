class DemonstrateAccess(object):
	"""Class to demonstrate when method __getattribute__ executes"""

	def __init__(self):
		"""DemonstrateAccess constractor, initializes attribute value"""

		self.value = 1

	def __getattribute__(self, name):
		"""Executes for every attribute access"""

		print "__getattribute__ executing..."
		print "\tClient attempts to access attribute:", name

		return object.__getattribute__(self,name)


	def __getattr__ (self, name):
		"""Executes when client access attribute nor in __dict__"""

		print "__getattribute__ executing..."
		print "\tClient attempts to access non-existing attribute:", name

		raise AttributeError, "Object has no attribute %s" % name

def test():
	access = DemonstrateAccess()
	access.value

	

if __name__ == "__main__":
	test()