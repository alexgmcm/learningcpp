#include "csvreporter.h"

using std::string;

static string ToCSV( const string & s ) {
    string csv;
    for ( unsigned int i = 0; i < s.size(); ++i ) {
        if ( s[i] == '"') {
            csv += '"';
        }
        csv += s[i];
    }
    return '"' + csv + '"';
}

CSVReporter :: CSVReporter( std::ostream & os ) 
      : Reporter( os ) {
}

void CSVReporter :: ReportHeader() {
     Out() << "word,context,line,file\n";
}

void CSVReporter :: ReportError( const string & word,
                                 const string & context,
                                 unsigned int line,
                                 const string & filename ) {
    Out() << ToCSV( word ) << ","
	  << ToCSV( context ) << ","
          << '"' << line << '"' << ","
          << ToCSV( filename ) << "\n";
}

void CSVReporter :: ReportFooter() {
   // nothing to do
}
