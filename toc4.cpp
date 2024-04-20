#include <iostream>
using namespace std;

// Define the DFA states
enum State {
    INITIAL, // Initial state
    ONE,     // First '1' encountered
    TWO      // Second '1' encountered (accepting state)
};

// Function to simulate the DFA
bool acceptsTwoConsecutiveOnes(const string& input) {
    State currentState = INITIAL;

    for (size_t i = 0; i < input.size(); ++i) {
        char c = input[i];
        switch (currentState) {
            case INITIAL:
                if (c == '1')
                    currentState = ONE;
                break;
            case ONE:
                if (c == '1')
                    currentState = TWO;
                else
                    currentState = INITIAL; // Reset to initial state for '0'
                break;
            case TWO:
                // Remain in the accepting state
                break;
        }
    }

    // Accept if the final state is TWO
    return currentState == TWO;
}

int main() {
    string input;
    cout << "Enter a string: ";
    cin >> input;

    if (acceptsTwoConsecutiveOnes(input))
        cout << "Accepted: The string contains two consecutive '1's." << endl;
    else
        cout << "Rejected: The string does not contain two consecutive '1's." << endl;

    return 0;
}

