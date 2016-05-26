import math

class Point:
	"""class that represents geomeetric point"""

	def __init__(self, xValue =0, yValue = 0):
		"""Point constructor takes x and y coordinates"""

		self.x = xValue
		self.y = yValue

class Circle (Point):
	"""Class that represents a Circle"""

	def __init__(self, x = 0, y = 0, radiusValue = 0.0):
		"""Circle constructor takes x amd y coordinates of centre point and radius"""
		Point.__init__(self, x, y) # call base-class
		self.radius = float(radiusValue)

	def area(self):
		"""Computes area of Circle"""

		return math.pi * self.radius ** 2

# main program

# examine classes Point and Circle
print "point bases:", Point.__bases__
print "Circle bases:", Circle.__bases__

# demonstrate class relationships with built-in function issubclass
print "\nCircle is a subclass of point:", issubclass(Circle, Point)
print "Point is a subclass of Circle:", issubclass(Point, Circle)

point =  Point(30,23)
circle = Circle(120,89, 2.7)

# demostrate object relationship with built-in function isinstance
print "\nCircle is a point object:", isinstance(circle, Point)
print"point is a Circle object:", isinstance( point, Circle)

# print point and Circle objects
print "\npoint members:\n\t",point.__dict__
print "circle members:\n\t",circle.__dict__

print "\nArea of circle:", circle.area()

		