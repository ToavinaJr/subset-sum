#ifndef PARTIAL_SUM_HPP
#define PARTIAL_SUM_HPP

#include <vector>

// Tri rapide (Quicksort) fait maison pour tableau d'entiers
void tri_rapide(int T[], int bas, int haut);
void trier_tableau(int T[], int taille);

// 1. Recherche d'un élément x
bool recherche_simple(const int T[], int taille, int x);
bool recherche_dichotomique(int T[], int taille, int x); // Trie puis cherche

// 2. Somme de 2 éléments égale à x
bool deux_somme_naif(const int T[], int taille, int x);
bool deux_somme_pointeurs(int T[], int taille, int x); // Trie puis deux pointeurs

// 3. Somme de 3 éléments égale à x (3 algos différents
bool trois_somme_force_brute(const int T[], int taille, int x);
bool trois_somme_dichotomique(int T[], int taille, int x); // Double boucle + dichotomie
bool trois_somme_pointeurs(int T[], int taille, int x);   // Tri + deux pointeurs

// 4. Somme de n éléments (Subset Sum)
bool somme_sous_ensemble(const int T[], int taille, int x);

#endif // PARTIAL_SUM_HPP