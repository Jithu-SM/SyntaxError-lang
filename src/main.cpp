#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "lexer.h"

void runCode(const std::string& code) {
    Lexer lexer(code);
    auto tokens = lexer.tokenize();

    for (size_t i = 0; i < tokens.size(); i++) {
        if (tokens[i].type == TokenType::OUT) {
            if (i + 1 < tokens.size() && tokens[i + 1].type == TokenType::STRING) {
                std::cout << tokens[i + 1].value << std::endl;
                i++; // skip string token
            }
        }
    }
}

void runFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error: Cannot open file " << filename << std::endl;
        return;
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    runCode(buffer.str());
}

void runREPL() {
    std::cout << "SyntaxError CLI (sntx) - Interactive Mode\n";
    std::cout << "Type 'exit' to quit.\n\n";

    std::string line, accumulated;

    while (true) {
        std::cout << ">>> ";
        std::getline(std::cin, line);

        if (line == "exit") break;
        if (line.empty()) continue;

        accumulated += line + "\n";
        runCode(accumulated);
        accumulated.clear(); // clear after execution (or keep for multi-line)
    }

    std::cout << "Exiting SyntaxError CLI.\n";
}

int main(int argc, char* argv[]) {
    if (argc == 1) {
        runREPL();
    } else if (argc == 2) {
        runFile(argv[1]);
    } else {
        std::cerr << "Usage:\n"
                  << "  sntx <file.sntx>   Run a SyntaxError source file\n"
                  << "  sntx               Start interactive mode\n";
        return 1;
    }
    return 0;
}
