#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>


void print_all(const pid_t child_pid) {
    const pid_t pid = getpid();
    const pid_t ppid = getppid();
    const uid_t uid = getuid();
    const uid_t euid = geteuid();
    const gid_t gid = getgid();
    const gid_t egid = getegid();

    printf("Je suis le processus de pid : %d \n"
           "Mon père est le processus de pid : %d \n"
           "Mon uid : %d \nMon euid : %d \n"
           "Mon gid : %d \nMon egid : %d \n", pid, ppid, uid, euid, gid, egid);
    if (child_pid) {
        printf("Mon fils est le processus de pid : %d.", child_pid);
    }
    printf("\n\n");
}

int compte_arg(const int argC, char** argv) {
    int sum = 0;
    for (int i = 1; i < argC; ++i) {
        const int n = atoi(argv[i]);

        sum += n;
    }

    return sum;
}

void cp(const char* filenamein, const char* filenameout) {
    const int filein = open(filenamein, O_RDONLY);
    if (filein == -1) {
        printf("Error file %s cannot be accessed.\n", filenamein);
        return;
    }
    const int fileout = creat(filenameout, S_IRUSR | S_IWUSR);
    if (fileout == -1) {
        printf("Error file %s cannot be accessed.\n", filenameout);
        return;
    }
    char buffer = 0;
    while (read(filein, &buffer, 1) > 0) {
        write(fileout, &buffer, 1);
    }
    close(filein);
    close(fileout);
}

void cp_reverse(const char* filenamein, const char* filenameout) {
    const int filein = open(filenamein, O_RDONLY);
    if (filein == -1) {
        printf("Error file %s cannot be accessed.\n", filenamein);
        return;
    }
    const int fileout = creat(filenameout, S_IRUSR | S_IWUSR);
    if (fileout == -1) {
        printf("Error file %s cannot be accessed.\n", filenameout);
        return;
    }
    char buffer = 0;
    int offset = -1;
    while (lseek(filein, offset, SEEK_END) > -1) {
        read(filein, &buffer, 1);
        write(fileout, &buffer, 1);
        offset--;
    }
}

void processus_1() {
    const pid_t pid = getpid();
    const pid_t ppid = getppid();
    const uid_t uid = getuid();
    const uid_t euid = geteuid();
    const gid_t gid = getgid();
    const gid_t egid = getegid();

    printf("Je suis le processus de pid : %d \n"
           "Mon père est le processus de pid : %d \n"
           "Mon uid : %d \nMon euid : %d \n"
           "Mon gid : %d \nMon egid : %d \n\n", pid, ppid, uid, euid, gid, egid);
}

void processus_2() {
    const pid_t fork_pid = fork();
    const char* name = fork_pid == 0 ? "fils" : "père";
    const pid_t pid = getpid();
    const pid_t ppid = getppid();
    printf("Valeur de fork = %d \n"
           "Je suis le processus %s : pid = %d, ppid = %d\n", fork_pid, name, pid, ppid);
}

void processus_3() {
    const pid_t fork_pid = fork();
    printf("Valeur de fork = %d \n", fork_pid);
    processus_1();
}

void exercice_7() {
    int x = 2;
    printf("x = %d\n", x);
    const pid_t pid = fork();
    switch (pid) {
        case 0:
            printf("Le fils est pid = %d et mon ppid = %d. \n", getpid(), getppid());
            processus_1();
            x += 3;
            printf("x = %d\n", x);
            break;
        case -1:
            fprintf(stderr, "Erreur fork. \n");
            break;;
        default:
            printf("Le père est pid = %d et mon ppid = %d. \n", getpid(), getppid());
            processus_1();
            x *= 5;
            printf("x = %d\n", x);
            break;
    }
    printf("Fin proccessus %d. \n", getpid());
}

void exercice_8_a() {
    const pid_t pid = fork();

    if (pid != 0) {
        if (pid == -1) {
            fprintf(stderr, "Erreur fork. \n");
            return;
        }
        print_all(pid);
        int wstatus;
        wait(&wstatus);
    }
}

void exercice_8_b() {
    const pid_t pid = fork();

    if (pid != 0) {
        if (pid == -1) {
            fprintf(stderr, "Erreur fork. \n");
            return;
        }
        print_all(pid);
        int wstatus;
        waitpid(pid, &wstatus, 0);
        if (WIFEXITED(wstatus)) {
            printf("Le fils à bien terminer avec le code %d", WEXITSTATUS(wstatus));
        }
    }
}

void exercice_9(const int argc, const char** argv) {
    if (argc < 2) {
        fprintf(stderr, "Entrer le nombre d'itération");
        return;
    }
    const int n = atoi(argv[1]);
    for (int i = 0; i < n; i++) {
        const pid_t pid = fork();
        print_all(pid);
    }
}

/**
 * \brief matrix is [[x1, y1], [x2, y2]]
 */
