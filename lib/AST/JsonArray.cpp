#include "jsonparser/AST/JsonArray.h"
#include <string>
#include <sstream>

void JsonArray::anchor() {}

JsonArray::~JsonArray()
{
    for(auto iter = elements.begin(); iter != elements.end(); ++iter)
    {
        delete (*iter);
    }
}

std::string JsonArray::tojson()
{
    std::ostringstream oss;

    oss.put('[');

    auto iter = elements.begin();
    if (iter != elements.end())
    {
        oss << (*iter)->tojson();
		++iter;
    }
    while(iter != elements.end())
    {
        oss << ", ";
        oss << (*iter)->tojson();
		++iter;
    }

    oss.put(']');
    
    return oss.str();
}