#include "jsonparser/AST/JsonString.h"
#include <string>

void JsonString::anchor() {}
JsonString::~JsonString() {}

std::string JsonString::tojson()
{
    std::string str;
    str += "\"";
    str += value;
    str += "\"";
    return str;
}