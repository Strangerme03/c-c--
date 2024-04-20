#include <iostream>
using namespace std;

int nfa = 1;
int flag = 0;

void state1(char c) {
    if (c == '1')
        nfa = 2;
    else
        flag = 1;
}

void state2(char c) {
    if (c == '1')
        nfa = 3;
    else
        flag = 1;
}

void state3(char c) {
    if (c == '1')
        nfa = 1;
    else
        flag = 1;
}

bool checkInput(string s, int x) {
    for (int i = 0; i < x; i++) {
        if (nfa == 1)
            state1(s[i]);
        else if (nfa == 2)
            state2(s[i]);
        else if (nfa == 3)
            state3(s[i]);
    }

    if (nfa == 1)
        return true;
    else
        return false;
}

int main() {
    string input;
    cout << "Enter a string: ";
    cin >> input;

    int len = input.length();

    if (checkInput(input, len))
        cout << "Accepted: String starts with '11'" << endl;
    else
        cout << "Not Accepted: String does not start with '11'" << endl;

    return 0;
}

