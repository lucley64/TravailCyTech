# Examen de Prog Parallele 2023_sessionNormale_final 

## Exercice 1: Questions de cours

1. **Différences d'exécution entre OpenMP et MPI**  
    [**OpenMP** et **MPI** sont deux modèles de programmation parallèles populaires, mais ils diffèrent dans la façon dont ils lancent et gèrent l'exécution parallèle.](https://explor.univ-lorraine.fr/explor/support/openmp-vs-mpi-notes/#:~:text=In%20summary%2C%20OpenMP%20is%20suitable,focuses%20on%20intra%2Dnode%20parallelism.)

    **OpenMP:**

    * [Est une API de directives de compilateur.](https://peakd.com/@fatieez/openmp-une-directive-pour-les-parralleliser-tous)
    * S'intègre au code source C/C++ existant.
    * Permet de paralléliser des boucles et des sections de code spécifiques.
    * **Ne nécessite pas d'exécutable spécial.**
    * Le programme est compilé avec les directives OpenMP et peut être exécuté directement avec `./monprogramme`.

    **MPI:**

    * [Est une bibliothèque de communication entre processus.](https://fr.wikipedia.org/wiki/Message_Passing_Interface)
    * Nécessite un environnement d'exécution parallèle (comme mpirun).
    * Démarre plusieurs processus distincts qui s'exécutent en parallèle.
    * [Nécessite des appels explicites à des fonctions MPI pour la communication et la synchronisation.](https://docs.alliancecan.ca/wiki/MPI/fr)
    * **Nécessite l'utilisation de mpirun pour lancer l'exécutable.**

    **Justification:**

    * **OpenMP:** Les directives OpenMP sont intégrées au code source et sont comprises par le compilateur. Le compilateur génère un code capable de s'exécuter en parallèle sur plusieurs threads. L'exécutable final ne nécessite pas d'environnement d'exécution spécial.
    * **MPI:** MPI est une bibliothèque externe qui n'est pas comprise par le compilateur. Le code source est compilé en un exécutable séquentiel standard. L'exécutable final nécessite un environnement d'exécution parallèle (comme mpirun) pour lancer et gérer les processus parallèles et la communication entre eux.

    **En résumé:**

    * **OpenMP:** Plus simple à utiliser, intégré au langage, ne nécessite pas d'exécutable spécial.
    * **MPI:** Plus flexible et puissant, permet de paralléliser des programmes plus complexes, nécessite mpirun pour l'exécution.

    **Choisir entre OpenMP et MPI:**

    Le choix entre OpenMP et MPI dépend de plusieurs facteurs:

    * La complexité du programme.
    * Le niveau de parallélisme requis.
    * La nécessité de communication et de synchronisation entre processus.

    **OpenMP** est généralement un bon choix pour les programmes parallèles simples qui peuvent être parallélisés au niveau des boucles ou des sections de code. **MPI** est plus adapté aux programmes parallèles complexes qui nécessitent une communication et une synchronisation entre processus explicites.

2. Différences entre la loi d'Amdahl et la loi de Gustafson

    **Loi d'Amdahl:**

    * Prédit l'accélération maximale possible d'un programme lorsqu'une partie séquentielle est parallélisée.
    * Se base sur une quantité de données fixe.
    * Formule: `Speedup = 1 / (f + (1-f)/p)`
        * `f` est la fraction du programme qui est séquentielle.
        * `p` est le nombre de processeurs.

    **Loi de Gustafson:**

    * Prédit l'accélération maximale possible d'un programme lorsqu'une partie séquentielle est parallélisée et que la quantité de données est augmentée proportionnellement au nombre de processeurs.
    * Ne se limite pas à une quantité de données fixe.
    * Formule: `Speedup = p / (1 + (1-f) * (p-1))`
        * `f` est la fraction du programme qui est séquentielle.
        * `p` est le nombre de processeurs.

    **Différences principales:**

    * **Quantité de données:** La loi d'Amdahl suppose une quantité de données fixe, tandis que la loi de Gustafson permet d'augmenter la quantité de données avec le nombre de processeurs.
    * **Forme de la courbe d'accélération:** La loi d'Amdahl prédit une courbe d'accélération hyperbolique, tandis que la loi de Gustafson prédit une courbe d'accélération linéaire.
    * **Cas d'utilisation:** La loi d'Amdahl est plus utile pour estimer l'accélération dans des situations où la quantité de données est limitée, tandis que la loi de Gustafson est plus utile pour estimer l'accélération dans des situations où la quantité de données peut être augmentée.

    **Exemple:**

    Supposons qu'un programme a une fraction séquentielle de `f = 0.2` et qu'il est exécuté sur 4 processeurs.

    * **Loi d'Amdahl:** `Speedup = 1 / (0.2 + (1-0.2)/4) = 2.86`
    * **Loi de Gustafson:** `Speedup = 4 / (1 + (1-0.2) * (4-1)) = 3.6`

    On voit que la loi de Gustafson prédit une accélération plus importante que la loi d'Amdahl. Cela est dû au fait que la loi de Gustafson prend en compte l'augmentation de la quantité de données avec le nombre de processeurs.

    **Conclusion:**

    La loi d'Amdahl et la loi de Gustafson sont deux outils importants pour estimer l'accélération d'un programme parallélisé. Le choix de la loi à utiliser dépend de la situation et des besoins spécifiques.

3. Différences entre MPI_Reduce() et MPI_Scatter()

    **MPI_Reduce()** et **MPI_Scatter()** sont deux fonctions de communication collective dans la bibliothèque MPI. Elles permettent d'effectuer des opérations sur des données réparties entre les processus d'un communicateur MPI.

    **MPI_Reduce():**

    * **Fonction:** Combine les valeurs de données de tous les processus en une seule valeur sur un processus désigné (la "racine").
    * **Opérations:** Offre un large choix d'opérations de réduction, telles que la somme, le maximum, le minimum, etc.
    * **Exemple:** Additionner les valeurs d'un tableau sur tous les processus et stocker le résultat sur la racine.

    **MPI_Scatter():**

    * **Fonction:** Distribue une portion d'un tableau de données depuis un processus (la "racine") vers tous les processus.
    * **Distribution:** Divise le tableau en blocs de taille égale et envoie un bloc à chaque processus.
    * **Exemple:** Distribuer un tableau d'entiers à tous les processus pour traitement parallèle.

    **Différences principales:**

    * **Direction du flux de données:** MPI_Reduce() combine les données vers la racine, tandis que MPI_Scatter() distribue les données depuis la racine.
    * **Opérations:** MPI_Reduce() offre des opérations de réduction prédéfinies, tandis que MPI_Scatter() ne permet que la distribution de données.
    * **Utilisation:** MPI_Reduce() est utilisé pour combiner des résultats après un traitement parallèle, tandis que MPI_Scatter() est utilisé pour distribuer des données avant un traitement parallèle.

    **Exemple d'utilisation:**

    Supposons que nous avons un tableau d'entiers et que nous voulons calculer la somme totale. Nous pouvons utiliser MPI_Reduce() comme ceci:

    ```c
    int sum = 0;
    MPI_Reduce(&my_value, &sum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
    ```

    Si nous voulons ensuite distribuer le tableau à tous les processus pour un traitement parallèle, nous pouvons utiliser MPI_Scatter() comme ceci:

    ```c
    MPI_Scatter(data, data_size, MPI_INT, &my_data, data_size, MPI_INT, 0, MPI_COMM_WORLD);
    ```

    **Conclusion:**

    MPI_Reduce() et MPI_Scatter() sont deux fonctions importantes pour la communication et la synchronisation dans les programmes MPI. Comprendre leurs différences est essentiel pour les utiliser efficacement.

4. 2 Stratégies de communication inter-processus dans MPI:

    1. **Communication point-à-point:**

        * Permet à deux processus spécifiques de communiquer directement entre eux.
        * Nécessite de connaître l'identifiant (rank) du processus avec lequel on souhaite communiquer.
        * Offre deux types de communication:
            * **Envoi/réception bloquante:** Les processus attendent que l'opération de communication soit terminée avant de continuer.
            * **Envoi/réception non bloquante:** Les processus peuvent continuer leur exécution après avoir lancé l'opération de communication.
        * **Fonctions MPI:** `MPI_Send()`, `MPI_Recv()`, `MPI_Isend()`, `MPI_Irecv()`.

    2. **Communication collective:**

        * Permet à tous les processus d'un communicateur de participer à une opération de communication simultanément.
        * Offre plusieurs types d'opérations, telles que:
            * **Diffusion (MPI_Bcast):** Un processus envoie une valeur à tous les autres processus.
            * **Réduction (MPI_Reduce):** Combine les valeurs de tous les processus en une seule valeur sur un processus désigné.
            * **Scatter/Gather (MPI_Scatter/MPI_Gather):** Distribue/rassemble des données entre tous les processus.
        * **Fonctions MPI:** `MPI_Bcast()`, `MPI_Reduce()`, `MPI_Scatter()`, `MPI_Gather()`, `MPI_Allreduce()`.

    3. **Définitions:**

        **Communication point-à-point:** Échange de messages entre deux processus spécifiques.

        **Communication collective:** Opération de communication impliquant tous les processus d'un communicateur.

## Exercice 2: Évaluation de la performance

1. Réponses aux questions:

    **a. Fraction parallélisable:**

    Pour calculer la fraction parallélisable de la tâche, on utilise la formule suivante:

    `Fp = 1 - (Temps d'exécution sur le système multi-core / Temps d'exécution sur le système uni-core)`

    Fp = 1 - (80 secondes / 120 secondes) = 1 - 0.6667 = 0.3333

    **b. Speedup général:**

    Le speedup général est le rapport du temps d'exécution sur le système uni-core au temps d'exécution sur le système multi-core:

    `Speedup = Temps d'exécution sur le système uni-core / Temps d'exécution sur le système multi-core`

    Speedup = 120 secondes / 80 secondes = 1.5

    **c. Ratio du speedup par rapport au speedup idéal:**

    Le speedup idéal est le temps d'exécution sur le système uni-core divisé par le nombre de cores:

    `Speedup idéal = Temps d'exécution sur le système uni-core / Nombre de cores`

    Speedup idéal = 120 secondes / 8 cores = 15 secondes

    Le ratio du speedup par rapport au speedup idéal est:

    `Ratio = Speedup / Speedup idéal`

    Ratio = 1.5 / 15 = 0.1

    **Conclusion:**

    * La fraction parallélisable de la tâche est de 33.33%.
    * Le speedup général du système est de 1.5.
    * Le ratio du speedup par rapport au speedup idéal est de 0.1.

    **Interprétation des résultats:**

    * La tâche est partiellement parallélisable, ce qui signifie qu'une partie de la tâche ne peut pas être parallélisée.
    * Le speedup obtenu est inférieur au speedup idéal, ce qui est dû à la présence de sérialisations dans la tâche et à des limitations du système multi-core (comme la latence de communication entre les cores).

    **Améliorations possibles:**

    * Optimiser le code pour réduire les sérialisations.
    * Utiliser des techniques de parallélisation plus avancées.
    * Choisir un système multi-core avec une meilleure architecture et une latence de communication plus faible.

2. Calculs pour les deux programmes:

    **a. Nombre de cycles:**

    * **Programme 1:**
        * Cycles Type 1 = 2 instructions * 1 CPI = 2 cycles
        * Cycles Type 2 = 1 instruction * 2 CPI = 2 cycles
        * Cycles Type 3 = 2 instructions * 3 CPI = 6 cycles
        * Total cycles = 2 + 2 + 6 = 10 cycles
    * **Programme 2:**
        * Cycles Type 1 = 4 instructions * 1 CPI = 4 cycles
        * Cycles Type 2 = 1 instruction * 2 CPI = 2 cycles
        * Cycles Type 3 = 1 instruction * 3 CPI = 3 cycles
        * Total cycles = 4 + 2 + 3 = 9 cycles

    **b. CPI:**

    * **Programme 1:**
        * CPI = Total cycles / Total instructions
        * CPI = 10 cycles / (2 + 1 + 2) instructions
        * CPI = 10 cycles / 5 instructions
        * CPI = 2 cycles/instruction
    * **Programme 2:**
        * CPI = Total cycles / Total instructions
        * CPI = 9 cycles / (4 + 1 + 1) instructions
        * CPI = 9 cycles / 6 instructions
        * CPI = 1.5 cycles/instruction

    **c. Performance:**

    * Le **programme 2** est plus performant que le programme 1 car il a un CPI plus bas (1.5 contre 2).
    * Le CPI est une mesure du nombre de cycles d'horloge nécessaires pour exécuter une instruction. Un CPI plus bas signifie que le programme est plus efficace et s'exécute plus rapidement.

    **Justification:**

    Le programme 2 a un nombre d'instructions plus élevé que le programme 1, mais il a un CPI plus bas. Cela signifie que le programme 2 est plus efficace pour exécuter ses instructions.

    **En résumé:**

    * Programme 1: 10 cycles, CPI = 2
    * Programme 2: 9 cycles, CPI = 1.5

    **Le programme 2 est donc le plus performant.**

## Exercice 3: OpenMP

1. Parallélisation du code OpenMP pour le problème à N corps:

    1. **Étape 1: Détecter les dépendances de données:**

        * La boucle `for` itère sur les particules `i` de 1 à N-1.
        * A chaque itération, la fonction `calculate_force` est appelée avec les positions de deux particules `i` et `j`.
        * Le résultat de la fonction `calculate_force` est utilisé pour mettre à jour les forces `f[x1[i]]` et `f[x2[i]]`.

        **Il existe deux types de dépendances de données dans ce code:**

        * **Dépendances de lecture:** La valeur de `f[x1[i]]` et `f[x2[i]]` est lue avant d'être mise à jour.
        * **Dépendances d'écriture:** La valeur de `f[x1[i]]` et `f[x2[i]]` est écrasée à chaque itération.

    2. **Étape 2: Paralléliser le code:**

        **Deux approches sont possibles pour paralléliser ce code:**

        1. **Parallélisation par boucles:**

            * Utiliser la directive `#pragma omp parallel for` pour paralléliser la boucle `for`.
            * Chaque thread calculera la force pour un ensemble de particules distinctes.
            * **Attention:** Il faut s'assurer que les accès aux tableaux `f`, `x1` et `x2` sont synchronisés pour éviter des écritures concurrentes.

        2. **Parallélisation par réduction:**

            * Utiliser la directive `#pragma omp parallel for reduction(+:f[:N])` pour paralléliser la boucle `for`.
            * Chaque thread calculera la force pour un ensemble de particules distinctes et accumulera le résultat dans une variable locale.
            * A la fin de la boucle, les résultats locaux seront réduits en une seule variable `f` en utilisant l'opérateur `+`.

    **Justification des choix:**

    * La parallélisation par boucles est plus simple à implémenter.
    * La parallélisation par réduction est plus efficace car elle évite les écritures concurrentes dans le tableau `f`.

    **Code OpenMP parallélisé (par réduction):**

    ```c
    #include <omp.h>

    void calculate_force(double x1, double x2, double *force);

    int main() {
        int N;
        double *x1, *x2, *f;

        // Initialisation des tableaux

        #pragma omp parallel for
        for (int i = 0; i < N; i++) {
            f[i] = 0.0;
        }

        #pragma omp parallel for reduction(+:f[:N])
        for (int i = 1; i < N; i++) {
            double force;
            calculate_force(x1[i], x2[i], &force);
            #pragma omp atomic
            f[x1[i]] += force;
            #pragma omp atomic
            f[x2[i]] -= force;
        }

        // Calcul des trajectoires

        return 0;
    }
    ```

    **Remarques:**

    * Le code ci-dessus est une simplification et peut être optimisé davantage.
    * Il est important de choisir la bonne stratégie de parallélisation en fonction du problème et de l'architecture du système.

    **Conclusion:**

    Le code OpenMP parallélisé permet de calculer la force nette sur chaque particule en parallèle, ce qui peut améliorer significativement les performances pour un grand nombre de particules.

2. Suite

    1. Explication du résultat final avec la directive "reduction":

        1. **Fonctionnement de la directive "reduction":**

            * La directive `#pragma omp parallel for reduction(+:sum)` permet de paralléliser la boucle `for` et de réduire la variable `sum` en une seule valeur finale.
            * Chaque thread calcule la somme d'une partie du tableau `array`.
            * A la fin de la boucle, les sommes locales sont additionnées pour obtenir la somme finale de `sum`.

        2. **Obtention du résultat final:**

            * La variable `sum` est initialisée à 0 avant la boucle `for`.
            * A chaque itération de la boucle, chaque thread ajoute la valeur de l'élément courant du tableau `array` à la variable `sum` locale.
            * La directive `reduction(+:sum)` combine les valeurs locales de `sum` en une seule valeur finale stockée dans la variable `sum` globale.
            * La valeur finale de `sum` est ensuite affichée par la fonction `printf`.

    2. **Modification du programme avec "omp parallel sections":**

        ```c
        #include <stdio.h>
        #include <stdlib.h>
        #include <omp.h>
        #define ARRAY_SIZE 100

        int main() {
        int i, sum = 0;
        int array[ARRAY_SIZE];

        // Initialisation du tableau
        for (i = 0; i < ARRAY_SIZE; i++) {
            array[i] = i;
        }

        #pragma omp parallel sections
        {
            #pragma omp section
            {
            int local_sum = 0;
            for (i = 0; i < ARRAY_SIZE / 2; i++) {
                local_sum += array[i];
            }
            #pragma omp critical
            sum += local_sum;
            }

            #pragma omp section
            {
            int local_sum = 0;
            for (i = ARRAY_SIZE / 2; i < ARRAY_SIZE; i++) {
                local_sum += array[i];
            }
            #pragma omp critical
            sum += local_sum;
            }
        }

        printf("La somme du tableau est : %d\n", sum);
        return 0;
        }
       ```

    **Explication des modifications:**

    * La directive `#pragma omp parallel sections` divise la région de code en deux sections parallèles.
    * Chaque section calcule la somme d'une moitié du tableau `array`.
    * La directive `#pragma omp critical` est utilisée pour garantir un accès mutuel exclusif à la variable `sum` lors de l'addition des sommes locales.

    **Résultat:**

    Le programme affiche la même somme finale que le programme original.

    **Remarques:**

    * Cette solution utilise la directive `omp critical` pour garantir la cohérence des données.
    * D'autres solutions sont possibles, par exemple en utilisant des variables locales et une réduction finale en dehors de la section parallèle.
    * Le choix de la meilleure solution dépend du contexte et des performances.

## Exercice 4: MPI

1. Implémentation MPI du tri pair-impair

    **Algorithme:**

    1. **Distribution:** Distribuer le tableau d'entiers de taille `n` sur `P` processus, chaque processus recevant une portion de taille `n/p`.
    2. **Tri local:** Chaque processus trie sa portion de tableau localement en utilisant un algorithme de tri séquentiel (par exemple, tri à bulles, tri par insertion).
    3. **Fusion:**
        * **Étapes paires:**
            * Les processus pairs envoient leurs `n/p` plus petits éléments à leurs processus de droite.
            * Les processus pairs reçoivent les `n/p` plus grands éléments de leurs processus de gauche.
            * Chaque processus fusionne les deux tableaux reçus en un seul tableau trié de taille `n/p`.
        * **Étapes impaires:**
            * Les processus pairs envoient leurs `n/p` plus grands éléments à leurs processus de gauche.
            * Les processus pairs reçoivent les `n/p` plus petits éléments de leurs processus de droite.
            * Chaque processus fusionne les deux tableaux reçus en un seul tableau trié de taille `n/p`.
    4. **Répéter les étapes 3 et 4** jusqu'à ce que chaque processus possède un seul élément (i.e., `log2(P)` étapes).
    5. **Collecte:** Le processus de rang 0 rassemble les éléments triés de tous les processus pour obtenir le tableau final trié.

    **Code MPI:**

    ```c
    #include <stdio.h>
    #include <stdlib.h>
    #include <mpi.h>

    #define TAG_SEND 1
    #define TAG_RECV 2

    void merge(int *data1, int size1, int *data2, int size2, int *data_out) {
        int i = 0, j = 0, k = 0;

        while (i < size1 && j < size2) {
            if (data1[i] < data2[j]) {
            data_out[k++] = data1[i++];
            } else {
            data_out[k++] = data2[j++];
            }
        }

        while (i < size1) {
            data_out[k++] = data1[i++];
        }

        while (j < size2) {
            data_out[k++] = data2[j++];
        }
    }

    int main(int argc, char **argv) {
        int my_rank, comm_size;
        int *data, *local_data, *recv_data;
        int i, step, size, send_size, recv_size;

        MPI_Init(&argc, &argv);
        MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
        MPI_Comm_size(MPI_COMM_WORLD, &comm_size);

        // Initialisation des données
        if (my_rank == 0) {
            data = (int *)malloc(sizeof(int) * n);
            for (i = 0; i < n; i++) {
            data[i] = rand() % 100;
            }
        }

        // Distribution du tableau
        local_data = (int *)malloc(sizeof(int) * n / comm_size);
        MPI_Scatter(data, n / comm_size, MPI_INT, local_data, n / comm_size, MPI_INT, 0, MPI_COMM_WORLD);

        // Tri local
        qsort(local_data, n / comm_size, sizeof(int), compare);

        for (step = 0; step < log2(comm_size); step++) {
            if (step % 2 == 0) {
            // Envoyer les plus petits éléments aux processus de droite
            send_size = n / comm_size / 2;
            recv_size = n / comm_size / 2;
            if (my_rank % 2 == 0) {
                MPI_Send(local_data, send_size, MPI_INT, my_rank + 1, TAG_SEND, MPI_COMM_WORLD);
                MPI_Recv(recv_data, recv_size, MPI_INT, my_rank + 1, TAG_RECV, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            } else {
                MPI_Recv(recv_data, recv_size, MPI_INT, my_rank - 1, TAG_SEND, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                MPI_Send(local_data + send_size, send_size, MPI_INT, my_rank - 1, TAG_RECV, MPI_COMM_WORLD);
            }

            // Fusionner les deux tableaux reçus
            merge(local_data, send_size, recv_data, recv_size, local_data);
            } else {
            // Envoyer les plus grands éléments aux processus de gauche
            send_size = n / comm_size / 2;
            recv_size = n / comm_size / 2;
            if (my_rank % 2 == 0) {
                MPI_Send(local_data + send_size, send_size, MPI_INT, my_rank - 1, TAG_SEND, MPI_COMM_WORLD);
                MPI_Recv(recv_data, recv_size, MPI_INT, my_rank - 1, TAG_RECV, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            } else {
                MPI_Recv(recv_data, recv_size, MPI_INT, my_rank + 1, TAG_SEND, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                MPI_Send(local_data, send_size, MPI_INT, my_rank + 1, TAG_RECV, MPI_COMM_WORLD);
            }
            // Fusionner les deux tableaux reçus
            merge(local_data + send_size, send_size, recv_data, recv_size, local_data + send_size);
            }
        }

        // Collecte des résultats
        if (my_rank == 0) {
            data = (int *)malloc(sizeof(int) * n);
        }
        MPI_Gather(local_data, n / comm_size, MPI_INT, data, n / comm_size, MPI_INT, 0, MPI_COMM_WORLD);

        // Affichage du tableau trié sur le processus 0
        if (my_rank == 0) {
            printf("Tableau trié:\n");
            for (i = 0; i < n; i++) {
            printf("%d ", data[i]);
            }
            printf("\n");
            free(data);
        }

        free(local_data);
        MPI_Finalize();
        return 0;
    }
    ```

    **Remarques:**

    * Ce code est une implémentation de base du tri pair-impair en MPI.
    * Il existe des optimisations possibles pour améliorer les performances, comme l'utilisation d'une communication non bloquante.
    * Le choix de l'algorithme de tri local peut également influencer les performances.

    **Points importants:**

    * Le tri pair-impair est un algorithme de tri parallèle efficace pour les architectures à mémoire distribuée.
    * L'implémentation en MPI nécessite de gérer la communication entre les processus pour échanger les données et fusionner les tableaux triés.
    * Le code MPI doit être optimisé pour prendre en compte les caractéristiques de l'architecture et du réseau.

    **Ressources supplémentaires:**

    * Tutoriel MPI: [URL non valide supprimée]
    * Tri pair-impair: [https://fr.wikipedia.org/wiki/Tri_pair-impair](https://fr.wikipedia.org/wiki/Tri_pair-impair)
