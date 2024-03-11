#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    int pipefd[2];
    pid_t pid;
    char message_parent[] = "Hello, child!";
    char message_child[] = "Hi, parent!";
    char buffer[100];

    if (pipe(pipefd) == -1) {
        perror("pipe");
        return 1;
    }

    pid = fork();
    if (pid < 0) {
        perror("fork");
        return 1;
    }

    if (pid == 0) { // Child process
        close(pipefd[1]); // Close unused write end

        // Read from pipe
        read(pipefd[0], buffer, sizeof(buffer));
        printf("Child received: %s\n", buffer);

        // Send message to parent
        write(pipefd[1], message_child, sizeof(message_child));

        close(pipefd[0]); // Close read end
    } else { // Parent process
        close(pipefd[0]); // Close unused read end

        // Send message to child
        write(pipefd[1], message_parent, sizeof(message_parent));

        // Wait for child's response
        read(pipefd[0], buffer, sizeof(buffer));
        printf("Parent received: %s\n", buffer);

        close(pipefd[1]); // Close write end
    }

    return 0;
}

