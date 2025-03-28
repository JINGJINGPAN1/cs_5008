#include <stdio.h>
#include <string.h>
// How many unique permutations can be made from the characters of the word “CAT”?
// answer: 6 unique permutations. "CAT", "CTA", "ACT", "ATC", "TAC", "TCA"

// Write a C program to generate all permutations and explain its time complexity.
// Time complexity will be: O(n! * n) where n is the length of the give string.
// Recursive Calls: For a string of length n, there are n! permutations.
// Each permutation requires n recursive calls (one for each character position).
// Overall Complexity:
// Total operations = O(n! × n).

// Here, for "CAT", there are 3 characthers, so the time complexity is O(3! * 3) = O(18)


void swap(char *x, char *y) {
    char temp = *x;
    *x = *y;
    *y = temp;
}
void generatePermutations(char *str, int start, int end) {
    if (start == end) {
    // TODO: Print the current permutation
        printf("%s\n", str);
    } else {
        for (int i = start; i <= end; i++) {
        // TODO: Swap the current character with the character at index ’i’
            swap(&str[start], &str[i]);
        // TODO: Recursively generate permutations for the next character
            generatePermutations(str, start + 1, end);
        // TODO: Backtrack (swap back to restore the original string)
            swap(&str[start], &str[i]);
        }
    }
}
int main() {
    char str[] = "CAT";
    int n = strlen(str); // Length of the string
    // TODO: Call the function with proper arguments to generate permutations
    generatePermutations(str, 0, n - 1);
    return 0;
}


 

