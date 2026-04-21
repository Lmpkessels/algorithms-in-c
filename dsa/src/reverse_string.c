#include <stdio.h>

// Get the length of a string through incrementing count for as long as
// null character isn't reached
int strlenc(char *s) {
    int count = 0;

    while (*s != '\0') {
        count++;
        s++;
    }

    return count;
}

// Reverse string trough swapping the right indice with the left indice (
// H with !, e with d, etc...)
char reverse_string(char *s) {
    int left = 0;
    int right = strlenc(s) - 1;
    char temp;

    while (left < right) {
        // Swap left indices with right indices
        temp = s[left];
        s[left] = s[right];
        s[right] = temp;

        left++;
        right--;
    }
}

int main(void) {
    char string[20] = "Hello, World!";
    
    reverse_string(string);

    printf("%s\n", string);
    return 0;
}