#ifndef _PROCESSUS_H
#define _PROCESSUS_H

#include <unistd.h>

#include "parser.h"


typedef struct cmd_t {
  pid_t pid;
  int status;
  int stdin, stdout, stderr;
  int wait;
  char* path;
  char* argv[MAX_CMD_SIZE];
  int fdclose[MAX_CMD_SIZE];
  struct cmd_t* next;
  struct cmd_t* next_success;
  struct cmd_t* next_failure;
} cmd_t;


int exec_cmd(cmd_t* p);



int init_cmd(cmd_t* p);


int parse_cmd(char* tokens[], cmd_t* cmds, size_t max);

#endif


int exec_cmd(cmd_t* p);
