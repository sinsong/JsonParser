#ifndef JSONPARSER_AST_JSONBOOL_H
#define JSONPARSER_AST_JSONBOOL_H

#include "jsonparser/AST/JsonValue.h"

// 布尔值
class JsonBool : public JsonValue
{
public:
    JsonBool(bool value)
    : value(value) {}

    virtual ~JsonBool() override;

    virtual std::string tojson() override;
    virtual void anchor() override;

    bool value;
};

#endif