#include <iostream>
#include "BookDatabase.cpp"
#include<set>
#include<fstream>
#include<cstdlib>

using namespace std;
 
 
 void printSet( const set<Book>& mySet) {
   for(set<Book>::const_iterator iter = mySet.begin(); iter!=mySet.end(); iter++)
        cout<<*iter;      
}

int main(){
	
	
	BookDatabase bd;
	string word, title, authors, publisher;
    
	ifstream file("books.txt");
    	
   if(!file){
		cout<<"\nError opening file\n\n";
   } else { 	  
     while( file>>word ){
     	
	     	title = word;
			
			file>>word;
			
		    int ammountOfBooks =  atoi(word.c_str() ); 
			
			file>>word;
			
			bool found = false;
			
		   do{	
			  for(int i=0; i<word.length(); i++){
			   
			    if( word.at(i) == '_'){	// if the word contains '_' then
				  publisher = word;     // it is the publisher
				  found = true;
				  break;
			    }
			   
			    if( i == word.length()-1 ) {
				  authors +=word;  
				  authors +=" ";	 	
			    }	
			  }
		    file>>word;	
		    
	      }while (!found);
	      
	  int year =  atoi(word.c_str() );
	  
	  Book tempBook (title,publisher,year,authors);
	  bd.addBook(tempBook);
	  
	  
	  authors = "";// reset authors variable
    }//end of while
  }//end of else
  
  	

	Book b1("Learn C++", "Prentice_Hall",2006,"William Topp William Ford"); 

    cout<<bd;
   
    bd.addBook(b1);
    bd.removeBook("Computer_Graphics");
    
    cout<<"\n"<<bd;
    
    cout<<"\n\n";
	cout<<bd.searchByTitle("Learn C++");
  
   
	
    set<Book> s1 = bd.searchByPublisher("Prentice_Hall");
    printSet(s1);
  
   // set<Book> s2 = bd.publishedBefore(2000);
  //  printSet(s2);
  
   // set<Book> s3 = bd.searchByAuthor("William Topp William Ford");
  //  printSet(s3);
  
}
	     
	    
	
	

	
