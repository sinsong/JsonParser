#include "jsonparser/Lex/Lexer.h"
#include <string>
#include <cctype>

void Lexer::anchor() {}

// helper
inline int ch2int(char c)
{
    switch(c)
    {
    case '0':
        return 0;
    case '1':
        return 1;
    case '2':
        return 2;
    case '3':
        return 3;
    case '4':
        return 4;
    case '5':
        return 5;
    case '6':
        return 6;
    case '7':
        return 7;
    case '8':
        return 8;
    case '9':
        return 9;
    }
    return ~((int)0);
}

void Lexer::readch()
{
    peek = in.get();
}

bool Lexer::readch(char c)
{
    readch();
    if ( peek != c )
        return false;
    peek = ' ';
    return true;
}

std::shared_ptr<Token> Lexer::scan()
{
    while(true)
    {
        // 空白字符
        if ( peek == ' ' || peek == '\t' )
        {
            readch();
            continue;
        }
        // 换行符
        else if ( peek == '\n' )
        {
            line += 1;
        }
        else if ( peek == '\r' )
        {
            line += 1;
            readch('\n');
        }
        // 其他交给下边
        else
        {
            break;
        }
        readch();
    }

    // 元字符
    switch( peek )
    {
    case '{':
        readch();
        return std::make_shared<Token>('{');
    case '[':
        readch();
        return std::make_shared<Token>('[');
    case ':':
        readch();
        return std::make_shared<Token>(':');
    case ',':
        readch();
        return std::make_shared<Token>(',');
    }

    // TString
    // ".*"
    if ( peek == '\"' )
    {
        std::string str;
        readch();
        if ( peek == '\"' )
        {
            readch();
            return std::make_shared<TString>("");
        }
        do
        {
            str.push_back(peek);
            readch();
        } while ( peek != '\"' );
        readch();
        return std::make_shared<TString>(str);
    }

    // Constant
    if ( isalpha(peek) )
    {
        std::string str;
        do
        {
            str.push_back(peek);
            readch();
        } while ( isalpha(peek) );
        if(str == "true")
            return std::make_shared<Token>(Token::TTRUE);
        else if(str == "false")
            return std::make_shared<Token>(Token::TFALSE);
        else if(str == "null")
            return std::make_shared<Token>(Token::TNULL);
    }

    // Number
    // \d+\.\d*
    if ( isdigit(peek) )
    {
        int v = 0;
        do
        {
            v = 10 * v + ch2int(peek);
            readch();
        } while ( isdigit(peek) );
        if ( peek != '.' )
            return std::make_shared<TInteger>(v);
        float x = v;
        float d = 10;
        for(;;)
        {
            readch();
            if( !isdigit(peek) )
                break;
            x = x + ch2int(peek) / d;
            d = d * 10;
        }
        return std::make_shared<TReal>(x);
    }

    // 其他
    std::shared_ptr<Token> tok = std::make_shared<Token>(peek);
    peek = ' ';
    return tok;
}