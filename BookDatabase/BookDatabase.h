#ifndef BOOKDATABASE_H
#define BOOKDATABASE_H

#include<map>

#include"Book.cpp"
#include<set>
#include<iostream>

using namespace std;

class BookDatabase{
  	
   public:
   	
	   Book& searchByTitle(const string& title);
	   
	   set<Book> searchByAuthor(const string& author);
	   
	   set<Book> publishedBefore( int year);
	   
	   set<Book> searchByPublisher(const string& publisher);
	   
	   void addBook( Book& book);
	   
	   void removeBook(const string& title);
	   
	   map <string,Book> getBookData();
	   
	   friend ostream& operator<< (ostream& os, BookDatabase& bookDatabase);
	   
   
   
   private:
   	
   	   map <string,Book> bookData;	   
	   		
};
#endif
  
