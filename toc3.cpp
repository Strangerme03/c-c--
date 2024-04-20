#include <iostream>
using namespace std;

// Define the DFA states
enum State {
    Q0, // Initial state
    Q1, // First 'a' encountered
    Q2, // 'b' encountered after 'a'
    Q3  // Second 'a' encountered (accepting state)
};

// Function to simulate the DFA
bool acceptsSubstringABA(const string& input) {
    State currentState = Q0;

    for (size_t i = 0; i < input.size(); ++i) {
        char c = input[i];
        switch (currentState) {
            case Q0:
                if (c == 'a')
                    currentState = Q1;
                break;
            case Q1:
                if (c == 'b')
                    currentState = Q2;
                else if (c == 'a')
                    currentState = Q1;
                else
                    currentState = Q0;
                break;
            case Q2:
                if (c == 'a')
                    currentState = Q3;
                else
                    currentState = Q0;
                break;
            case Q3:
                // Remain in the accepting state
                break;
        }
    }

    // Accept if the final state is Q3
    return currentState == Q3;
}


int main() {
    string input;
    cout << "Enter a string: ";
    cin >> input;

    if (acceptsSubstringABA(input))
        cout << "Accepted: The string contains the substring \"aba\"." << endl;
    else
        cout << "Rejected: The string does not contain the substring \"aba\"." << endl;

    return 0;
}

