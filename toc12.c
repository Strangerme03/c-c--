#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isSeparator(char c) {
    return (c == ',' || c == ';' || c == '(' || c == ')' || c == '[' || c == ']' || c == '{' || c == '}');
}

int main() {
    char statement[1000];

    printf("Enter a C program statement: ");
    fgets(statement, sizeof(statement), stdin);

    char token[1000];
    int tokenIndex = 0;

    for (int i = 0; statement[i] != '\0'; i++) {
        char currentChar = statement[i];

        if (isSeparator(currentChar) || currentChar == ' ') {
            if (tokenIndex > 0) {
                token[tokenIndex] = '\0';
                printf("Token: %s\n", token);
                tokenIndex = 0;
            }

        } else {
            token[tokenIndex++] = currentChar;
        }
    }

    if (tokenIndex > 0) {
        token[tokenIndex] = '\0';
        printf("Token: %s\n", token);
    }

    return 0;
}

