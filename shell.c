#include <stdio.h>
#include "shell.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>


void execute(char* const args[])
{
  int i;
  printf("*** Entered:");
  for (i = 0; args[i] != NULL; i++)
    printf(" %s", args[i]);
  printf(" (%d words)\n", i);

  int status = exec args;
  if (status == 1)
  { /* error occurred */
    fprintf(stderr, "Command not found\n");
    fprintf("Command exited with %d\n",status);              // status code other   
    return 1;
  }
  if else(status == 2)
  {
    char delim[] = " ";
    char *ptr = strtok(args, delim);
    ptr = strtok(NULL, delim);
    fprintf("%d: cannot access '%d' : No such file or directory exists\n",ptr[0], ptr[1] );
    fprintf("Command exited with %d\n",status);              // status code other   
    return 1;
  }
  else
  {    
      if (args.equals("fork")
      {
        pid_t pid, pid1;
        pid = exec(args);
        /* fork a child process */
        if (pid < 0) 
        { /* error occurred */
          fprintf(stderr, "Fork Failed\n");
          return 1;
        }
        else if (pid == 0) 
        { /* child process */
          pid1 = getpid();
          printf("child: pid = %d\n",pid);
          printf("child: pid1 = %d\n",pid1);
        }
        else 
        { /* parent process */
          pid1 = getpid();
          printf("parent: pid = %d\n",pid);
          printf("parent: pid1 = %d\n",pid1);
          wait(NULL);
        }
      }
      else
      {
        exec(args);
      }
    fprintf(stderr, "Command exited sucessfully\n");   // status code 0
  }

      

  exit();
}

