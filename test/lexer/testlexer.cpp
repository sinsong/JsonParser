#include "jsonparser/Lex/Lexer.h"
#include "jsonparser/Parse/Parser.h"
#include <iostream>
#include <fstream>
#include <exception>
#include <typeinfo>

int main(int argc, char **argv)
{
    try
    {
        std::ifstream ifs;
        ifs.open(argv[1]);
        Lexer lex(ifs);
        
        while(true)
        {
            std::shared_ptr<Token> tok = lex.scan();
            if (!ifs.good())
                break;
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpotentially-evaluated-expression"
            std::cout << tok->getstr() << " - " << typeid(*tok).name() << std::endl;
#pragma clang diagnostic pop
        }

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}