#pragma once
#include <string>

enum class TokenType {
    OUT,        // our 'out' keyword
    STRING,     // string literal
    END         // end of input
};

struct Token {
    TokenType type;
    std::string value;
};
