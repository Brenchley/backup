/*P15/1580/2015
Wanyonyi Brenchley Joshua
*/

#include <iostream>// library that contains basic input/output functions
#include <fstream>// library that contains file input/output functions
#include <string>
#include <vector>

using namespace std;

class book
{
private:
	string  title,author, publisher;
	int stock;
	int price;
	int numberOfSuccessfulTransaction;
	/*static*/int numberOfUnSuccessfulTransaction;
	void updateStock(string parAuthor, string parTitle, int parReduceNumber);

public:
	book();
	void getBookDetails();
	void printBookDetails();
	void searchBook(string parAuthor, string parTitle);
	void updateData(string parAuthor, string parTitle,int newStock,int newPrice);
};

//book constructor
book::book(){
	string *author = new string[50];
	string *title = new string[50];
	string *publisher = new string[50];
	int price = 0;
	int stock = 0;
	book::numberOfSuccessfulTransaction = 0;
	book::numberOfUnSuccessfulTransaction = 0;
}


void book::getBookDetails(){

	cin.ignore();  
	cout << "Enter Authors name:";
	getline(cin,author);
	cout << "Enter Book title:";
	getline(cin,title);
	cout << "Enter Publishers name:";
	getline(cin,publisher);
	cout << "Enter book's price:";
	cin>>price;
	cout << "Enter Stock:";
	cin>>stock;
	
	cout << "\n\n";

	ofstream myStream("lib.txt",ios::app);

	if (myStream.is_open()){
	myStream <<author << "\n";
	myStream <<title<< "\n ";
	myStream <<price<< "\n";
	myStream <<publisher<< "\n";
	myStream <<stock<< "\n";
	
	
	}
}

void book::printBookDetails(){
	string line;
	ifstream myStream("lib.txt");

	if (myStream.is_open())
	{
		while(getline(myStream, line))
		{
			cout << line << "\n";
		}
		myStream.close();
	}
	else cout << "Unable to open file";
}


void book::searchBook(string parAuthor, string parTitle) {
	ifstream reader("lib.txt");
	string author, title, publisher;
	int price, stock, iNeededCopies;
	bool isFound = false;

	while ( !reader.eof() ) {
		reader >> author;
		reader >> title;
		reader >> price;
		reader >> publisher;
		reader >> stock;
		if ( author == parAuthor && title == parTitle ) {
			isFound = true;
			break;
		}
	}
	reader.close();
	if ( isFound ) {
		cout << "The Book is Found" << endl;
		cout << "Author: " << author << endl;
		cout << "Title: " << title << endl;
		cout << "Price: " << price << endl;
		cout << "Publisher: " << publisher << endl;
		cout << "Stock: " << stock << endl;

		cout << "\n\nEnter Number of Copies: " ;
		cin >> iNeededCopies;
		if ( stock < iNeededCopies ) {
			cout << "Sorry Stock Limited." << endl;
			book::numberOfUnSuccessfulTransaction ++;
		}
		else {
			cout << "Please give: " << price * iNeededCopies << endl;
			updateStock(author, title, iNeededCopies);
			book::numberOfSuccessfulTransaction ++;
		}
	}	
	else {
		cout << "Sorry The Book is not found." << endl;
		book::numberOfUnSuccessfulTransaction ++;
	}
cout<<"Number of SuccessfulTransaction: "<< numberOfSuccessfulTransaction<<"\n";	
cout<<"Number of UnSuccessfulTransaction: "<< numberOfUnSuccessfulTransaction<<"\n";
}

void book::updateData(string parAuthor, string parTitle,int newStock,int newPrice){
	vector<string> vecStAuthor;
	vector<string> vecStTitle;
	vector<int> vecIPrice;
	vector<string> vecStPublisher;
	vector<int> vecINumberOfCopies;

	ifstream reader("lib.txt");

	string stAuthor, stTitle, stPublisher;
	int iPrice, iNumberOfCopies, iNeededCopies;	
	
	while ( !reader.eof() ) {
		reader >> stAuthor;
		reader >> stTitle;
		reader >> iPrice;
		reader >> stPublisher;
		reader >> iNumberOfCopies;
		if ( stAuthor == parAuthor && stTitle == parTitle ) {
			iNumberOfCopies = newStock;
			iPrice = newPrice;
		}
		vecStAuthor.push_back(stAuthor);
		vecStTitle.push_back(stTitle);
		vecIPrice.push_back(iPrice);
		vecStPublisher.push_back(stPublisher);
		vecINumberOfCopies.push_back(iNumberOfCopies);
	}
	reader.close();

	ofstream writer("lib.txt");

	int iIndex = 0;
	while ( iIndex < vecStAuthor.size() ) {
		writer << vecStAuthor[iIndex] << endl;
		writer << vecStTitle[iIndex] << endl;
		writer << vecIPrice[iIndex] << endl;
		writer << vecStPublisher[iIndex] << endl;
		writer << vecINumberOfCopies[iIndex] << endl;
		iIndex ++;
	}
	writer.close();
}


