
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "parser.h"
#include "symbol_table.h"

int evaluate_expression(const char *expr) {
    int lhs = 0, rhs = 0;
    char op;
    char left[64], right[64];

    if (sscanf(expr, "%s %c %s", left, &op, right) == 3) {
        if (isalpha(left[0]))
            lhs = get_variable(left);
        else
            lhs = atoi(left);

        if (isalpha(right[0]))
            rhs = get_variable(right);
        else
            rhs = atoi(right);

        switch (op) {
            case '+': return lhs + rhs;
            case '-': return lhs - rhs;
            case '*': return lhs * rhs;
            case '/': return rhs != 0 ? lhs / rhs : 0;
            default:
                printf("[ERROR] Unknown operator: %c\n", op);
                return 0;
        }
    } else {
        if (isalpha(expr[0])) return get_variable(expr);
        return atoi(expr);
    }
}

int evaluate_condition(const char *expr) {
    char var[64], op[3];
    int value;
    if (sscanf(expr, "%s %2s %d", var, op, &value) != 3) {
        printf("[ERROR] Invalid condition format: %s\n", expr);
        return 0;
    }

    int var_value = get_variable(var);
    int result = 0;

    if (strcmp(op, "<") == 0) result = var_value < value;
    else if (strcmp(op, "<=") == 0) result = var_value <= value;
    else if (strcmp(op, ">") == 0) result = var_value > value;
    else if (strcmp(op, ">=") == 0) result = var_value >= value;
    else if (strcmp(op, "==") == 0) result = var_value == value;
    else if (strcmp(op, "!=") == 0) result = var_value != value;
    else printf("[ERROR] Unknown operator: %s\n", op);

    printf("[DEBUG] EVAL: %s %s %d → %d\n", var, op, value, result);
    return result;
}

void parse_line(const char *line, FILE *file) {
    char command[256];
    strcpy(command, line);
    char *trim = strtok(command, "\n");

    if (trim == NULL || strlen(trim) == 0) return;
    printf("[TRACE] parse_line: %s\n", trim);

    if (strncmp(trim, "print(", 6) == 0) {
        char content[128];
        sscanf(trim, "print(%[^)])", content);
        if (isalpha(content[0]))
            printf("%d\n", get_variable(content));
        else
            printf("%s\n", content);
    } else if (strncmp(trim, "let ", 4) == 0) {
        char var[64], expr[128];
        sscanf(trim, "let %s = %[^\;];", var, expr);
        int value = evaluate_expression(expr);
        set_variable(var, value);
    } else if (strncmp(trim, "function", 8) == 0) {
        char name[64], body[2048] = "";
        sscanf(trim, "function %s {", name);
        char buffer[256];
        while (fgets(buffer, sizeof(buffer), file)) {
            if (strchr(buffer, '}')) break;
            strcat(body, buffer);
        }
        store_function(name, body);
    } else if (strchr(trim, '(') && strchr(trim, ')') && strchr(trim, ';')) {
        char fname[64];
        sscanf(trim, "%[^ (]", fname);
        const char *func_body = get_function(fname);
        if (func_body) {
            FILE *temp = fmemopen((void *)func_body, strlen(func_body), "r");
            char line_buf[256];
            while (fgets(line_buf, sizeof(line_buf), temp)) {
                parse_line(line_buf, temp);
            }
            fclose(temp);
        } else {
            printf("[ERROR] Unknown function: %s\n", fname);
        }
    } else {
        printf("[WARN] Unknown command: %s\n", trim);
    }
}
