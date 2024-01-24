#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>


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

int main(const int argc, const char** argv) {
    processus_3();
    return 0;
}


