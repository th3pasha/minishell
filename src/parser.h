#ifndef _PARSER_H
#define _PARSER_H

#define MAX_LINE_SIZE   1024
#define MAX_CMD_SIZE    256


void move(char* dest, const char* src, size_t n);
int trim(char* str);
int clean(char* str);
int separate_s(char* str, char* s, size_t max);
int substenv(char* str, size_t max);
int strcut(char* str, char sep, char** tokens, size_t max);
size_t copy_until(char* src, char* dest, char delim, size_t max);
void replace_env(char* str, size_t* j, size_t* i);
int strcut_s(char* str, char sep, char** tokens, size_t max);
#endif
