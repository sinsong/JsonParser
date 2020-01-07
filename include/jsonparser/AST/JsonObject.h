#ifndef JSONPARSER_AST_JSONOBJECT_H
#define JSONPARSER_AST_JSONOBJECT_H

#include <map>
#include <string>

#include "jsonparser/AST/JsonValue.h"

class JsonObject : public JsonValue
{
public:
    virtual ~JsonObject() override;
    
    virtual std::string tojson() override;
    virtual void anchor() override;

public:
    std::map<std::string, JsonValue*> members;
};

#endif