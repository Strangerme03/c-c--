// WAP to implement regular expressions that identifies 10-digit phone number starting with 98 or 97.

#include <iostream>
#include <regex>

int main() {
    std::string input;
    std::cout << "Enter a phone number: ";
    std::cin >> input;

    // Define the regular expression pattern
    std::regex pattern("^(98|97)\\d{8}$");

    // Check if the input matches the pattern
    if (std::regex_match(input, pattern)) {
        std::cout << "Valid phone number!\n";
    } else {
        std::cout << "Invalid phone number.\n";
    }

    return 0;
}
