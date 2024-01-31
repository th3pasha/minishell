/*
  A basic shell implementation.

  Ayoub AZIZI, UPJV, 2023
  
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "parser.h"
#include "cmd.h"

void terminal(){
  char *cwd; 
  char *usr;
  getcwd(cwd, MAX_LINE_SIZE);
  getlogin_r(usr, MAX_LINE_SIZE);

  printf("%s@%s$ ", usr, cwd);
}

int main(int argc, char* argv[]) {
  char cmdline[MAX_LINE_SIZE]; 
  char* cmdtoks[MAX_CMD_SIZE]; 
  cmd_t cmds[MAX_CMD_SIZE];
  cmd_t* current;
  
  char* cwd;

  while (1) {
    terminal();
    
    if (fgets(cmdline, MAX_LINE_SIZE, stdin)==NULL) break;
    cmdline[strlen(cmdline)-1]='\0';
    
    for (current=cmds; current!=NULL; ) {
      
      
      
    }
  }
  fprintf(stderr, "\nExiting ~shell!\n");
  return 0;
}
