#ifndef INC_ERROR_H
#define INC_ERROR_H
#include <stdexcept>
#include <string>
class ScheckError : public std::runtime_error {
 public:
 ScheckError( const std::string & emsg ) 
   : std::runtime_error( emsg ) {
  }
};
#endif
