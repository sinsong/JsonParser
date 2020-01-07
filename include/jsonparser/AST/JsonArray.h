#ifndef JSONPARSER_AST_JSONARRAY_H
#define JSONPARSER_AST_JSONARRAY_H

#include "jsonparser/AST/JsonValue.h"
#include <vector>

class JsonArray : public JsonValue
{
public:
    virtual ~JsonArray() override;
    
    virtual std::string tojson() override;
    virtual void anchor() override;

public:
    std::vector<JsonValue*> elements;
};

#endif