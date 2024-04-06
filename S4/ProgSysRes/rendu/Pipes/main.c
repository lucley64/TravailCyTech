#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

void exercice_1() {
    int pipefd1[2], pipefd2[2];
    char buf;

    if (pipe(pipefd1) == -1 || pipe(pipefd2) == -1) {
        perror("pipe");
        return;
    }

    switch (fork()) {
        case -1:
            fprintf(stderr, "No pork");
            break;
        case 0:
            close(pipefd1[1]);
            close(pipefd2[0]);
            while (read(pipefd1[0], &buf, 1) > 0) {
                printf("%c", buf);
            }
            printf("\n");

            write(pipefd2[1], "Salut Père", 11 * sizeof(char));

            close(pipefd2[0]);
            close(pipefd1[0]);
            _exit(EXIT_SUCCESS);
        default:
            close(pipefd1[0]);
            close(pipefd2[1]);
            write(pipefd1[1], "Salut Fils", 10 * sizeof(char));
            close(pipefd1[1]);

            while (read(pipefd2[0], &buf, 1) > 0) {
                printf("%c", buf);
            }
            close(pipefd2[0]);

            wait(NULL);
            exit(EXIT_SUCCESS);
    }
}

void exercice_4_a() {
    mkfifo("my_pipe", S_IRWXU | S_IRWXG | S_IRWXO);
    int pipefd = open("my_pipe", O_WRONLY);
    write(pipefd, "un message", 10 * sizeof(char));
    close(pipefd);
    pipefd = open("my_pipe", O_RDONLY);
    char buf;
    while (read(pipefd, &buf, 1) > 0) {
        printf("%c", buf);
    }
    printf("\n");
    close(pipefd);
    exit(EXIT_SUCCESS);
}

void exercice_4_b() {
    int pipefd = open("my_pipe", O_RDONLY);
    char buf;
    while (read(pipefd, &buf, 1) > 0) {
        printf("%c", buf);
    }
    close(pipefd);
    pipefd = open("my_pipe", O_WRONLY);
    write(pipefd, "un autre message", 16 * sizeof(char));
    close(pipefd);
}



int main(const int argc, const char** argv) {



    if (argc >= 2) {
        if (strcmp(argv[1], "exercice_1") == 0) {
            exercice_1();
        }
        else if (strcmp(argv[1], "exercice_4") == 0) {
            if (argc == 3) {
                if (strcmp(argv[2], "a") == 0) {
                    exercice_4_a();
                }
                else {
                    exercice_4_b();
                }
            }
        }

    }


    exit(EXIT_SUCCESS);
}
