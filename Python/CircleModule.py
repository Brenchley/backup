import math
from PointModule import Point

class Circle(Point):
	"""Class that represents a circle"""

	def __init__(self,x=0, y=0, radiusValue = 0.0):
		"""Circle constructor takes center point and radius"""

		Point.__init__(self, x, y)
		self.radius = float(radiusValue)

	def area( self):
		"""Computes area of a circle"""

		return math.pi * self.radius ** 2

	def __str__(self):
		"""String representation of a circle"""

		# call base-class __str__ method
		return "Center = %s Radius = %f" % (Point.__str__(self), self.radius)

def main():
	circle = Circle(37,45,2.5) # create Circle object

	# print circle attributes
	print "X coordinate is:", circle.x
	print "Y coordinate is:", circle.y
	print "Radius is:", circle.radius

	circle.radius = 4.25
	circle.x = 3
	circle.y = 3

	print "\nThe new location and radius of circle are:", circle
	print "The area of circle is: %.2f" % circle.area()

	print

if __name__ == "__main__":
	main()