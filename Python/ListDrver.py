from NewList import SingleList

def getIntegers():
	size = int(raw_input("list size"))

	returnList = []

	for i in range(size):
		returnList.append(int(raw_input("Integer %d: " % (i +1))))

	return returnList

#input and create intergers1 and integers2
print "Creating integers1..."
integers1 = SingleList(getIntegers() )

print "Creating integers2..."
integers2 = SingleList( getIntegers() )

#print integers1 size and contents
print "\nSize of list integers1 is", len(integers1)
print "List:\n", integers1

#print integers2 size and contents
print "\nSize of list integers2 is", len(integers2)
print "List: \n", integers2

#use overloaded comparison operator
print "Evaluating: integers1 != integers2"

if integers1 != integers2:
	print "They are not equal"

print "\nEvaluating: integers1 == integers2"

if integers1 == integers2:
	print "They are equal"

print "integers1[ 0 ] is", integers1[0]
print "Assigning 0 to integers1[0]"
integers1[0] = 0
print "integers1:\n", integers1

size= int(raw_input("Enter number of figures to be appended:"))

for i in range(size):
	integers1.append(int(raw_input("Value:")))

print integers1

print "\n Count of values in list:"
print integers1.count(4)

print "\n Index of list:"
print integers1.index(3)

print "\n List after running method insert:"
integers1.insert(2,69)
print integers1

print "\n List after running method pop:"
integers1.pop()
print integers1

print "\n List after running method remove:"
integers1.remove(5)
print integers1

print "\n List after running method reverse:"
integers1.reverse()
print integers1

print "\n List after running method sort:"
integers1.sort()
print integers1
