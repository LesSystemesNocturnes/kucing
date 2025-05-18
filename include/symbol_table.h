#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

void set_variable(const char *name, int value);
int get_variable(const char *name);

void store_function(const char *name, const char *body);
const char *get_function(const char *name);

#endif
