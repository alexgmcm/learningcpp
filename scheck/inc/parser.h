#ifndef INC_SCHECK_PARSER_H
#define INC_SCHECK_PARSER_H

#include <string>
#include <iostream>
#include <sstream>

class Parser {
    public:
        Parser( std::istream & is );
        std::string NextWord();
        unsigned int LineNo() const;
        std::string Context() const;
    private:
        char NextChar();
        bool ReadLine();
        enum State { stInSpace, stInWord, stInNum };
        State mState;
        std::istream & mSubmission;
        std::string mLine;
        unsigned int mLineNo, mPos;
};

#endif
