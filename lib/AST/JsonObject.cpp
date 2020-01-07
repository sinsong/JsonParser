#include "jsonparser/AST/JsonObject.h"
#include <string>
#include <sstream>

void JsonObject::anchor() {}

JsonObject::~JsonObject()
{
    for(auto iter = members.begin(); iter != members.end(); ++iter)
    {
        delete (iter->second);
    }
}

std::string JsonObject::tojson()
{
    std::ostringstream oss;
    
    oss.put('{');

    auto iter = members.begin();
    if (iter != members.end())
    {
        oss << iter->first;
        oss << ':';
        oss << iter->second->tojson();
		++iter;
    }
    while(iter != members.end())
    {
        oss << ", ";
        oss << iter->first;
        oss << ':';
        oss << iter->second->tojson();
		++iter;
    }

    oss.put('}');

    return oss.str();
}