#ifndef JSONPARSER_PARSE_PARSER_H
#define JSONPARSER_PARSE_PARSER_H

#include "jsonparser/AST/AST.h"
#include "jsonparser/Lex/Token.h"
#include "jsonparser/Lex/Lexer.h"

class Parser
{
public:
    Parser(Lexer &l)
    : lex(l)
	{
		move();
	}

    void move();
    void error(std::string s);
    void match(int t);
    JsonObject* parse();
    JsonValue* value();
    JsonObject* object();
    JsonArray* array();
    virtual void anchor();

private:
    Lexer &lex;
    std::shared_ptr<Token> look;
};

#endif