#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

// DFA states
enum State { START, LETTER_DIGIT, INVALID };

// Transition function for the DFA
enum State transition(enum State currentState, char c) {
    if (currentState == START) {
        if (isalpha(c) || c == '_')
            return LETTER_DIGIT;
        else
            return INVALID;
    } else if (currentState == LETTER_DIGIT) {
        if (isalnum(c) || c == '_')
            return LETTER_DIGIT;
        else
            return INVALID;
    }
    return INVALID;
}

// DFA to validate C identifiers
bool isValidIdentifier(const char* str) {
    enum State currentState = START;
    for (int i = 0; str[i] != '\0'; ++i) {
        currentState = transition(currentState, str[i]);
        if (currentState == INVALID)
            return false;
    }
    return currentState == LETTER_DIGIT;
}

int main() {
    char input[100]; // Assuming identifiers won't exceed 100 characters
    printf("Enter an identifier: ");
    fgets(input, sizeof(input), stdin); // Read the entire line

    // Remove the newline character at the end (if present)
    input[strcspn(input, "\n")] = '\0';

    if (isValidIdentifier(input))
        printf("'%s' is a valid C identifier.\n", input);
    else
        printf("'%s' is not a valid C identifier.\n", input);

    return 0;
}
