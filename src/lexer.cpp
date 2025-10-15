#include "lexer.h"
#include <cctype>
#include <iostream>

char Lexer::currentChar() {
    if (pos >= source.size()) return '\0';
    return source[pos];
}

void Lexer::advance() { pos++; }

Token Lexer::string() {
    advance(); // skip opening quote
    std::string result;
    while (currentChar() != '"' && currentChar() != '\0') {
        result += currentChar();
        advance();
    }
    advance(); // skip closing quote
    return Token{TokenType::STRING, result};
}

std::vector<Token> Lexer::tokenize() {
    std::vector<Token> tokens;
    while (currentChar() != '\0') {
        if (isspace(currentChar())) { advance(); continue; }

        if (currentChar() == 'o' && source.substr(pos, 3) == "out") {
            tokens.push_back(Token{TokenType::OUT, "out"});
            pos += 3;
            continue;
        }

        if (currentChar() == '"') {
            tokens.push_back(string());
            continue;
        }

        std::cerr << "Unknown character: " << currentChar() << std::endl;
        advance();
    }
    tokens.push_back(Token{TokenType::END, ""});
    return tokens;
}
