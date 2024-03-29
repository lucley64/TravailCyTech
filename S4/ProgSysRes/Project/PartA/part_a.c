//
// Created by cytech on 26/03/24.
//

#include "part_a.h"

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <asm-generic/errno-base.h>

void* calculator(void* num) {
    const int k = *(int *) num;
    char pipe_name[50];
    sprintf(pipe_name, "PartA/pipes/thread_pipe_%d", k - 1);

    // EACCES

    while (true) {
        char buf;
        char str_start[32];
        int thread_pipefd = open(pipe_name, O_RDONLY);
        while (read(thread_pipefd, &buf, sizeof(char)) > 0) {
            sprintf(str_start, "%s%c", str_start, buf);
        }
        close(thread_pipefd);
        printf("Reading %s\n", str_start);


        char str_end[32];
        thread_pipefd = open(pipe_name, O_RDONLY);
        while (read(thread_pipefd, &buf, sizeof(char)) > 0) {
            sprintf(str_end, "%s%c", str_end, buf);
        }
        close(thread_pipefd);
        printf("Reading %s\n", str_end);

        const int start = atoi(str_start);
        const int end = atoi(str_end);

        if (start == 0 && end == 0 || end < start) {
            break;
        }

        int* primes = malloc((end - start) * sizeof(int));
        int off = 0;

        for (int i = start; i < end; ++i) {
            bool is_prime = true;
            for (int j = 2; j <= sqrt(i); ++j) {
                if ((is_prime = i % j != 0) == false) break;
            }
            if (is_prime) {
                *(primes + off++) = i;
            }
        }

        const int father_pipefd = open("PartA/pipes/father_pipe", O_WRONLY);

        write(father_pipefd, primes, off * sizeof(int));

        close(father_pipefd);
        free(primes);
    }

    pthread_exit(EXIT_SUCCESS);
}


void part_a(const int argc, const char** argv) {
    printf("Enter total range size: ");
    int n;
    scanf("%d", &n);

    printf("Enter number of subprocess: ");
    int p;
    scanf("%d", &p);

    if (p <= 0 || p > n) {
        fprintf(stderr, "Error p = %d and n = %d whitch is bnot a valid comibaison", p, n);
        exit(EXIT_FAILURE);
    }

    DIR* dir = opendir("PartA/pipes");
    if (dir) {
        closedir(dir);
    } else {
        mkdir("PartA/pipes", S_IRWXG | S_IRWXU | S_IRWXO);
    }

    // Le père crée p tubes et les fils se connectent à chacun.
    pthread_t* threads = malloc(p * sizeof(pthread_t));
    bool* free_threads = malloc(p * sizeof(bool));

    mkfifo("PartA/pipes/father_pipe", S_IRWXG | S_IRWXU | S_IRWXO);
    for (int i = 0; i < p; ++i) {
        char path[50];
        sprintf(path, "PartA/pipes/thread_pipe_%d", i);
        mkfifo(path, S_IRWXG | S_IRWXU | S_IRWXO);
        if (pthread_create(threads + i, NULL, calculator, &i) < 0) {
            fprintf(stderr, "No thread sadge\n");
            free(threads);
            exit(EXIT_FAILURE);
        }
        free_threads[i] = true;
    }

    const int range_size = 5; // n / p;
    int* primes = calloc(n, sizeof(int));
    size_t off = 0;
    //     Le père boucle sur les intervalles de recherche de taille T.
    for (int i = 0; i < n / range_size; ++i) {
        // Le père envoie les bornes de l'intervalle au fils disponible via son tube.
        const int thread_num = i % p;
        char path[50];
        sprintf(path, "PartA/pipes/thread_pipe_%d", thread_num);
        int min = i * range_size;
        int max = min + range_size - 1;
        int pipefd = open(path, O_WRONLY);
        write(pipefd, &min, sizeof(int));
        close(pipefd);
        pipefd = open(path, O_WRONLY);
        write(pipefd, &max, sizeof(int));
        close(pipefd);


        // Le fils effectue la recherche et envoie les nombres premiers trouvés et un 0 au père via le tube commun.
        int buf;
        const int father_pipefd = open("PartA/pipes/father_pipe", O_RDONLY);
        while (read(father_pipefd, &buf, sizeof(int)) > 0) {
            *(primes + off++) = buf;
        }
        close(father_pipefd);
    }

    /*
    Pour chaque intervalle:


    */


    // Le père envoie deux entiers à 0 à chaque fils pour les terminer.
    for (int i = 0; i < p; ++i) {
        char path[50];
        sprintf(path, "PartA/pipes/thread_pipe_%d", i);
        const int pipefd = open(path, O_WRONLY);

        write(pipefd, 0, sizeof(int));
        write(pipefd, 0, sizeof(int));

        close(pipefd);
    }

    // Le père attend la fin de tous les fils.
    for (int i = 0; i < p; ++i) {
        pthread_join(threads[i], NULL);
    }

    // Le père affiche les nombres premiers trouvés.
    printf("Prime numbers: ");
    for (const int* prime = primes; prime != primes + n && *prime != 0; ++prime) {
        if (prime != primes) {
            printf(", %d", *prime);
        } else {
            printf("%d", *prime);
        }
    }
    printf("\n");


    free(free_threads);
    free(primes);
    free(threads);
    exit(EXIT_SUCCESS);
}
