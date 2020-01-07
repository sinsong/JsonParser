#include "jsonparser/Parse/Parser.h"
#include <string>
#include <exception>

void Parser::anchor() {}

void Parser::move()
{
    look = lex.scan();
}

void Parser::error(std::string s)
{
    std::string msg;
    msg += "near line ";
    msg += std::to_string(lex.line);
    msg += ": ";
    msg += s;
    throw std::runtime_error(msg);
}

void Parser::match(int t)
{
    if ( look->tag == t )
        move();
    else
    {
        std::string msg;
        msg += "syntax error: expect a \"";
        msg += (char)t;
        msg += "\"";
        error(msg);
    }
}

JsonObject* Parser::parse()
{
    return object();
}

/***
 * 解析 JsonValue
 * @return JsonValue 对象
 * @throws IOException
 *
 * value -> $object
 *        | $array
 *        | $string
 *        | $number
 *        | true
 *        | false
 *        | null
 */
JsonValue* Parser::value()
{
    JsonValue *value = nullptr;
    // object, array 解析过程中匹配了 { } [ ] 等字符，不需要 move()
    // 普通值类型需要 move() 一下
    switch(look->tag)
    {
    case Token::TSTRING:
        value = new JsonString(std::dynamic_pointer_cast<TString>(look)->value);
        move();
        break;
    case Token::TNUMBER:
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpotentially-evaluated-expression"
        if(typeid(*look) == typeid(TInteger))
#pragma clang diagnostic pop
            value = new JsonInteger(std::dynamic_pointer_cast<TInteger>(look)->value);
        else
            value = new JsonReal(std::dynamic_pointer_cast<TReal>(look)->value);
        move();
        break;
    case Token::TTRUE:
        value = new JsonBool(true);
        move();
        break;
    case Token::TFALSE:
        value = new JsonBool(false);
        move();
        break;
    case Token::TNULL:
        value = new JsonNull();
        move();
        break;
    case '{':
        value = object();
        break;
    case '[':
        value = array();
        break;
    default:
        error("syntax error: no match, expect a value");
        break;
    }
    return value;
}

/***
 * 解析 JsonObject
 * @return JsonObject 对象
 * @throws IOException
 *
 * object  -> { $members }
 * members -> $member
 *          | $member , $members
 * member  -> $whitespace $string $whitespace : $element
 * element -> $whitespace $value $whitespace
 */
JsonObject* Parser::object()
{
    match('{');
    JsonObject *object = new JsonObject();
    while(true)
    {
        if(look->tag == '}')
            break;
        
        JsonString* key = dynamic_cast<JsonString*>(value());
        match(':');
        JsonValue* value = this->value(); //重名太草了
        object->members.insert(std::pair<std::string, JsonValue*>(key->value, value));

        if ( look->tag != '}' )
            match(',');
    }
    match('}');
    return object;
}

/***
 * 解析 JsonArray
 * @return JsonArray 对象
 * @throws IOException
 *
 * array -> [ $whitespace ]
 *        | [ $elements ]
 * elements -> $element
 *           | $element , $elements
 * element -> $whitespace $value $whitespace
 */
JsonArray* Parser::array()
{
    JsonArray *array = new JsonArray();
    match('[');
    while(true)
    {
        if(look->tag == ']')
            break;
        array->elements.push_back(value());
        if(look->tag != ']')
            match(',');
    }
    match(']');
    return array;
}