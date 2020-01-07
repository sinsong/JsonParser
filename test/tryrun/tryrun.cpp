#include "jsonparser/Lex/Lexer.h"
#include "jsonparser/Parse/Parser.h"
#include <iostream>
#include <fstream>
#include <exception>

int main(int argc, char **argv)
{
    try
    {
        std::ifstream ifs;
        ifs.open(argv[1]);
        Lexer lex(ifs);
        Parser parser(lex);
        JsonObject *obj = parser.parse();
        std::cout << obj->tojson() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}