#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: sntx <command> [file]\nCommands: run, repl, version, help\n");
        return 1;
    }

    if (strcmp(argv[1], "version") == 0) {
        printf("SyntaxError v0.0.1\n");
    } else if (strcmp(argv[1], "help") == 0) {
        printf("Usage: sntx <command> [file]\nCommands: run, repl, version, help\n");
    } else if (strcmp(argv[1], "run") == 0) {
        if (argc < 3) {
            printf("Error: No file specified.\n");
            return 1;
        }
        printf("Running %s...\n", argv[2]);
        // TODO: implement interpreter
    } else if (strcmp(argv[1], "repl") == 0) {
        printf("Starting SyntaxError REPL...\n");
        // TODO: implement REPL loop
    } else {
        printf("Unknown command: %s\n", argv[1]);
    }

    return 0;
}
