#include "jsonparser/AST/JsonReal.h"
#include <string>

void JsonReal::anchor() {}
JsonReal::~JsonReal() {}

std::string JsonReal::tojson()
{
    return std::to_string(value);
}