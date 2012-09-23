#include <iostream>
#include <string>
#include "dictionary.h"
#include "parser.h"
#include "csvreporter.h"
using namespace std;

//need to create XML reporter!! similar to csv

int main(int argc, char * argv[] ) {
  try{

    cout << "scheck version 0.1" << endl;
    const char * subtext = "data/sub1.txt"; 

    Dictionary d( "data/brownfoxdict.dat" );
    
    ifstream sub( subtext );
    if ( ! sub.is_open() ) {
        throw ScheckError( "cannot open data/sub1.txt" );
    }
    
    Parser p( sub );
    Reporter * rep = 0;
    if ( argc == 1 ) {
      rep = new CSVReporter( cout );
    }
    else {
      rep = new XMLReporter( cout );
    }

    string word;
    // cout << d.testWord();
    rep.ReportHeader();
    while( ( word = p.NextWord() ) != ""  ) {
      if (!d.Check(word) ) {
	rep.ReportError( word, p.Context(), p.LineNo(), subtext ); 
      }
    }
    rep.ReportFooter();
  }
  catch( const ScheckError & e ) {
    cerr << "Error: " << e.what() << endl;
    return 1;
  }
  catch( ... ) {
    cerr << "Error: unknown exception" << endl;
    return 2;
  }

}
