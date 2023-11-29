#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "parser.h"
#include "cmd.h"

int main(int argc, char* argv[]) {
  char cmdline[MAX_LINE_SIZE]; 
  char* cmdtoks[MAX_CMD_SIZE]; 
  cmd_t cmds[MAX_CMD_SIZE];
  cmd_t* current;
  
  while (1) {
    
    printf("$ ");
    
    
    if (fgets(cmdline, MAX_LINE_SIZE, stdin)==NULL) break;
    cmdline[strlen(cmdline)-1]='\0';
    
    
    for (current=cmds; current!=NULL; ) {
      
      
      
    }
  }
  
  fprintf(stderr, "\nGood bye!\n");
  return 0;
}
