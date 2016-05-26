import math
from PointModule import Point
from CircleModule import Circle

class Cylinder( Circle):
	"""Class to represent a cylinder"""

	def __init__(self, x,y,radius, height):
		"""Constructor for cylinder takes x,y, height and radius"""

		Circle.__init__(self, x, y, radius)
		self.height = float( height)

	def area(self):
		"""Calculate (surface) area of Cylinder"""
		return 2 * Circle.area(self) + 2 * math.pi * self.radius * self.height

	def __str__(self):
		"""String representation of a Cylnder"""

		return "%s; Heigt = %.3f" % (Circle.__str__(self), self.height)

def main():

	cylinder =Cylinder(23,4,3.4,5.4)

	print "The X coordinate is:", cylinder.x
	print "The y coordinate is:", cylinder.y
	print "Radius is:", cylinder.radius
	print "Heigt is:", cylinder.height

	cylinder.height = 10
	cylinder.radius = 4.25
	cylinder.x, cylinder.y = 2, 3

	print "\nThe new point, radius and height of cylinder are:", cylinder
	print "\nThe area of cylinder is: %.2f" %cylinder.area()
	print "\ncylinder printed as a point is:", Point.__str__(cylinder)
	print "\ncylinder printed as a Circle is:", Circle.__str__(cylinder)


if __name__ == "__main__":
	main()

