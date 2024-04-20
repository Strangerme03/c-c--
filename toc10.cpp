#include <iostream>
#include <regex>

int main() {
    std::string input;
    std::cout << "Enter a string: ";
    std::cin >> input;

    // Define the regular expression pattern
    std::regex pattern(".*aba.*");

    // Check if the input matches the pattern
    if (std::regex_match(input, pattern)) {
        std::cout << "The string contains the substring \"aba\".\n";
    } else {
        std::cout << "The string does not contain the substring \"aba\".\n";
    }

    return 0;
}
