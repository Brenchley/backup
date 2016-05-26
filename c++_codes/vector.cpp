/*
WANYONYI BRENCHLEY JOSHUA
P15/1580/2015
*/
#include <iostream>
class Vector{
private: 
	float *values;
public:
	Vector();
	void displayValues();
	void displayFormated();
	void getValues();
	float getValue(int pos);
	void setValue(int pos, float val);
	void add100();
	void multiplyBy(int x);
	void sum(Vector b);
};

class Student: public Vector{
	private:
		char regno[20],sirname[20],fname[20],lname[20];
		float marks, mean;
		char grade;
	public:
		void getStudentDetails();
		void calcMarks();
		void showMarks();
};


/********Implementation*********/
//Constructor
Vector::Vector(){
	values = new float;
	values = new float[10];
	for (int i = 0; i < 10; ++i)
	{	
		values[i] = 0;
	}
}

void Vector::getValues(){
	for (int i = 0; i < 10; ++i)
	{	
		std::cout << "Input value " << i+1 <<":";
		std::cin >> values[i];
	}
}

float Vector::getValue(int pos){
	return Vector::values[pos-1];
}

void Vector::setValue(int pos, float val){
	Vector::values[pos-1] = val;
}


void Vector::displayValues(){
	for (int i = 0; i < 10; ++i)
	{
		/* code */
		std::cout << "value "<< i+1 <<"= " << Vector::values[i]  <<"\n";
	}
}
void Vector::displayFormated(){
	std::cout << "(" <<Vector::values[0];
	for (int i = 1; i < 10; ++i)
	{
		/* code */
		std::cout<<", " << Vector::values[i]  ;
	}
	std::cout << ")";
}

void Vector::add100(){
	for (int i = 0; i < 10; ++i)
	{
		/* code */
		Vector::values[i] = Vector::values[i] + 100;
	}
}
void Vector::sum(Vector b){
	Vector c;
	for (int i = 1; i <= 10; ++i)
	{
		c.setValue(i,Vector::values[i-1] + b.getValue(i));
	}
	std::cout<<"The sum is: ";  
	c.displayFormated();
}

void Vector::multiplyBy(int x){
	for (int i = 0; i < 10; ++i)
	{
		/* code */
		Vector::values[i] = Vector::values[i] * x;
	}
}


void Student::getStudentDetails(){
	std::cout << "Enter Registration Number:";
	std::cin >> Student::regno;
	std::cout << "Enter First Name:";
	std::cin >> Student::fname;
	std::cout << "Enter Sir Name:";
	std::cin >> Student::sirname;
	std::cout << "Enter unit marks: \n";
	getValues();
	
}

void Student::calcMarks(){
	for (int i = 0; i <= 10; ++i)
	{
		/* code */
		Student::marks = Student::marks + getValue(i);
	}
	Student::mean = Student::marks / 10;
		if(mean >= 70){
		Student::grade = 'A';	
	}
	else if (mean >= 60){
		Student::grade = 'B';
	}
	else if (mean >= 50){
		Student::grade = 'C';
	}
	else if (mean >= 40){
		Student::grade = 'D';
	}
	else {
		Student::grade = 'E';
	}

}

void Student::showMarks(){
	std::cout<<"\n\n\n" << "First Name :"<<Student::fname<< " "<<"\n";
	std::cout << "Sir Name :"<<Student::sirname<< " "<<"\n";
	std::cout << "Total marks:"<<Student::marks <<" " << "\n";
	std::cout <<"Avarage:"<<Student::mean<<"\n";
	std::cout <<"Grade:" <<Student::grade<<"\n";
	
}



int main()
{	
	char cInput ;
	Vector a;
	Student b;
	
	std::cout<<"Enter 1 to create vector that holds 10 Values."<<"\n";
	std::cout<<"Enter 2 to modify the values of each element by adding 100."<<"\n";
	std::cout<<"Enter 3 to multiply each value by a scalar value."<<"\n";
	std::cout<<"Enter 4 to display the vector in the form (10, 20, 30,….)."<<"\n";
	std::cout<<"Enter 5 to add two vectors."<<"\n";
	std::cout<<"Enter 6 to input student registration number, surname, other names, and marks for 10 units."<<"\n";
	std::cout<<"Enter 7 to print a transcript showing a matrix of each student’s marks out of 100, average and grade."<<"\n\n";
	std::cout<<"Choice :";
	std::cin>>cInput;
	switch (cInput) {
	case '1':
	//call function getValues

	    a.getValues();
		break;
	case '2':
	//call a function add100
		a.getValues();
	    a.add100();
		break;
	case '3':
	//call a function multiplyBy
		a.getValues();
	    a.multiplyBy(2);
		break;
	case '4':
	//call a function displayFormated
		a.getValues();
	    a.displayFormated();
		break;
	case '5':
	// call a function sum
		a.getValues();
		a.sum(a);
		break;
	case '6':
		b.getStudentDetails();


		break;
	case '7':
		int nPupil;
		Student *p;
		std::cout<<"Enter no. of Student"<<"\n";
		std::cin>>nPupil;
		p = new Student[nPupil];
		for (int i = 0; i < nPupil; ++i){		
			p[i].getStudentDetails();
			p[i].calcMarks();
			
		}
	for (int i = 0; i < nPupil; ++i){
		p[i].showMarks();

	}
	//call function save and quit

	return 0;

	if( cInput != 1,2,3,4,5,6,7)
		std::cout<<"invalid input";
	break;
	}

	return 0;
}

