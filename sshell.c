#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    /*
	char *cmd = "/bin/date -u";
	int retval;

	//retval = system(cmd);
	fprintf(stdout, "Return status value for '%s': %d\n", cmd, retval);*/
    
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
        wait(&retval); /* could also be waitpid(pid, &status, 0) */
        fprintf(stderr, "+ completed '%s %s' [%d]\n", cmd, args[1], retval);
    } else {
        perror("fork");
        exit(1);
    }

	return EXIT_SUCCESS;
}
