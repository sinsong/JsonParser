#ifndef JSONPARSER_LEX_LEXER_H
#define JSONPARSER_LEX_LEXER_H

#include "jsonparser/Lex/Token.h"
#include <istream>
#include <memory>

class Lexer
{
public:
    Lexer(std::istream &is)
    : line(1),
      peek(' '), 
      in(is) {}
    
    void readch();
    bool readch(char c);
    std::shared_ptr<Token> scan();
    virtual void anchor();

public:
    int line;
private:
    char peek;
    std::istream& in;
};

#endif