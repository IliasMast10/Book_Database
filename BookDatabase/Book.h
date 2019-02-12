#ifndef BOOK_H
#define BOOK_H

#include <vector>
#include<iostream>

using namespace std;

class Book{
    public:
       	
      
	   Book(const string& title, const string& publisher, int yearOfPublication, string authors);
	   
	   string getTitle() const;
	   
	   string getPublisher() const;
	   
	   int getYearOfPublication() const;
	   
	   vector <string> getAuthors() const;
	   
	   void setAuthors(string authors);
	   
	   friend bool operator== (const Book& b1, const Book& b2);
	   
	   friend bool operator< ( const Book& b1, const Book& b2);
	   
	   friend ostream& operator<< (ostream& os, Book& b);
	   
	  
	   
	private:
		
		string title, publisher;
		int year;
		vector<string> authors;
		
		// method to make the string of authors readable
		string stringOfAuthors() {
			
			string temp;
			for(int i=0; i<authors.size(); i++){
			  temp += authors[i];
			  temp += "   ";	
			}
		  return temp;	
		}  

};
#endif














