class Employee:
	"""Empoyee class with static method isCrowded"""

	numberOfEmployees = 0 # number of Employees created
	maxEmployees = 10 # maix number of comfortable employees

	def isCrowded():
		"""Static method return true if the employees are crowded"""

		return Employee.numberOfEmployees > Employee.maxEmployees

	# create static method
	isCrowded = staticmethod(isCrowded)

	def __init__(self, firstName, lastName):
		"""Employee constructor takes first and last names"""

		self.first = firstName
		self.last = lastName
		Employee.numberOfEmployees +=1

	def __del__(self):
		"""Employee destructor"""

		Employee.numberOfEmployees -=1

	def __str__(self):
		"""String representation of Employee"""

		return "%s %s" % (self.first, self.last)

# main program
def main():
	answers = ["No", "Yes"] # responses to isCrowded

	employeeList=[] # list of objects of class Employee

	# call static method using class
	print "Employees are crowded?",
	print answers[Employee.isCrowded()]

	print "\nCreating 11 objects of class Employee..."

	# create 11 object of class Employee
	for i in range(11):
		employeeList.append(Employee("Josh", "Brenchley" + str(i)))

		# call static method using object
		print "Employee are crowded?",
		print answers[employeeList[i].isCrowded()]
	print "\nRemoving one employee..."
	del employeeList[0]

	print "Employees are crowded?", answers[Employee.isCrowded()]

if __name__ == "__main__":
	main()