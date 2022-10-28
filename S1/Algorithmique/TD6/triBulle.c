#include <stdio.h>

int main(int argc, char const *argv[])
{
    int tab[] = {5, 0, 24, 33, 23, 21, 58, 22, 8, 9};

    for (int *i = &tab; i < &tab[sizeof(tab) / sizeof(int)]; i++)
    {
        printf("%i, ", *i);
    }

    triBulle(tab);

    return 0;
}

int size(int *tab)
{
    return sizeof(tab) / sizeof(int);
}

void triBulle(int *tab)
{
    for (int i = 0; i < size(tab); i++)
    {
        for (int j = 0; j < size(tab) - i; j++)
        {
            if (tab[j] > tab[j + 1])
            {
                int temp = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = temp;
            }
        }
    }
}