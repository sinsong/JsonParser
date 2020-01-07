#include "jsonparser/AST/JsonNull.h"

void JsonNull::anchor() {}
JsonNull::~JsonNull() {}

std::string JsonNull::tojson()
{
    return "null";
}