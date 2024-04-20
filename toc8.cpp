//WAP to implement NFA that accepts the string containing bab as a substring.

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isAccepted(char *str) {
    int currentState = 0;
    int len = strlen(str);
    
    for (int i = 0; i < len; i++) {
        if (currentState == 0 && str[i] == 'b') {
            currentState = 1;
        } else if (currentState == 1 && str[i] == 'a') {
            currentState = 2;
        } else if (currentState == 2 && str[i] == 'b') {
            return true; 
        } else {
            currentState = (str[i] == 'b') ? 1 : 0; 
        }
    }
    
    return false; 
}

int main() {
    char str[100];
    
    printf("Enter the string: ");
    scanf("%s", str);
    
    if (isAccepted(str)) {
        printf("Accepted.");
    } else {
        printf("Rejected.");
    }
    
    return 0;
}
