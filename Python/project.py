import sys
def open_file():
    name_of_file = raw_input("Enter the file name: ")#input
    while True:
        try:
            handle_object = open(name_of_file,'r').readlines()
            return handle_object
        except:
            print("{0} doesn't exist".format(name_of_file))
            name_of_file = input("Enter the file name again: ")


def letter_grade(marks):
    if marks >= 90:
        return 'A'
    elif marks >= 80:
        return 'B'
    elif marks >= 70:
        return 'C'
    elif marks >= 60:
        return 'D'
    else:
        return 'F'


def main():
    marks = list()
    ids_of_students = list()
    grades_of_students = list()
    print("The purpose of this assignment is to understand function and file.")
    read_file_object = open_file()

    for string in read_file_object:
        try:
            student_mark = float(string)
            marks.append(student_mark)
            grades_of_students.append(letter_grade(student_mark))
        except:
            ids_of_students.append(string)
    total_records = len(marks)
    print("User ID\t\tScores\tGrade")
    for i in range(total_records):
        print("{0}\t\t\t{1}\t{2}".format(ids_of_students[i],marks[i],grades_of_students[i]))

    print("There are {0} students records".format(total_records))
    print("The average  is:  {0}".format(sum(marks)/total_records))
    highest_student_mark = max(marks)
    index_of_highest_student_mark = marks.index(highest_student_mark)#output
    print("{0} has the highest student mark of {1}".format(ids_of_students[index_of_highest_student_mark],highest_student_mark))


if __name__ == "__main__":
    main()
