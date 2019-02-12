#include "BookDatabase.h"
#include<iostream>

using namespace std;
    
    Book& BookDatabase::searchByTitle(const string& title){
     
	    map<string, Book>::iterator it = bookData.find(title);
       
	    if(it==bookData.end()){
          cout<<"key by the name of "<<title<<"  was not found in the map.\n";
        }
        else
          return it->second ;
    }
    
    
    set<Book> BookDatabase::searchByAuthor(const string& author){
      
	   set<Book> setOfBooks;
	    
	   map<string, Book>:: iterator it = this->bookData.begin();
	   		
         while(it != this->bookData.end() ){ 
            Book tempBook = it->second;
            
           	for(int i=0; i<tempBook.getAuthors().size(); i++){ // search in the vector of authors
    
			   if(author == tempBook.getAuthors()[i] ){ // if there is the name of the author in the vector
			   	
			    setOfBooks.insert(tempBook);	   	//then add the book to the set.
			   }
		    }
          it++;
         }
	     
      return setOfBooks;	
	}
	
	
    
    
    set<Book> BookDatabase::publishedBefore( int year){
     	
      set<Book> setOfBooks;
	    
	   map<string, Book>:: iterator it = this->bookData.begin();
	   		
         while(it != this->bookData.end() ){
        
			   if( it->second.getYearOfPublication() < year ){ 

			    setOfBooks.insert(it->second);	   	
			   }
		    it++; 	   
		 }    
      return setOfBooks;	
	}
    
    
    set<Book> BookDatabase::searchByPublisher(const string& publisher){
    	
       set<Book> setOfBooks;
	    
	   map<string, Book>:: iterator it = this->bookData.begin();
	   		
         while(it != this->bookData.end() ){
            Book tempBook = it->second;
            
           	for(int i=0; i<tempBook.getAuthors().size(); i++){
    
			   if(publisher == tempBook.getPublisher() ){
			   	
			    setOfBooks.insert(tempBook);	   	
			   }
		    }
          it++;
         }
	     
      return setOfBooks;	
	}
    
    
    void BookDatabase::addBook( Book& book){
    	
    	pair<string, Book> newPair(book.getTitle(), book);
        bookData.insert (newPair); 
	}



    void BookDatabase::removeBook(const string& title){
     	bookData.erase(title);
     	cout<<"\nThe book with the title: " <<title<< ", was erased";	
	}
    
    
    // i get access to the map
    map <string,Book> BookDatabase::getBookData(){
	   return bookData;
	}
  
    /*i didnt kno how to fix the error so i did the comparison in this class also
    bool operator< ( const Book& b1, const Book& b2) {
	 	  return b1.getTitle() < b2.getTitle();
	 }
    */
    
    ostream& operator<< (ostream& os, BookDatabase& bookDatabase){
       
	   os<<"\n\t\tBOOK DATABASE\n------------------------------------------\n"; 
	   
       map<string, Book>:: iterator it = bookDatabase.bookData.begin();
	   		
       while(it != bookDatabase.bookData.end() ){
        os<< it->second;
        it++;
       }
     return os;
	}
    
    
    
	
    
    
    
    
    
    
    
    
    
    
    
    
  


