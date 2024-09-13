//
// Created by cytech on 14/04/24.
//

#include "part_b.h"

#include <stdio.h>

#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <regex.h>
#include <ctype.h>
#include <limits.h>


void client_1() {
    int client_pipe_fd = open("PartB/pipe_client", O_RDONLY);
    int server_pipe_fd = open("PartB/pipe_server", O_WRONLY);

    printf("Client operational.\n");

    char input[1024];
    do {
        fgets(input, 1024 * sizeof(char), stdin);


        printf("Sending to server: %s\n", input);

        write(server_pipe_fd, input, strlen(input) * sizeof(char));

        char *rep = malloc(sizeof(char) * strlen(input));

        read(client_pipe_fd, rep, sizeof(char) * strlen(input));

        printf("Server answer: %s\n", rep);

        free(rep);
    } while (strcmp(input, "exit") != 0);
}

void server_1() {
    int client_pipe_fd = open("PartB/pipe_client", O_WRONLY);
    int server_pipe_fd = open("PartB/pipe_server", O_RDONLY);

    char input[1024];
    do {
        input[0] = '\0';

        read(server_pipe_fd, input, 1024 * sizeof(char));

        printf("Request → %s ←\n", input);

        size_t len = strlen(input);
        char *rep = malloc(len * sizeof(char));
        for (int i = 0; i < len; ++i) {
            rep[i] = input[len - i - 1];
        }

        printf("Answer → %s ←", rep);

        write(client_pipe_fd, rep, len * sizeof(char));

        free(rep);

    } while (strcmp(input, "exit") != 0);
}

void client_2() {
    int client_pipe_fd = open("PartB/pipe_client", O_RDONLY);
    int server_pipe_fd = open("PartB/pipe_server", O_WRONLY);

    printf("Client operational.\n");

    char input[1024];
    do {
        fgets(input, 1024 * sizeof(char), stdin);

        printf("Sending to server: %s\n", input);

        write(server_pipe_fd, input, strlen(input) * sizeof(char));

        int rep;

        read(client_pipe_fd, &rep, sizeof(int));

        printf("Server answer: %d\n", rep);

    } while (strcmp(input, "exit") != 0);
}

int is_operator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

int calculate(int num1, int num2, char op) {
    switch (op) {
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case '*':
            return num1 * num2;
        case '/':
            if (num2 == 0) {
                printf("Error: Division by zero\n");
                exit(1);
            }
            return num1 / num2;
        default:
            printf("Error: Invalid operator\n");
            exit(1);
    }
}

void server_2() {
    int client_pipe_fd = open("PartB/pipe_client", O_WRONLY);
    int server_pipe_fd = open("PartB/pipe_server", O_RDONLY);

    char input[1024];

    do {
        input[0] = '\0';

        read(server_pipe_fd, input, 1024 * sizeof(char));

        printf("Request → %s ←\n", input);

        size_t len = strlen(input);

        int num1 = INT_MAX, num2;
        char op;
        int found_operator = 0;
        int valid = 1;
        for (int i = 0; i < len; i++) {
            if (isdigit(input[i])) {
                if (found_operator) {
                    num2 = atoi(&input[i]);
                    break;
                } else if (num1 == INT_MAX) {
                    num1 = atoi(&input[i]);
                }
            } else if (is_operator(input[i])) {
                if (found_operator) {
                    valid = 0;
                }
                op = input[i];
                found_operator = 1;
            } else if (!isspace(input[i])) {
                valid = 0;
            }
        }

        int rep = valid && found_operator ? calculate(num1, num2, op) : 0;


        printf("Answer → %d ←", rep);

        write(client_pipe_fd, &rep, sizeof(int));


    } while (strcmp(input, "exit") != 0);
}

void part_b(const int argc, const char **argv) {
    mkfifo("PartB/pipe_client", S_IRWXG | S_IRWXU | S_IRWXO);
    mkfifo("PartB/pipe_server", S_IRWXG | S_IRWXU | S_IRWXO);

    if (argc != 3) {
        fprintf(stderr, "Please indicate client_<num> or server_<num>");
        exit(EXIT_FAILURE);
    } else if (strcmp(argv[2], "client_1") == 0) {
        client_1();
    } else if (strcmp(argv[2], "client_2") == 0) {
        client_2();
    } else if (strcmp(argv[2], "server_1") == 0) {
        server_1();
    } else if (strcmp(argv[2], "server_2") == 0) {
        server_2();
    }


}