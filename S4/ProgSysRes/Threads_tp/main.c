#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

volatile int global_variable = 6174;

void* my_thread_1(void* arg) {
    const int mem = global_variable;

    printf("Thead no: %s started\n", (char *) arg);

    while (mem == global_variable) {
    }
    printf("Thread %s, global variable changed: %d\n", (char *) arg, global_variable);


    pthread_exit(EXIT_SUCCESS);
}

void exercice_1() {
    pthread_t th1, th2;

    void* ret;

    if (pthread_create(&th1, NULL, my_thread_1, "1") < 0) {
        fprintf(stderr, "No thread sadge\n");
        exit(EXIT_FAILURE);
    }
    if (pthread_create(&th2, NULL, my_thread_1, "2") < 0) {
        fprintf(stderr, "No thread sadge\n");
        exit(EXIT_FAILURE);
    }

    sleep(5);

    global_variable++;
    pthread_join(th2, &ret);
    pthread_join(th1, &ret);


    exit(EXIT_SUCCESS);
}

void* thread_exo_2_1(void* arg) {

    sleep(15);
    pthread_exit(EXIT_SUCCESS);
}
void* thread_exo_2_2(void* arg) {

    sleep(15);

    pthread_exit(EXIT_SUCCESS);
}
void* thread_exo_2_3(void* arg) {

    fork();

    sleep(15);

    pthread_exit(EXIT_SUCCESS);
}

void exercice_2() {
    pthread_t thread1, thread2, thread3;
    if (pthread_create(&thread1, NULL, thread_exo_2_1, "1") < 0) {
        fprintf(stderr, "No thread sadge\n");
        exit(EXIT_FAILURE);
    }
    if (pthread_create(&thread2, NULL, thread_exo_2_2, "2") < 0) {
        fprintf(stderr, "No thread sadge\n");
        exit(EXIT_FAILURE);
    }
    if (pthread_create(&thread3, NULL, thread_exo_2_3, "2") < 0) {
        fprintf(stderr, "No thread sadge\n");
        exit(EXIT_FAILURE);
    }

    sleep(10);



    void* ret;
    pthread_join(thread1, &ret);
    pthread_join(thread2, &ret);
    pthread_join(thread3, &ret);

    exit(EXIT_SUCCESS);
}


int main(const int argc, const char** argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <program> [args]", argv[0]);
        exit(EXIT_FAILURE);
    }
    if (strcmp(argv[1], "exercice_1") == 0) {
        exercice_1();
    } else if (strcmp(argv[1], "exercice_2") == 0) {
        exercice_2();
    }


    return 0;
}
