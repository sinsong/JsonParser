#ifndef JSONPARSER_AST_JSONREAL_H
#define JSONPARSER_AST_JSONREAL_H

#include "jsonparser/AST/JsonValue.h"

class JsonReal : public JsonValue
{
public:
    JsonReal(float value)
    : value(value) {}

    virtual ~JsonReal() override;

    virtual std::string tojson() override;
    virtual void anchor() override;

public:
    float value;
};

#endif