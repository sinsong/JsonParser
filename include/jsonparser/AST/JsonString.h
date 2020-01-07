#ifndef JSONPARSER_AST_JSONSTRING_H
#define JSONPARSER_AST_JSONSTRING_H

#include "jsonparser/AST/JsonValue.h"

#include <string>

class JsonString : public JsonValue
{
public:
    JsonString(std::string value)
    : value(value) {}

    virtual ~JsonString() override;
    virtual std::string tojson() override;
    virtual void anchor() override;
    
public:
    std::string value;
};

#endif