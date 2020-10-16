#ifndef JSONPARSER_AST_JSONNULL_H
#define JSONPARSER_AST_JSONNULL_H

#include "jsonparser/AST/JsonValue.h"

// 空值
class JsonNull : public JsonValue
{
public:
    virtual ~JsonNull() override;
    
    virtual std::string tojson() override;
    virtual void anchor() override;
};

#endif