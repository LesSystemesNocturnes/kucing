#ifndef PARSER_H
#define PARSER_H

void parse_line(const char *line, FILE *source);
void eval_block(FILE *source);
void handle_if(const char *line, FILE *source);
void handle_while(const char *line, FILE *source);
void handle_for(const char *line, FILE *source);
int evaluate_condition(const char *expr);

#endif
