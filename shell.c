#include <stdio.h>
#include "shell.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
int execvp(const char *file, char *const argv[]);

void execute(char* const args[])
{
      int i;
      printf("*** Entered:");
      for (i = 0; args[i] != NULL; i++)
      {
        printf(" %s", args[i]);
      }
      printf(" (%d words)\n", i);
    
      int status = execvp(args[0],args);
      if (status == 1)
      { /* error occurred*/
        printf("Command not found\n");
        printf("Command exited with %d\n",status);              // status code other   
        return;
      }
      else if(status == 2)
      {
        printf("%s: cannot access '%s' : No such file or directory exists\n",args[0],args[1] );
        printf("Command exited with %d\n",status);              // status code other   
        return;
      }
      else
      {
        if (args[0] == "exit")
          {
              exit(0);
          }
        else if (status == 0 || status == -1)
          {
            pid_t pid, pid1;
            pid = fork();
            /* fork a child process*/
            if (pid < 0) 
            { /* error occurred*/
              printf("Fork Failed\n");
              printf("Command exited with %d\n",pid);              // status code other   
            }
            else if (pid == 0) 
            { /* child process*/
              pid1 = getpid();
              printf("child: pid = %d\n",pid);
              printf("child: pid1 = %d\n",pid1);
            }
            else 
            { /* parent process*/
              pid1 = getpid();
              printf("parent: pid = %d\n",pid);
              printf("parent: pid1 = %d\n",pid1);
              wait(NULL);
            }
          }
          else
          {
            execvp(args[0],args);
          }
        printf("Command exited sucessfully\n");   // status code 0
      }
      
}
