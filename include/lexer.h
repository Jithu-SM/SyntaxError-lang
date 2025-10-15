#pragma once
#include <string>
#include <vector>
#include "token.h"

class Lexer {
public:
    Lexer(const std::string& src) : source(src), pos(0) {}
    std::vector<Token> tokenize();

private:
    std::string source;
    size_t pos;
    char currentChar();
    void advance();
    Token string();
};
