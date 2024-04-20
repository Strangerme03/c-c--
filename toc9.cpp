// WAP to implement regular expressions that identifies 10-digit phone number starting with 98 or 97.

#include <stdio.h>
#include <regex.h>

#define MAX_MATCHES 1
#define BUFFER_SIZE 100

int main() {
    char input[BUFFER_SIZE];
    regex_t regex;
    int reti;
    char msgbuf[BUFFER_SIZE];

    reti = regcomp(&regex, "^(98|97)[0-9]{8}$", REG_EXTENDED);
    if (reti) {
        fprintf(stderr, "Could not compile regex\n");
        return 1;
    }

    printf("Enter the phone number: ");
    scanf("%s", input);

    reti = regexec(&regex, input, 0, NULL, 0);
    if (!reti) {
        printf("Valid phone number\n");
    } else if (reti == REG_NOMATCH) {
        printf("Invalid phone number\n");
    } else {
        regerror(reti, &regex, msgbuf, sizeof(msgbuf));
        fprintf(stderr, "Regex match failed: %s\n", msgbuf);
        return 1;
    }

    regfree(&regex);

    return 0;
}

