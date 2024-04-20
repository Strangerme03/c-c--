//WAP to implement NFA that accepts the string ending with 00.

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isAccepted(char *str) {
    int currentState = 0;
    int len = strlen(str);
    
    for (int i = 0; i < len; i++) {
        if (currentState == 0 && str[i] == '0') {
            currentState = 1;
        } else if ((currentState == 0 || currentState == 1) && str[i] == '1') {
            currentState = 0;
        } else if (currentState == 1 && str[i] == '0') {
            currentState = 2;
        } else if (currentState == 2 && str[i] == '0') {
            currentState = 2;
        } else if (currentState == 2 && str[i] == '1') {
            currentState = 1;
        } else {
            return false;
        }
    }
    
    return currentState == 2;
}

int main() {
    char str[100];
    
    printf("Enter the string: ");
    scanf("%s", str);
    
    if (isAccepted(str)) {
        printf("String is accepted.\n");
    } else {
        printf("String is not accepted.\n");
    }
    
    return 0;
}
