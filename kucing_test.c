#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_VARS 100

typedef struct {
    char *key;
    char *value;
} Variable;

Variable variables[MAX_VARS];
int var_count = 0;

void set_var(const char *key, const char *value) {
    for (int i = 0; i < var_count; ++i) {
        if (strcmp(variables[i].key, key) == 0) {
            free(variables[i].value);
            variables[i].value = strdup(value);
            return;
        }
    }
    variables[var_count].key = strdup(key);
    variables[var_count].value = strdup(value);
    var_count++;
}

const char* get_var(const char *key) {
    for (int i = 0; i < var_count; ++i) {
        if (strcmp(variables[i].key, key) == 0) {
            return variables[i].value;
        }
    }
    return "";
}

char* substitute_vars(const char *line) {
    static char buffer[512];
    int i = 0;

    while (*line && i < sizeof(buffer) - 1) {
        if (*line == '$') {
            line++;  // skip the $

            char varname[64] = {0};
            int j = 0;

            while (*line && (isalnum(*line) || *line == '_') && j < 63) {
                varname[j++] = *line++;
            }
            varname[j] = '\0';

            const char *val = get_var(varname);
            for (int k = 0; val[k] && i < sizeof(buffer) - 1; ++k) {
                buffer[i++] = val[k];
            }

            continue;  // critical!
        }

        buffer[i++] = *line++;
    }

    buffer[i] = '\0';
    return buffer;
}

int main(void) {
    printf("What is your name?\n");

    printf("Name: ");
    char input[256];
    if (fgets(input, sizeof(input), stdin)) {
        input[strcspn(input, "\n")] = '\0';
        set_var("name", input);
    }

    const char *msg = "Hello $name! Welcome to Kucing!";
    printf("%s\n", substitute_vars(msg));

    return 0;
}
