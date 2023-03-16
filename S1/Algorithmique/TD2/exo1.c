#include "stdio.h"

#define sizeArr(x) (sizeof(x)/sizeof((x)[0]))

struct Etudiant
{
    char nom[255];
    char prenom[255];
    float moyenne;
};

int main(int argc, char const *argv[])
{
    int nbNotes, i, j;
    float notes, uneNote;
    struct Etudiant etudiants[20];

    for ( i = 0; i < sizeArr(etudiants); i++)
    {
        printf("Etudiant n°%i : ", i);
    }
    
    return 0;
}

