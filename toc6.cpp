#include <iostream>
using namespace std;

bool checkInput(string s) {
    // Check if the string starts with '11'
    return (s.substr(0, 2) == "11");
}

int main() {
    string input;
    cout << "Enter a string: ";
    cin >> input;

    if (checkInput(input))
        cout << "Accepted: String starts with '11'" << endl;
    else
        cout << "Not Accepted: String does not start with '11'" << endl;

    return 0;
}
