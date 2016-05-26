# prompting user to enter file name

print ("The purpose of this assignment is to understand function and file.\n")
while 1:

	f= input("Enter name of file")
	try:
		
		file = open(f, "r")
		if file:
			break
	except IOError:
		print (" %s does not exist")% f
		

# function to print out the records
def printRecords(foo):
	records = foo.readlines()
	print ("Student ID".ljust(10)),
	print ("Score".ljust(10)),
	print ("Grade".ljust(10))
	

	for record in records:
		fields = record.split()
		print (fields[0].ljust(5)),
		print (fields[1].ljust(5)),
		print (letter_grade(float(fields[1])))
# function to get letter_grades	
def letter_grade(score):
	if score >= 90:
		return 'A'
	elif score >=80:
		return 'B'
	elif score >= 70:
		return 'C'
	elif score >= 60:
		return 'D'
	elif score >= 50:
		return 'E'
	else:
		return 'F'
# function to get number of records
def NumberOfStudents(foo):
	f = open(foo, 'r')
	lines = int(len(f.readlines()))
	return lines	
# function to get average
def Average(foo):
	f = open(foo, 'r')
	totals = 0
	records = f.readlines()
	for record in records:
		fields = record.split()
		
		totals += float(fields[1])
	return totals/NumberOfStudents(foo)

# function to get student with highest score
def highestScore(foo):
	f = open(foo, 'r')
	score={} #initialize an empty dictionary
	i=0
	records = f.readlines()
	for record in records:
		fields = record.split()
		for i in range(NumberOfStudents(foo)):
			score[fields[0]] = float(fields[1])
	top = max(score.values())
	print ("\n"),score.keys()[list(score.values()).index(top)], ("has the highest score of"), top
	
mean = Average(f)
records = NumberOfStudents(f) 


print ("There are %d records in the file\n") % (records)
print ("The average of the  scores is %.1f")% (mean)

printRecords(file)	
file.close()

highestScore(f)