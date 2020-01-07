#include "jsonparser/AST/JsonInteger.h"
#include <string>

void JsonInteger::anchor() {}
JsonInteger::~JsonInteger() {}

std::string JsonInteger::tojson()
{
    return std::to_string(value);
}