int** exercice_10(const int x1, const int y1, const int x2, const int y2) {
    int calc;
    const pid_t pork1 = fork();
    if (pork1 == 0) {
        calc = x1 * x1 + y1 * x2;
        exit(calc);
    }
    const pid_t pork2 = fork();
    if (pork2 == 0) {
        calc = x1 * y1 + y1 * y2;
        exit(calc);
    }
    const pid_t pork3 = fork();
    if (pork3 == 0) {
        calc = x1 * x2 + x2 * y2;
        exit(calc);
    }
    const pid_t pork4 = fork();
    if (pork4 == 0) {
        calc = x2 * y1 + y2 * y2;
        exit(calc);
    }
    int wstatus[4];
    waitpid(pork1, &wstatus[0], 0);
    waitpid(pork2, &wstatus[1], 0);
    waitpid(pork3, &wstatus[2], 0);
    waitpid(pork4, &wstatus[3], 0);
    int** matrix = malloc(2 * sizeof(int *));
    matrix[0] = (int *) malloc(2 * sizeof(int));
    matrix[1] = (int *) malloc(2 * sizeof(int));

    if (WIFEXITED(wstatus[0]) && WIFEXITED(wstatus[1]) && WIFEXITED(wstatus[2]) && WIFEXITED(wstatus[3])) {
        matrix[0][0] = WEXITSTATUS(wstatus[0]);
        matrix[0][1] = WEXITSTATUS(wstatus[1]);
        matrix[1][0] = WEXITSTATUS(wstatus[2]);
        matrix[1][1] = WEXITSTATUS(wstatus[3]);
    }
    return matrix;
}

void exercice_11() {
    const pid_t res = fork();
    pid_t pid;
    int status;
    switch (res) {
        case -1:
            fprintf(stderr, "Erreur fork.");
            break;
        case 0:
            printf("processus fils %d execute ls\n", getpid());
            execlp("ls", "ls", "-al", NULL);
            fprintf(stderr, "Ce message n'apparait pas si tout va bien ");
            fprintf(stderr, "car le code est changé\n");
            exit(10);
        default:
            pid = wait(&status); // Le père attend le fils. Wait retourne le pid du fils
            printf("processus père %d\n", getpid());
            printf("PID = %d, status = %d\n", pid, status);
            break;
    }
}

void exercice_12_calc(const int argc, const char** argv) {
    if (argc != 3) {
        fprintf(stderr, "usage: %s <operande_1> <operande_2>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    const int somme = atoi(argv[1]) + atoi(argv[2]);
    printf("%s + %s = %d\n", argv[1], argv[2], somme);
}

void exercice_12_recouv(const int argc, char** const argv) {
    if (argc < 2) {
        fprintf(stderr, "usage: %s <nom_du_programme> [args]\n", argv[0]);
        exit(10);
    }
    switch (fork()) {
        case -1:
            printf("fork impossible...\n");
            exit(5);
        case 0:
            execvp(argv[1], argv + 1);
            printf("Recouvrement du code de %s impossible...", argv[1]);
            exit(15);
        default:
            wait(NULL);
    }
}

void exercice_13_nouveau(const int argc, const char** argv) {
    if (argc != 2) {
        printf("usage: %s <nb_se_secondes>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    const int temps = atoi(argv[1]);
    printf("Nouveau code du fils\n");
    printf("Duree du sommeil : %d\n", temps);
    sleep(temps);
    printf("Réveil et fin du fils après %d secondes \n", temps);
}

size_t count_delim(const char* input, const char tok) {
    const char* tmp = input;
    size_t count = 0;
    while (*tmp != '\0') {
        if (*tmp == tok) {
            count++;
        }
        tmp++;
    }
    return count;
}

char* rem_trail_nl(char* input) {
    char* tmp = input;
    while (*tmp != '\0') {
        if (*tmp == '\n') {
            *tmp = '\0';
        }
        tmp++;
    }
}

void exercice_14(const int argc, char** const argv) {
    printf("Starting my shell\n");
    const char check[255] = "exit";
    char input[255] = "";
    while (strcmp(input, check) != 0) {
        printf("my_shell$ ");
        fgets(input, 255, stdin);
        if (strcmp(input, check) != 0) {
            rem_trail_nl(input);
            char** args = malloc(sizeof(char *) * count_delim(input, ' ') + 1);
            size_t offs = 0;
            const char* token = strtok(input, " ");
            while (token) {
                *(args + offs++) = strdup(token);
                token = strtok(0, " ");
            }
            *(args + offs) = 0;
            switch (fork()) {
                case -1:
                    fprintf(stderr, "fork impossible...\n");
                    exit(5);
                case 0:
                    execvp(args[0], args);
                    exit(EXIT_FAILURE);
                default:
                    wait(NULL);
                    break;
            }
            free(args);
        }
    }
}

void exercice_15() {
    int toto = open("toto", O_APPEND | O_CREAT, S_IRWXU | S_IRWXG | S_IRWXO);
    char buf[32];
    const pid_t pork = fork();
    switch (pork) {
        case -1:
            fprintf(stderr, "Erreur pork.");
            exit(EXIT_FAILURE);
        case 0:
            write(toto, "ab", sizeof(char) * 2);
            sleep(5);
            read(toto, buf, 2);
            printf("fils lit : %s\n", buf);
            break;
        default:
            sleep(1);
            read(toto, buf, 2);
            printf("père lit : %s\n", buf);
            write(toto, "AB", sizeof(char) * 2);
            break;
    }
}

int main(const int argc, char** const argv) {
    // int** ret_mat = exercice_10(1, 1, 3, 2);
    //
    // printf("%d %d \n%d %d\n", ret_mat[0][0], ret_mat[0][1], ret_mat[1][0], ret_mat[1][1]);
    //
    //
    // free(ret_mat[0]);
    // free(ret_mat[1]);
    // free(ret_mat);

    exercice_15();

    exit(EXIT_SUCCESS);
}
