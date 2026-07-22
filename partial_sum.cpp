#include "partial_sum.hpp"
#include <iostream>
#include <vector>

// ==========================================
// OUTIL DE TRI MAISON (Quicksort sur int[])
// ==========================================

void echanger(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int partitionner(int T[], int bas, int haut) {
    int pivot = T[haut];
    int i = bas - 1;
    for (int j = bas; j < haut; j++) {
        if (T[j] < pivot) {
            i++;
            echanger(T[i], T[j]);
        }
    }
    echanger(T[i + 1], T[haut]);
    return i + 1;
}

void tri_rapide(int T[], int bas, int haut) {
    if (bas < haut) {
        int pi = partitionner(T, bas, haut);
        tri_rapide(T, bas, pi - 1);
        tri_rapide(T, pi + 1, haut);
    }
}

void trier_tableau(int T[], int taille) {
    if (taille > 1) {
        tri_rapide(T, 0, taille - 1);
    }
}

// ==========================================
// 1. RECHERCHE D'UN ÉLÉMENT X
// ==========================================

bool recherche_simple(const int T[], int taille, int x) {
    for (int i = 0; i < taille; ++i) {
        if (T[i] == x) return true;
    }
    return false;
}

bool recherche_dichotomique(int T[], int taille, int x) {
    trier_tableau(T, taille);
    int gauche = 0;
    int droite = taille - 1;
    while (gauche <= droite) {
        int milieu = (droite + gauche) / 2;
        if (T[milieu] == x) {
            return true;
        } else if (T[milieu] < x) {
            gauche = milieu + 1;
        } else {
            droite = milieu - 1;
        }
    }
    return false;
}

// ==========================================
// 2. SOMME DE 2 ÉLÉMENTS ÉGALE À X
// ==========================================

// Algo 1 : Double boucle - O(N^2)
bool deux_somme_naif(const int T[], int taille, int x) {
    for (int i = 0; i < taille - 1; ++i) {
        for (int j = i + 1; j < taille; ++j) {
            if (T[i] + T[j] == x) return true;
        }
    }
    return false;
}

// Algo 2 : Tri + Deux Pointeurs - O(N log N)
bool deux_somme_pointeurs(int T[], int taille, int x) {
    trier_tableau(T, taille);
    int gauche = 0;
    int droite = taille - 1;
    while (gauche < droite) {
        int somme = T[gauche] + T[droite];
        if (somme == x) {
            return true;
        } else if (somme < x) {
            gauche++;
        } else {
            droite--;
        }
    }
    return false;
}

// ==========================================
// 3. SOMME DE 3 ÉLÉMENTS ÉGALE À X (3 ALGOS)
// ==========================================

// Algo 1 : Force Brute - O(N^3)
bool trois_somme_force_brute(const int T[], int taille, int x) {
    if (taille < 3) return false;
    for (int i = 0; i < taille - 2; ++i) {
        for (int j = i + 1; j < taille - 1; ++j) {
            for (int k = j + 1; k < taille; ++k) {
                if (T[i] + T[j] + T[k] == x) return true;
            }
        }
    }
    return false;
}

// Algo 2 : Double boucle + Recherche Dichotomique - O(N^2 log N)
bool trois_somme_dichotomique(int T[], int taille, int x) {
    if (taille < 3) return false;
    trier_tableau(T, taille);

    for (int i = 0; i < taille - 2; ++i) {
        for (int j = i + 1; j < taille - 1; ++j) {
            int cible = x - (T[i] + T[j]);
            
            // Recherche dichotomique de 'cible' uniquement 
            // sur la portion restante T[j+1 ... taille-1]
            int gauche = j + 1;
            int droite = taille - 1;
            while (gauche <= droite) {
                int milieu = gauche + (droite - gauche) / 2;
                if (T[milieu] == cible) {
                    return true;
                } else if (T[milieu] < cible) {
                    gauche = milieu + 1;
                } else {
                    droite = milieu - 1;
                }
            }
        }
    }
    return false;
}

// Algo 3 : Tri + Deux pointeurs - O(N^2)
bool trois_somme_pointeurs(int T[], int taille, int x) {
    if (taille < 3) return false;
    trier_tableau(T, taille);

    for (int i = 0; i < taille - 2; ++i) {
        int gauche = i + 1;
        int droite = taille - 1;
        int cible_restante = x - T[i];

        while (gauche < droite) {
            int somme_deux = T[gauche] + T[droite];
            if (somme_deux == cible_restante) {
                return true;
            } else if (somme_deux < cible_restante) {
                gauche++;
            } else {
                droite--;
            }
        }
    }
    return false;
}

// ==========================================
// 4. SOMME DE N ÉLÉMENTS (SUBSET SUM)
// ==========================================

bool somme_sous_ensemble(const int T[], int taille, int x) {
    if (x == 0) return true;
    if (x < 0) return false;

    // Allocation dynamique d'un tableau de booléens natif
    bool* dp = new bool[x + 1];
    for (int i = 0; i <= x; ++i) dp[i] = false;
    dp[0] = true;

    for (int i = 0; i < taille; ++i) {
        int num = T[i];
        for (int j = x; j >= num; --j) {
            if (dp[j - num]) {
                dp[j] = true;
            }
        }
    }

    bool resultat = dp[x];
    delete[] dp; // Libération propre de la mémoire
    return resultat;
}

// Algo pour la reconstruction de la solution (si nécessaire)
std::vector<int> somme_sous_ensemble(const std::vector<int>& T, int x) {
    if (x <= 0) return {};

    std::vector<int> parent(x + 1, -1);
    parent[0] = 0;

    for (int num : T) {
        if (num <= 0) continue;
        for (int j = x; j >= num; --j) {
            if (parent[j - num] != -1 && parent[j] == -1) {
                parent[j] = num;
            }
        }
    }

    if (parent[x] == -1) return {};

    std::vector<int> solution;
    for (int curr = x; curr > 0; curr -= parent[curr]) {
        solution.push_back(parent[curr]);
    }

    return solution;
}