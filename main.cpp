#include <print>
#include "ArrayAnalyzer.hpp"

int main() {
    // Encapsulation des données dans une instance de classe
    ArrayAnalyzer analyzer({3, 34, 4, 12, 5, 2});

    std::println("--- Tests Algorithmes de Recherche et Somme (POO) ---\n");

    // 1. Recherche
    int x1 = 12;
    std::println("1. Presence de {} : {} (Séquentielle)", x1, analyzer.recherche_simple(x1) ? "OUI" : "NON");
    std::println("   Presence de {} : {} (Dichotomique)\n", x1, analyzer.recherche_dichotomique(x1) ? "OUI" : "NON");

    // 2. Somme de 2 éléments
    int x2 = 9;
    std::println("2. Somme de 2 elements egale a {} : {} (Naif)", x2, analyzer.deux_somme_naif(x2) ? "OUI" : "NON");
    std::println("   Somme de 2 elements egale a {} : {} (Pointeurs)\n", x2, analyzer.deux_somme_pointeurs(x2) ? "OUI" : "NON");

    // 3. Somme de 3 éléments
    int x3 = 10;
    std::println("3. Somme de 3 elements egale a {} :", x3);
    std::println("   - Force Brute : {}", analyzer.trois_somme_force_brute(x3) ? "OUI" : "NON");
    std::println("   - Dichotomie  : {}", analyzer.trois_somme_dichotomique(x3) ? "OUI" : "NON");
    std::println("   - Pointeurs   : {}\n", analyzer.trois_somme_pointeurs(x3) ? "OUI" : "NON");

    // 4. Subset Sum
    int x4 = 9, x5 = 13;
    std::println("4. Somme de n elements egale a {} : {}", x4, analyzer.somme_sous_ensemble_existe(x4) ? "OUI" : "NON");
    std::println("   Somme de n elements egale a {} : {}", x5, analyzer.somme_sous_ensemble_existe(x5) ? "OUI" : "NON");

    return 0;
}