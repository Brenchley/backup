#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class books
{
private:
	 /*static*/int numberOfSuccessfulTransaction;
	 /*static*/int numberOfUnSuccessfulTransaction;
	void updateStock(string parAuthor, string parTitle, int parReduceNumber);

public:	
	books();
	void searchBook(string parAuthor, string parTitle);
};

books::books() {
	books::numberOfSuccessfulTransaction = 0;
	books::numberOfUnSuccessfulTransaction = 0;
}

void books::searchBook(string parAuthor, string parTitle) {
	ifstream reader("BookInformation.txt");
	string stAuthor, stTitle, stPublisher;
	int iPrice, iNumberOfCopies, iNeededCopies;
	bool isFound = false;

	while ( !reader.eof() ) {
		reader >> stAuthor;
		reader >> stTitle;
		reader >> iPrice;
		reader >> stPublisher;
		reader >> iNumberOfCopies;
		if ( stAuthor == parAuthor && stTitle == parTitle ) {
			isFound = true;
			break;
		}
	}
	reader.close();
	if ( isFound ) {
		cout << "The Book is Found" << endl;
		cout << "Author: " << stAuthor << endl;
		cout << "Title: " << stTitle << endl;
		cout << "Price: " << iPrice << endl;
		cout << "Publisher: " << stPublisher << endl;

		cout << "\n\nEnter Number of Copies: " ;
		cin >> iNeededCopies;
		if ( iNumberOfCopies < iNeededCopies ) {
			cout << "Sorry Stock Limited." << endl;
			books::numberOfUnSuccessfulTransaction ++;
		}
		else {
			cout << "Please give: " << iPrice * iNeededCopies << endl;
			updateStock(stAuthor, stTitle, iNeededCopies);
			books::numberOfSuccessfulTransaction ++;
		}
	}	
	else {
		cout << "Sorry The Book is not found." << endl;
		books::numberOfUnSuccessfulTransaction ++;
	}
}

void books::updateStock(string parAuthor, string parTitle, int parReduceNumber) {
	vector<string> vecStAuthor;
	vector<string> vecStTitle;
	vector<int> vecIPrice;
	vector<string> vecStPublisher;
	vector<int> vecINumberOfCopies;

	ifstream reader("BookInformation.txt");

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

	ofstream writer("BookInformation.txt");

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

int main() {

	string author;
	string title;
	books newCostomer;
	while ( true ) {
		cout << "**********************"<<"\n";
		cout << "Enter Author Name:";
		cin >> author;
		if ( author == "exit" ) break;
		cout << "Enter Book Title:";
		cin >> title;
		newCostomer.searchBook(author, title);
	}
	return 0;
}