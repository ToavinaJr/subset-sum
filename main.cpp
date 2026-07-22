#include <print>
#include "partial_sum.hpp"

int main() {
    // Déclaration d'un tableau d'entiers brut natif
    int T[] = {3, 34, 4, 12, 5, 2};
    int taille = sizeof(T) / sizeof(T[0]);
    
    std::println("--- Tests Algorithmes de Recherche et Somme (100% NATIF) ---");
    std::println("Tableau : [3, 34, 4, 12, 5, 2]\n");

    // Nous faisons des copies locales pour les fonctions qui modifient/trient le tableau d'origine
    int T_recherche[6];
    int T_somme_2[6];
    int T_somme_3_dich[6];
    int T_somme_3_ptr[6];

    for (int i = 0; i < taille; ++i) {
        T_recherche[i] = T[i];
        T_somme_2[i] = T[i];
        T_somme_3_dich[i] = T[i];
        T_somme_3_ptr[i] = T[i];
    }

    // 1. Recherche simple d'un élément
    int x1 = 12;
    std::println("1. Presence de {} : {} (Séquentielle)", x1, recherche_simple(T, taille, x1) ? "OUI" : "NON");
    std::println("   Presence de {} : {} (Dichotomique + Quicksort)\n", x1, recherche_dichotomique(T_recherche, taille, x1) ? "OUI" : "NON");

    // 2. Somme de 2 éléments
    int x2 = 9; // 4 + 5
    std::println("2. Somme de 2 elements egale a {} : {} (Double boucle)", x2, deux_somme_naif(T, taille, x2) ? "OUI" : "NON");
    std::println("   Somme de 2 elements egale a {} : {} (Deux Pointeurs + Quicksort)\n", x2, deux_somme_pointeurs(T_somme_2, taille, x2) ? "OUI" : "NON");

    // 3. Somme de 3 éléments (Test des 3 algorithmes différents)
    int x3 = 10; // 3 + 5 + 2
    std::println("3. Somme de 3 elements egale a {} :", x3);
    std::println("   - Force Brute [O(N^3)] : {}", trois_somme_force_brute(T, taille, x3) ? "OUI" : "NON");
    std::println("   - Double boucle + Dichotomie [O(N^2 log N)] : {}", trois_somme_dichotomique(T_somme_3_dich, taille, x3) ? "OUI" : "NON");
    std::println("   - Deux Pointeurs [O(N^2)] : {}\n", trois_somme_pointeurs(T_somme_3_ptr, taille, x3) ? "OUI" : "NON");

    // 4. Somme de n éléments (Subset Sum)
    int x4 = 9;   // 4 + 5 ou 3 + 4 + 2
    int x5 = 13;  // impossible
    std::println("4. Somme de n elements egale a {} : {}", x4, somme_sous_ensemble(T, taille, x4) ? "OUI" : "NON");
    std::println("   Somme de n elements egale a {} : {}", x5, somme_sous_ensemble(T, taille, x5) ? "OUI" : "NON");

    return 0;
}