#include <stdio.h>
#include <ctype.h>

int main() {
    FILE *file;
    char filename[100];
    char ch;
    int letters = 0, words = 0, lines = 0;
    int inword = 0; // Flag to indicate if currently inside a word

    printf("Enter the filename: ");
    scanf("%s", filename);

    // Open the file
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Unable to open the file.\n");
        return 1;
    }

    // Read the file character by character
    while ((ch = fgetc(file)) != EOF) {
        if (isalpha(ch)) {
            letters++;
        }
        if (isspace(ch) && inword) {
            words++;
            inword = 0;
        }
        if (ch == '\n') {
            lines++;
        }
        if (!isspace(ch) && !inword) {
            inword = 1;
        }
    }

    // Close the file
    fclose(file);

    printf("Number of letters: %d\n", letters);
    printf("Number of words: %d\n", words);
    printf("Number of lines: %d\n", lines);

    return 0;
}
