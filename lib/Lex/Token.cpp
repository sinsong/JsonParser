#include "jsonparser/Lex/Token.h"

void Token::anchor() {}
void TInteger::anchor() {}
void TReal::anchor() {}
void TString::anchor() {}

Token::~Token() {}
TInteger::~TInteger() {}
TReal::~TReal() {}
TString::~TString() {}

std::string Token::getstr()
{
    switch(tag)
    {
    case Token::TTRUE:
        return "true";
    case Token::TFALSE:
        return "false";
    case Token::TNULL:
        return "null";
    default:
        return std::string{(char)tag};
    }
}

std::string TInteger::getstr()
{
    return std::to_string(value);
}

std::string TReal::getstr()
{
    return std::to_string(value);
}

std::string TString::getstr()
{
    return value;
}