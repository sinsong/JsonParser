#ifndef JSONPARSER_AST_JSONVALUE_H
#define JSONPARSER_AST_JSONVALUE_H

#include <string>

class JsonValue
{
public:
    virtual ~JsonValue();
    virtual std::string tojson() = 0;
    virtual void anchor();
};

#endif