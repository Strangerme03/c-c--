#include <iostream>
#include <cctype> // Include this header for isalpha and isalnum
using namespace std;

// Define the DFA states
enum State {
    INITIAL, // Initial state
    LETTER,  // Alphabet letter encountered
    DIGIT,   // Digit encountered
    UNDERSCORE, // Underscore encountered
    ACCEPT   // Accepting state
};

bool isValidCIdentifier(const string& input) {
    State currentState = INITIAL;

    for (size_t i = 0; i < input.size(); ++i) {
        char c = input[i];
        switch (currentState) {
            case INITIAL:
                if (isalpha(c) || c == '_')
                    currentState = LETTER;
                else
                    return false; // Reject if not starting with a letter or underscore
                break;
            case LETTER:
                if (isalnum(c) || c == '_')
                    currentState = ACCEPT;
                else
                    return false; // Reject if invalid character
                break;
            case DIGIT:
                if (isalnum(c) || c == '_')
                    currentState = ACCEPT;
                else
                    return false; // Reject if invalid character
                break;
            case UNDERSCORE:
                if (isalpha(c))
                    currentState = LETTER; // Transition back to LETTER state if alphabet letter encountered after underscore
                else
                    return false; // Reject if invalid character
                break;
            case ACCEPT:
                // Remain in the accepting state
                break;
        }
    }

    // Accept if the final state is ACCEPT
    return currentState == ACCEPT;
}

int main() {
    string input;
    cout << "Enter a C identifier: ";
    cin >> input;

    if (isValidCIdentifier(input))
        cout << "Valid C identifier." << endl;
    else
        cout << "Invalid C identifier." << endl;

    return 0;
}

