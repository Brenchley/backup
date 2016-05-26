class Employee:
	"""Abstract base class Employee"""

	def __init__(self, first, last):
		"""Employee construcor, takes first name and last name.
		Note: Cannot create object of class Employee"""

		if self.__class__ == Employee:
			raise NotImplementedError, "Cannot create object of class Employee"


		self.firstName = first
		self.lastName  = last

	def __str__(self):
		"""String representation of Employee"""

		return "%s %s" % (self.firstName, self.lastName)

	def _checkPositive(self, value):
		"""Utility method to ensure a value is positive"""

		if value < 0:
			raise ValueError, "Attribute value (%s) must be positive" % value
		else:
			return value

	def earnings(self):
		"""Abstract method derived classes must override"""

		raise NotImplementedError, "Cannot call abstract method"

class Boss(Employee):
	"""Boss class inherits from Employee"""

	def __init__(self, first, last, salary):
		"""Boss construcor, takes first and last names and salary"""

		Employee.__init__(self, first, last)
		self.weeklySalary = self._checkPositive(float(salary))

	def earnings(self):
		"""Computes the Boss's pay"""

		return self.weeklySalary


	def __str__(self):
		"""String representation of Boss"""

		return "%17s: %s" % ("Boss", Employee.__str__(self))

class CommissionWOrker(Employee):
	"""CommissionWOrker class, inherits from Employee"""

	def __init__(self, first, last, salary, commission, quantity):
		"""CommissionWOrker construcor takes first and last names, salary, commission and quantity"""

		Employee.__init__(self, first, last)
		self.salary = self._checkPositive(float(salary))
		self.commission = self._checkPositive(float(commission))
		self.quantity = self._checkPositive(float(quantity))

	def earnings(self):
		"""Computes CommissionWOrker's earnings"""

		return self.salary + self.commission * self.quantity

	def __str__(self):
		"""String representation of CommissionWOrker"""
		return "%17s: %s" % ("Commission Worker", Employee.__str__(self))

class PieceWorker(Employee):
	"""PieceWorker class. inherits from Employee"""

	def __init__(self, first, last, wage, quantity):
		"""PieceWorker construcor, takes first and last names, wage and quantity"""

		Employee.__init__(self, first, last)
		self.wagePerPiece = self._checkPositive(float(wage))
		self.quantity = self._checkPositive(quantity)

	def earnings(self):
		"""Compute PieceWorker's pay"""

		return self.wagePerPiece * self.quantity	
	
	def __str__(self):
		"""String representation of PieceWorker"""

		return "%17s: %s" % ("Piece Worker", Employee.__str__(self))

class HourlyWorker(Employee):
	"""HourlyWorker class, inherits from Employee"""

	def __init__(self, first, last, wage, hours):
		"""HourlyWorker construcor takes first and last names, wage and hours"""

		Employee.__init__(self, first, last)
		self.wage = self._checkPositive(float(wage))
		self.hours = self._checkPositive(float(hours))

	def earnings(self):
		"""Compute HourlyWorker's pay"""
		if self.hours <= 40:
			return self.wage * self.hours
		else:
			return 40 * self.wage + (self.hours - 40) * self.wage * 1.5

	def __str__(self):
		"""String representation of HourlyWorker"""

		return "%17s: %s" % ("Hourly worker", Employee.__str__(self))
# main program

# create list of Employees
employees = [Boss("Josh", "Brenchley", 1690.00),
		 	 CommissionWOrker("Sue", "Moraya", 123.54, 4, 175),
		 	 PieceWorker("Bob", "Wayne", 3.75, 254),
		 	 HourlyWorker("Can","Wai Ho", 13.69, 54)]

for employee in employees:
	print "%s earned $%.2f" % (employee, employee.earnings())
