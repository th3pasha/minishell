#ifndef _BUILTIN_H
#define _BUILTIN_H

#include "cmd.h"

int is_builtin(const char* cmd);


int builtin(cmd_t* cmd);


int cd(const char* path, int fderr);


int export(const char* var, const char* value, int fderr);


int exit_shell(int ret, int fderr);

#endif
