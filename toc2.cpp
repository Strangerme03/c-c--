#include <iostream>
using namespace std;

// Define the DFA states
enum State {
    INITIAL, // Initial state
    A,       // First '1' encountered
    B,       // Second '1' encountered (accepting state)
    DEAD     // Invalid state
};

// Function to simulate the DFA
bool acceptsEndingWith11(const string& input) {
    State currentState = INITIAL;

    for (size_t i = 0; i < input.size(); ++i) {
        char c = input[i];
        switch (currentState) {
            case INITIAL:
                if (c == '1')
                    currentState = A;
                else if (c != '0')
                    currentState = DEAD;
                break;
            case A:
                if (c == '1')
                    currentState = B;
                else if (c != '0')
                    currentState = DEAD;
                else
                    currentState = INITIAL; // Reset to initial state for '0'
                break;
            case B:
                if (c != '0' && c != '1')
                    currentState = DEAD;
                else
                    currentState = INITIAL; // Reset to initial state for '0' or '1'
                break;
            case DEAD:
                break;
        }
    }

    // Accept if the final state is B
    return currentState == B;
}

int main() {
    string input;
    cout << "Enter a string: ";
    cin >> input;

    if (acceptsEndingWith11(input))
        cout << "Accepted: The string ends with '11'." << endl;
    else
        cout << "Rejected: The string does not end with '11'." << endl;

    return 0;
}

