#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>

void exercice_1();

void exercice_2();

void exercice_3();

void exercice_4();

int main(const int argc, const char** argv) {
    if (argc >= 2) {
        if (strcmp(argv[1], "exercice_1") == 0) {
            exercice_1();
        } else if (strcmp(argv[1], "exercice_2") == 0) {
            exercice_2();
        } else if (strcmp(argv[1], "exercice_3") == 0) {
            exercice_3();
        } else if (strcmp(argv[1], "exercice_4") == 0) {
            exercice_4();
        } else {
            printf("%s not found.\n", argv[1]);
        }
    } else {
        fprintf(stderr, "Usage: %s <program> [args].\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    exit(EXIT_SUCCESS);
}

void exercice_1_handler(const int signo, siginfo_t* info, void* context) {
    if (signo == SIGTERM) {
        printf("Caught signal term.\n");
    } else if (signo == SIGKILL) {
        printf("Caught signal kill.\n");
    }
}

void exercice_1() {
    const pid_t pid = fork();
    struct sigaction handle = {0};
    handle.sa_flags = SA_SIGINFO;
    handle.sa_sigaction = &exercice_1_handler;
    if (sigaction(SIGTERM, &handle, NULL) == -1) {
        perror("sigterm");
        exit(EXIT_FAILURE);
    }
    // if (sigaction(SIGKILL, &handle, NULL) == -1) {
    //     perror("sigkill");
    //     exit(EXIT_FAILURE);
    // } // cannot be cought
    pid_t ppid;
    switch (pid) {
        case -1:
            perror("fok");
            exit(EXIT_FAILURE);
        case 0:
            ppid = getppid();
            kill(ppid, SIGTERM);
        // kill(ppid, SIGKILL);
            break;
        default:
            pause();
            pause();
            break;
    }
    exit(EXIT_SUCCESS);
}

void exercice_2() {
    const pid_t pork = fork();
    switch (pork) {
        case -1:
            perror("fok");
            exit(EXIT_FAILURE);
        case 0: {
            const pid_t ppid = getppid();
            printf("f1\n");
            kill(ppid, SIGCONT);
            raise(SIGSTOP);
            printf("f2\n");
            kill(ppid, SIGCONT);
        }
        break;
        default: {
            raise(SIGSTOP);
            printf("p1\n");
            kill(pork, SIGCONT);
            raise(SIGSTOP);
            printf("p2\n");
        }
        break;
    }
    exit(EXIT_SUCCESS);
}

volatile int count = 0;

void exercice_3_handle_alarm(int signo) {
    if (count >= 3) {
        printf("No question, no awnser!!\n");
        exit(EXIT_FAILURE);
    }
    printf("Waiting... (%d)\n", ++count);
    alarm(5);
}

void exercice_3() {
    signal(SIGALRM, exercice_3_handle_alarm);
    alarm(5);
    printf("Enter a question: ");
    char question[255];
    scanf("%s", question);
    printf("%s\n", question);
    exit(EXIT_SUCCESS);
}

void exercice_4_handle_sigchld(int signo) {
    printf("Caught signal SIGCHLD.\n");
}

void exercice_4() {
    signal(SIGCHLD, exercice_4_handle_sigchld);
    switch (fork()) {
        case -1:
            perror("fok");
            exit(EXIT_FAILURE);
        case 0:
            printf("Gnehehe %d\n", getpid());
            pause();
            printf("Noooo!\n");
            break;
        default:
            sleep(1);
            break;
    }
    exit(EXIT_SUCCESS);
}
