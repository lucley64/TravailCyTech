#include <stdio.h>
#include <pthread.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

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

void* print_num_thread() {
    for (int i = 0; i < 3; ++i) {
        printf("Thread number %lu\n", pthread_self());
    }
    pthread_exit(EXIT_SUCCESS);
}

void exercice_3() {
    pthread_t threads[4];
    for (pthread_t* t = threads; t != threads + 4; t++) {
        if (pthread_create(t, NULL, print_num_thread, NULL) < 0) {
            fprintf(stderr, "No thread sadge\n");
            exit(EXIT_FAILURE);
        }
    }

    for (const pthread_t* t = threads; t != threads + 4; t++) {
        pthread_join(*t, NULL);
    }
    exit(EXIT_SUCCESS);
}


const int mat[] = {5, 2, 3, 6};

typedef struct {
    int i;
    int res;
} tdata;

void* calc(void* num) {
    tdata* n = num;
    int res = 0;

    const int col = n->i % 2;
    const int row = n->i / 2;

    for (int i = 0; i < 2; ++i) {
        res += mat[row * 2 + i] * mat[col + i * 2];
    }

    n->res = res;
    pthread_exit(EXIT_SUCCESS);
}

void exercice_4() {
    pthread_t t[4];
    tdata data[4];
    for (int i = 0; i < 4; ++i) {
        data[i].i = i;
        if (pthread_create(&t[i], NULL, calc, &data[i]) < 0) {
            fprintf(stderr, "No thread sadge\n");
            exit(EXIT_FAILURE);
        }
    }

    int result[4];
    for (int i = 0; i < 4; ++i) {
        pthread_join(t[i], NULL);

        result[i] = data[i].res;
    }


    printf("Result: \n[%d, %d]\n[%d, %d]\n", result[0], result[1], result[2], result[3]);
    exit(EXIT_SUCCESS);
}

volatile char* string_text;

void* thread_ex5_1() {
    while (strcmp((const char *) string_text, "exit") != 0) {
        printf("Enter input: ");
        scanf("%s", string_text);
    }


    pthread_exit(EXIT_SUCCESS);
}

void* thread_ex5_2() {
    while (strcmp((const char *) string_text, "exit") != 0) {
        sleep(4);
        printf("%s\n", (const char *) string_text);
    }

    pthread_exit(EXIT_SUCCESS);
}


void exercice_5() {
    pthread_t t1, t2;
    string_text = malloc(100 * sizeof(char));
    if (pthread_create(&t1, NULL, thread_ex5_1, NULL) < 0) {
        fprintf(stderr, "No thread sadge\n");
        exit(EXIT_FAILURE);
    }
    if (pthread_create(&t2, NULL, thread_ex5_2, NULL) < 0) {
        fprintf(stderr, "No thread sadge\n");
        exit(EXIT_FAILURE);
    }


    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    exit(EXIT_SUCCESS);
}

volatile bool thread_complete[] = {true, true, true, true, true, true, true, true, true, true, };
void* hairdresser_p(void* num) {
    const int n = *(int*) num;

    thread_complete[n] = false;
    const int time = rand() % 15 + 15;

    printf("Hairdresser number %d starts for %d min.\n", n, time);

    sleep(time);

    printf("Hairdresser number %d has finished.\n", n);

    thread_complete[n] = true;

    pthread_exit(EXIT_SUCCESS);
}

void hairdresser() {

    pthread_t h[10];

    while (1) {
        const int time = rand() % 30;
        printf("Waiting for %d min...\n", time);
        sleep(time);
        printf("New client!!!\n");

        for (int i = 0; i < 10; ++i) {
            if(thread_complete[i]) {
                if (pthread_create(&h[i], NULL, hairdresser_p, &i) < 0) {
                    fprintf(stderr, "No thread sadge\n");
                    exit(EXIT_FAILURE);
                }
                break;
            }
        }
    }

}

void jam_factory() {

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
    } else if (strcmp(argv[1], "exercice_3") == 0) {
        exercice_3();
    } else if (strcmp(argv[1], "exercice_4") == 0) {
        exercice_4();
    } else if (strcmp(argv[1], "exercice_5") == 0) {
        exercice_5();
    } else if (strcmp(argv[1], "hairdresser") == 0) {
        hairdresser();
    } else if (strcmp(argv[1], "jam_factory") == 0) {
        jam_factory();
    }


    return 0;
}
