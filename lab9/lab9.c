/* Author(s): Ryan Kozak, Section 3.
 *
 * This is a lab9.c the csc60mshell
 * This program serves as a skeleton for doing lab 9 and 10.
 * Student is required to use this program to build a mini shell
 * using the specification as documented in direction.
 * Date: Fall 2017
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define MAXLINE 80
#define MAXARGS 20
#define MAX_PATH_LENGTH 50
#define TRUE 1

/* function prototypes */
int parseline(char *cmdline, char **argv);

//The two functions below will be needed in lab10. 
//Leave them here to be used later.
/* void process_input(int argc, char **argv); */
/* void handle_redir(int count, char *argv[]); */

/* ----------------------------------------------------------------- */
/*                  The main program starts here                     */
/* ----------------------------------------------------------------- */
int main(void)
{
    char cmdline[MAXLINE];
    char *argv[MAXARGS];
    int argc;
    int status;
    pid_t pid;

    /* Loop forever to wait and process commands */
    while (TRUE) {
	/* Print your shell name: csc60mshell (m for mini shell) */
	printf("csc60mshell> ");

	/* Read the command line */
	fgets(cmdline, MAXLINE, stdin);

	/* Call parseline to build argc/argv */
	argc = parseline(cmdline, argv);	


	for(int c = 0; c < argc; c++) {
	      printf ("Argv %i = %s \n", c, argv[c]); 	
	}

	/* If user hits enter key without a command, continue to loop */
	/* again at the beginning */
	/*  Hint: if argc is zero, no command declared */
	/*  Hint: look up for the keyword "continue" in C */
	if(argc == 0) {
		continue;
	}


	/* Handle build-in command: exit, pwd, or cd  */
	/* Put the rest of your code here */


	/* Handle the exit command */
	if ( strcmp(argv[0],"exit") == 0) {
		exit(EXIT_SUCCESS);
	}

	/* Handle the pwd command */
	else if(strcmp(argv[0],"pwd") == 0) {
	
		char cwd[MAX_PATH_LENGTH];
	
   		if (getcwd(cwd, sizeof(cwd)) != NULL) {
       			printf("%s\n", cwd);
		}
		
	}

	/* Handle the cd command */
	else if(strcmp(argv[0],"cd") == 0) {
	
		char *dir;
	
		/* Set destination to  home directory if no argument provided after cd */
		if(argc < 2) {
			dir = getenv("HOME");
		}
		/* Set destination directory to input string*/
		else {
			dir = argv[1];
		}
		
		/* Try and change directory, show error if fails. */
		if(chdir(dir) < 0 ) {
			perror("Error executing command");
		}
	}

	else {
	
	
 
//.......................IGNORE........................	
//	/* Else, fork off a process */
//      else {
//	   pid = fork();
//         switch(pid)
//	   {
//	   case -1:
//		perror("Shell Program fork error");
//	        exit(EXIT_FAILURE);
//	   case 0:
//		 /* I am child process. I will execute the command, */
//		 /* and call: execvp */
//		 process_input(argc, argv);
//		 break;
//	   default:
//		 /* I am parent process */
//		 if (wait(&status) == -1)
//		    perror("Parent Process error");
//		 else
//		    printf("Child returned status: %d\n",status);
//		 break;
//	   } 	/* end of the switch */
//...end of the IGNORE above.........................
	}	/* end of the if-else-if */
    }		/* end of the while */
} 		/* end of main */

/* ----------------------------------------------------------------- */
/*                  parseline                                        */
/* ----------------------------------------------------------------- */
/* parse input line into argc/argv format */

int parseline(char *cmdline, char **argv)
{
    int count = 0;
    char *separator = " \n\t"; /* Includes space, Enter, Tab */
 
    /* strtok searches for the characters listed in separator */
    argv[count] = strtok(cmdline, separator);

    while ((argv[count] != NULL) && (count+1 < MAXARGS)) 
    	argv[++count] = strtok((char *) 0, separator);
     		
    return count;
}
/* ----------------------------------------------------------------- */
/*                  process_input                                    */
/* ----------------------------------------------------------------- */
/*void process_input(int argc, char **argv) {                       */

    /* Step 1: Call handle_redir to deal with operators:            */
    /* < , or  >, or both                                           */


    /* Step 2: perform system call execvp to execute command        */
    /* Hint: Please be sure to review execvp.c sample program       */
    /* if (........ == -1) {                                        */
    /*    fprintf(stderr, "Error on the exec call\n");              */
    /*    _exit(EXIT_FAILURE);                                      */
    /* }                                                            */
 
//}
/* ----------------------------------------------------------------- */
//void handle_redir(int count, char *argv[])
/* ----------------------------------------------------------------- */


/* ----------------------------------------------------------------- */
