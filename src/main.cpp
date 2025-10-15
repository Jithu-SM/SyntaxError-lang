#include <iostream>
#include <fstream>
#include <sstream>
#include "lexer.h"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <file.sntx>\n";
        return 1;
    }

    std::ifstream file(argv[1]);
    if (!file) {
        std::cerr << "Error: Cannot open file " << argv[1] << std::endl;
        return 1;
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string code = buffer.str();

    Lexer lexer(code);
    auto tokens = lexer.tokenize();

    for (size_t i = 0; i < tokens.size(); i++) {
        if (tokens[i].type == TokenType::OUT) {
            if (tokens[i + 1].type == TokenType::STRING) {
                std::cout << tokens[i + 1].value << std::endl;
                i++; // skip string token
            }
        }
    }

    return 0;
}
