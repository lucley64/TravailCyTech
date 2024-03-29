#include <list>
#include <map>
#include <algorithm>
#include <iostream>
#include <map>
#include <random>


using std::string, std::map, std::list, std::cout, std::endl, std::vector;


// Fonction pour afficher les éléments d'une liste
void afficherListe(const list<int>& l) {
    for (const auto& element: l) {
        cout << element << " ";
    }
    cout << endl;
}

// Fonction pour afficher les éléments d'une map
void afficherMap(const map<string, string>& m) {
    for (const auto& [fst, snd]: m) {
        cout << fst << " : " << snd << endl;
    }
}

// Fonction pour afficher les éléments d'un vecteur
void afficherVecteur(const vector<int>& v) {
    for (const auto& element: v) {
        cout << element << " ";
    }
    cout << endl;
}

int main() {
    // ### Conteneur séquentiel list

    // Déclaration d'une liste
    list liste = {0, 3, 1, 4, 2};

    // Affichage de la liste
    cout << "list : " << endl;
    afficherListe(liste);

    // Tri de la liste
    liste.sort();

    // Affichage de la liste triée
    cout << "0 1 2 3 4 (list.sort) " << endl;
    afficherListe(liste);

    // Inversion de la liste
    liste.reverse();

    // Affichage de la liste inversée
    cout << "4 3 2 1 0 (list.reverse) " << endl;

    // Accès aux premier et dernier éléments
    cout << liste.front() << " " << liste.back() << endl;

    // ### Conteneur associatif map

    // Déclaration d'une map
    const map<string, string> mapPrenomsNum = {
        {"Jean Martin", "01.02.03.04.05"},
        {"Francois Martin", "02.03.04.05.06"},
        {"Louis Martin", "04.05.06.07.08"},
        {"Louis Dupont", "03.04.05.06.07"},
    };


    // Affichage de la map
    cout << "map : " << endl;
    afficherMap(mapPrenomsNum);

    // ### Iterator, auto, Algorithmes

    // Déclaration d'un vecteur
    vector vec = {32, 71, 12, 45, 26, 80, 53, 33};

    // Affichage du vecteur
    cout << endl;
    afficherVecteur(vec);

    // Mélange aléatoire du vecteur
    shuffle(vec.begin(), vec.end(), std::mt19937(std::random_device()()));

    // Affichage du vecteur mélangé
    cout << "26 71 53 12 32 80 33 45 (random_shuffle)" << endl;
    afficherVecteur(vec);

    // ### Foncteur (fonction objet)

    // Déclaration d'un foncteur pour comparer des entiers
    struct ComparateurEntiers {
        bool operator()(const int a, const int b) const { return a < b; }
    };

    // Tri du vecteur avec le foncteur
    sort(vec.begin(), vec.end(), ComparateurEntiers());

    // Affichage du vecteur trié
    cout << endl;
    afficherVecteur(vec);

    // ### Lambda-expression & for-each

    // Itération sur le vecteur et multiplication par 2
    for_each(vec.begin(), vec.end(), [](int& element) { element *= 2; });

    // Affichage du vecteur après multiplication
    cout << endl;
    afficherVecteur(vec);

    return 0;
}
