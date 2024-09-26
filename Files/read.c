#include <stdio.h>

int main() {
    FILE *file;
    char buffer[10];

    file = fopen("example.txt", "r");
    if (file == NULL) {
        printf("Error in opening file!\n");
        return 1;
    }

    // Read the file in chunks until the end of the file
    while (fgets(buffer, 10, file) != NULL) {
        printf("%s", buffer);  // Print each chunk of 100 characters or less
    }

    fclose(file);
    return 0;
}
