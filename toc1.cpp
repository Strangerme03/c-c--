#include <iostream>
using namespace std;

// Define the DFA states
enum State {
    Q0, // Initial state
    Q1, // First 'a' encountered
    Q2  // Second 'a' encountered (accepting state)
};

// Function to simulate the DFA
bool acceptsStartingWithAA(const string& input) {
    State currentState = Q0;

    for (size_t i = 0; i < input.size(); ++i) {
        char c = input[i];
        switch (currentState) {
            case Q0:
                if (c == 'a')
                    currentState = Q1;
                else
                    return false; // Reject if first character is not 'a'
                break;
            case Q1:
                if (c == 'a')
                    currentState = Q2;
                else
                    return false; // Reject if second character is not 'a'
                break;
            case Q2:
                // Remain in the accepting state
                break;
        }
    }

    // Accept if the final state is Q2
    return currentState == Q2;
}

int main() {
    string input;
    cout << "Enter a string: ";
    cin >> input;

    if (acceptsStartingWithAA(input))
        cout << "Accepted: The string starts with 'aa'." << endl;
    else
        cout << "Rejected: The string does not start with 'aa'." << endl;

    return 0;
}

