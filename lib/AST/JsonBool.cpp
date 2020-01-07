#include "jsonparser/AST/JsonBool.h"

void JsonBool::anchor() {}
JsonBool::~JsonBool() {}

std::string JsonBool::tojson()
{
    return value ? "true" : "false";
}