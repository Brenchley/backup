class Employee:
	"""Class to represent an employee"""
	def  __init__(self, first, last):

		self.firstName = first
		self.lastName = last

	def __str__(self):
		"""String represent of am Employee"""

		return "%s %s" % (self.firstName, self.lastName)


class HourlyWorker(Employee):
	"""Class to represent an employee paid by hour"""

	def __init__(self, first, last, initHour, initWage):
		"""COnstructor for HourlyWorker, takes first and last name, initial number of hours and initial wage"""

		Employee.__init__(self, first, last)
		self.hours = float(initHour)
		self.wage = float(initWage)

	def getPay(self):
		"""Calculate HourlyWorker's weekly pay"""

		return self.hours * self.wage

	def __str__(self):
		"""String representation of HourlyWorker"""

		print "HourlyWorker.__str__ is executing"

		return "%s is an hourly worker with pay of $%.2f" % (Employee.__str__(self), self.getPay())


hourly = HourlyWorker("Lord", "Brenchley", 40.0, 15.00)

print "Calling __str__ method several ways. . ."
print hourly # invoke __str__ implicity
print hourly.__str__() # invoke __str__ explicitly
print HourlyWorker.__str__(hourly) # explicit, unbound call