void book::updateStock(string parAuthor, string parTitle, int parReduceNumber) {
	vector<string> vecStAuthor;
	vector<string> vecStTitle;
	vector<int> vecIPrice;
	vector<string> vecStPublisher;
	vector<int> vecINumberOfCopies;

	ifstream reader("lib.txt");

	string stAuthor, stTitle, stPublisher;
	int iPrice, iNumberOfCopies, iNeededCopies;	
	
	while ( !reader.eof() ) {
		reader >> stAuthor;
		reader >> stTitle;
		reader >> iPrice;
		reader >> stPublisher;
		reader >> iNumberOfCopies;
		if ( stAuthor == parAuthor && stTitle == parTitle ) {
			iNumberOfCopies -= parReduceNumber;

		}
		vecStAuthor.push_back(stAuthor);
		vecStTitle.push_back(stTitle);
		vecIPrice.push_back(iPrice);
		vecStPublisher.push_back(stPublisher);
		vecINumberOfCopies.push_back(iNumberOfCopies);
	}
	reader.close();

	ofstream writer("lib.txt");

	int iIndex = 0;
	while ( iIndex < vecStAuthor.size() ) {
		writer << vecStAuthor[iIndex] << endl;
		writer << vecStTitle[iIndex] << endl;
		writer << vecIPrice[iIndex] << endl;
		writer << vecStPublisher[iIndex] << endl;
		writer << vecINumberOfCopies[iIndex] << endl;
		iIndex ++;
	}
	writer.close();
}



/*void book::searchBook(){
	string search_str;
	cout << "Please enter Author's name or Book Title"<< "\n";
	cin >> search_str;
	ifstream file("lib.txt");
	
	string line;
	while(getline(file, line)){
		if(line.find(search_str)!= string::npos){
			cout <<line<<"\n";}	
		}
		if (line.find(search_str)== string::npos)
			{
				cout << "NO BOOK WITH THAT NAME OR AUTHOR";
			}
	size_ Title;
	float repl = price;
	int newNumber = 32;	
	getline(file, line);
	for(;line.find(repl)!=string::npos){
		osstringstream os;
		os <<repl ':'<< newNumber;
		line =os.str();
	}

}*/
int main(){
	int b_num = 0;
	char choice;
	book b[20];
	string author;
	string title;
	int stock;
	int price;

cout <<"Enter:"<< "\n\t"<<"1.To enter book"<<"\n\t"<<"2.To to search books"<<"\n\t"<<"3.To display all books"<<"\n\t"<<"4.Update book Data"<<"\n\t";
	cin >> choice;
while (choice!=5){
	

	switch(choice){
		case '1':
			cout << "How many books do you want to enter:";
			cin >> b_num;
			for (int i = 0; i < b_num; ++i)
			{
				b[i].getBookDetails();
			}
			break;
		case '2':
				cout << "Enter Author Name:";
				cin >> author;
				cout << "Enter Book Title:";
				cin >> title;
				b[1].searchBook(author, title);	
				
			break;
		case '3':
				b[1].printBookDetails();
				break;
		case '4':
				cout << "Enter Author Name:";
				cin >> author;
				cout << "Enter Book Title:";
				cin >> title;
				cout << "Enter new Stock data:";
				cin >> stock;
				cout << "Enter new Price data:";
				cin >> price;
				b[1].updateData(author, title, stock, price);


	
	}
	cout <<"Enter:"<< "\n\t"<<"1.To enter book"<<"\n\t"<<"2.To to search books"<<"\n\t"<<"3.To display all books"<<"\n\t"<<"4.Update book Data"<<"\n\t";;
	cin >> choice;
	cout<< "\n\n";
}
			
	return 0;

}
