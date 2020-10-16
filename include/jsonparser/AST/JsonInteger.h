#ifndef JSONPARSER_AST_JSONINTEGER_H
#define JSONPARSER_AST_JSONINTEGER_H

#include "jsonparser/AST/JsonValue.h"

// 整数
class JsonInteger : public JsonValue
{
public:
    JsonInteger(int value)
    : value(value) {}

    virtual ~JsonInteger() override;

    virtual std::string tojson() override;
    virtual void anchor() override;

public:
    int value;
};

#endif