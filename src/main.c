
#include <stdio.h>
#include <stdlib.h>
#include "../include/parser.h"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename.kc>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Could not open file");
        return 1;
    }

    char line[256];

    printf("\n😺 KUCING v0.1.0 🐾\n\n");

    while (fgets(line, sizeof(line), file)) {
        parse_line(line, file);  // now correctly passes the file pointer
    }

    fclose(file);
    return 0;
}
