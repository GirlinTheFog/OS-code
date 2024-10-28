#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    // Create a child process using fork()
    pid_t child_pid = fork();

    if (child_pid == -1) {  // Error occurred during fork
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (child_pid == 0) {  // Child process
        printf("Child process (PID: %d) is running.\n", getpid());

        // Execute a different program using exec()
        execl("/bin/date", "date", NULL);  // Run the `date` command

        // If exec fails, terminate the child process
        perror("exec failed");
        exit(EXIT_FAILURE);
    } else {  // Parent process
        printf("Parent process (PID: %d) is waiting for the child to terminate.\n", getpid());

        // Wait for the child process to terminate
        int status;
        wait(&status);
        printf("Parent resumes.\n");

        // Check how the child terminated
        if (WIFEXITED(status)) {
            printf("Child process (PID: %d) terminated with status %d.\n", child_pid, WEXITSTATUS(status));
        } else if (WIFSIGNALED(status)) {
            printf("Child process (PID: %d) terminated due to signal %d.\n", child_pid, WTERMSIG(status));
        } else {
            printf("Child process (PID: %d) terminated abnormally.\n", child_pid);
        }
    }

    return 0;
}
