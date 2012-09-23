#ifndef INC_REPORTER_H
#define INC_REPORTER_H

#include <string>
#include <ostream>


class Reporter {
  public:
    Reporter( std::ostream & os ) : mOut( os ) {
    }
    virtual ~Reporter() {
    }
    virtual void ReportHeader() = 0;
    virtual void ReportError( const std::string & word,
                   const std::string & context,
                   unsigned int line,
                   const std::string & filename ) = 0;
    virtual void ReportFooter() = 0;
  protected:
    std::ostream & Out() {
      return mOut;
    }
  private:
    std::ostream & mOut;
};

#endif
