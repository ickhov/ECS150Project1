#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include "date.h"

void readNextCommand(char* cmd, char *command_line);

int main(int argc, char *argv[])
{
    /*
	char *cmd = "/bin/date -u";
	int retval;

	//retval = system(cmd);
	fprintf(stdout, "Return status value for '%s': %d\n", cmd, retval);*/
    
    /*
    pid_t pid;
    char *cmd = "/bin/date";
    char *args[] = { cmd, "-u", NULL };
    
    pid = fork();
    if (pid == 0) {
        // child process
        execv(cmd, args);
        perror("execv");
        exit(1);
    } else if (pid > 0) {
        // parent process
        int retval;
        wait(&retval);
        fprintf(stderr, "+ completed '%s %s' [%d]\n", cmd, args[1], retval);
    } else {
        perror("fork");
        exit(1);
    }
     */
    
    char *command;
    size_t command_size = 512;
    
    // allocate space to store the command line
    command = (char *) malloc(command_size * sizeof(char));
    
    if (command == NULL) {
        exit(1);
    }
    
    while(1) {
       
        printf("sshell$: ");
        
        // get the command after sshell$:
        getline(&command, &command_size, stdin);
        
        // check if the command has a trailing new line
        char *new_line = strchr(command, '\n');
        
        // if ptr is not NULL, then there's a trailing new line
        // set ptr to terminating character
        if (new_line != NULL) {
            *new_line = '\0';
        }
        
        char *first_space = strchr(command, ' ');
        
        int first_space_num = first_space - command;
        
        printf("%d\n", first_space_num);
        
        char* cmd = (char *) malloc(command_size * sizeof(char));
        
        readNextCommand(cmd, command);
        
        printf("%s\n", cmd);
        
        readNextCommand(cmd, command);
        
        printf("%s\n", cmd);
        
        /*
        
        
        char *date = "date";
        
        // check if the entered command matches one of the built-in command
        if (strncmp(command, date, 512) == 0) {
            pid_t pid;
            char *cmd = "/bin/date";
            char *args[] = { cmd, "-u", NULL };
            
            pid = fork();
            if (pid == 0) {
                // child process
                execv(cmd, args);
                perror("execv");
                exit(1);
            } else if (pid > 0) {
                // parent process
                int retval;
                wait(&retval);
                fprintf(stderr, "+ completed '%s' [%d]\n", command, retval);
            } else {
                perror("fork");
                exit(1);
            }
        }
         */
    }
    
    
    
    
	return EXIT_SUCCESS;
}

void readNextCommand(char* cmd, char *command_line) {
    int isSpace = 0;
    
    while(isSpace == 0) {
        if (*command_line != ' ') {
            *cmd = *command_line;
            cmd++;
            command_line++;
        } else {
            isSpace = 1;
        }
    }
}
