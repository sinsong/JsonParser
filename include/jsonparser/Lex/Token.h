#ifndef JSONPARSER_LEX_TOKEN_H
#define JSONPARSER_LEX_TOKEN_H

#include <string>

class Token
{
public:
    enum : int
    {
        TSTRING = -1,
        TNUMBER = -2,
        TTRUE = -3,
        TFALSE = -4,
        TNULL = -5
    };

    Token()
    : tag(0) {}

    Token(int t)
    : tag(t) {}

    virtual ~Token();

    virtual std::string getstr();
    virtual void anchor();

public:
    int tag;
};

class TInteger : public Token
{
public:
    TInteger(int value)
    : Token(Token::TNUMBER),
      value(value) {}
    
    virtual ~TInteger() override;

    virtual std::string getstr() override;
    virtual void anchor() override;

public:
    int value;
};

class TReal : public Token
{
public:
    TReal(float value)
    : Token(Token::TNUMBER),
      value(value) {}
      
    virtual ~TReal() override;

    virtual std::string getstr() override;
    virtual void anchor() override;

public:
    float value;
};

class TString : public Token
{
public:
    TString(std::string value)
    : Token(Token::TSTRING),
      value(value) {}

    virtual ~TString() override;

    virtual std::string getstr() override;
    virtual void anchor() override;

public:
    std::string value;
};

#endif