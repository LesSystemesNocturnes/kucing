
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "symbol_table.h"

#define MAX_VARS 100
#define MAX_FUNCS 100

typedef struct {
    char name[64];
    int value;
} Variable;

typedef struct {
    char name[64];
    char *body;
} Function;

static Variable variables[MAX_VARS];
static int variable_count = 0;

static Function functions[MAX_FUNCS];
static int function_count = 0;

void set_variable(const char *name, int value) {
    for (int i = 0; i < variable_count; i++) {
        if (strcmp(variables[i].name, name) == 0) {
            variables[i].value = value;
            return;
        }
    }
    if (variable_count < MAX_VARS) {
        strncpy(variables[variable_count].name, name, sizeof(variables[variable_count].name));
        variables[variable_count].value = value;
        variable_count++;
    } else {
        printf("Symbol table full!\n");
    }
}

int get_variable(const char *name) {
    for (int i = 0; i < variable_count; i++) {
        if (strcmp(variables[i].name, name) == 0) {
            return variables[i].value;
        }
    }
    printf("Variable '%s' not found\n", name);
    return 0;
}

void store_function(const char *name, const char *body) {
    for (int i = 0; i < function_count; i++) {
        if (strcmp(functions[i].name, name) == 0) {
            free(functions[i].body);
            functions[i].body = strdup(body);
            return;
        }
    }
    if (function_count < MAX_FUNCS) {
        strncpy(functions[function_count].name, name, sizeof(functions[function_count].name));
        functions[function_count].body = strdup(body);
        function_count++;
    } else {
        printf("Function table full!\n");
    }
}

const char *get_function(const char *name) {
    for (int i = 0; i < function_count; i++) {
        if (strcmp(functions[i].name, name) == 0) {
            return functions[i].body;
        }
    }
    return NULL;
}
