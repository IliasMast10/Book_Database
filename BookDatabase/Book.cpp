#include "Book.h"

#include<iostream>

using namespace std;
    

 	Book::Book(const string& title, const string& publisher,int yearOfPublication,
           	   string authors) : title(title), publisher(publisher), year(yearOfPublication) {
    	
           setAuthors(authors);
	}
 
    string Book:: getTitle() const{
 	  return title;
    }
 
    string Book:: getPublisher() const{
 	  return publisher;
    }
    
    int Book::getYearOfPublication()const{
    	return year;
	}
	
   	vector<string> Book::getAuthors()const{
		return authors;
	}
	
	// I set the authors in the vector
	void Book::setAuthors(string authors){
	
		int pass = 0;
		int beginOfWord = 0;
		string temp;
	
		for(int i = 0; i< authors.length(); i++){	 
		    
			if( isspace( authors.at(i) ) ){
			      pass++;    
		    }
		    
			if( (pass == 2) || (i+1 == authors.length()) ) {
			  
			   temp = authors.substr( beginOfWord, i+1); // i take the first or last name 
			                                            // and i push it to the vector
			   this->authors.push_back(temp);
			   pass = 0;
			   beginOfWord = i+1; // i set the next word to begin where the previous word ended
		    }
		}
		
		
	}
	
     bool operator== ( const Book& b1,const Book& b2){
     	if(b1.getTitle() == b2.getTitle())
     	 return true;
     	else
		 return false; 
	 }
	 
	 
	 bool operator< ( const Book& b1,const Book& b2){
	   return b1.getTitle() < b2.getTitle();
	 }
	   
	  ostream& operator<< (ostream& os, Book& b){
	    
	    	os<<"\nTitle: "<<b.getTitle();
			os<<"\nAuthors: "<<b.stringOfAuthors();
			os<<"\nPublisher: "<<b.getPublisher();
			os<<"\nYear: "<<b.getYearOfPublication()<<"\n";
				
	    return os;	
	  	
	  }
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
