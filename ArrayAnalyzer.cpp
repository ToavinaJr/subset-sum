#include "ArrayAnalyzer.hpp"
#include <algorithm>

ArrayAnalyzer::ArrayAnalyzer(std::vector<int> values) : data(std::move(values)) {}

void ArrayAnalyzer::echanger(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int ArrayAnalyzer::partitionner(std::vector<int>& arr, int bas, int haut) {
    int pivot = arr[haut];
    int i = bas - 1;
    for (int j = bas; j < haut; j++) {
        if (arr[j] < pivot) {
            i++;
            echanger(arr[i], arr[j]);
        }
    }
    echanger(arr[i + 1], arr[haut]);
    return i + 1;
}

void ArrayAnalyzer::tri_rapide(std::vector<int>& arr, int bas, int haut) {
    if (bas < haut) {
        int pi = partitionner(arr, bas, haut);
        tri_rapide(arr, bas, pi - 1);
        tri_rapide(arr, pi + 1, haut);
    }
}

std::vector<int> ArrayAnalyzer::get_sorted_data() const {
    std::vector<int> copy = data;
    if (copy.size() > 1) {
        // Utilisation de la méthode de tri membre
        const_cast<ArrayAnalyzer*>(this)->tri_rapide(copy, 0, copy.size() - 1);
    }
    return copy;
}

// 1. Recherche
bool ArrayAnalyzer::recherche_simple(int x) const {
    for (int val : data) {
        if (val == x) return true;
    }
    return false;
}

bool ArrayAnalyzer::recherche_dichotomique(int x) const {
    auto sorted = get_sorted_data();
    int gauche = 0;
    int droite = sorted.size() - 1;
    while (gauche <= droite) {
        int milieu = gauche + (droite - gauche) / 2;
        if (sorted[milieu] == x) return true;
        if (sorted[milieu] < x) gauche = milieu + 1;
        else droite = milieu - 1;
    }
    return false;
}

// 2. Somme de 2 éléments
bool ArrayAnalyzer::deux_somme_naif(int x) const {
    size_t n = data.size();
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = i + 1; j < n; ++j) {
            if (data[i] + data[j] == x) return true;
        }
    }
    return false;
}

bool ArrayAnalyzer::deux_somme_pointeurs(int x) const {
    auto sorted = get_sorted_data();
    int gauche = 0;
    int droite = sorted.size() - 1;
    while (gauche < droite) {
        int somme = sorted[gauche] + sorted[droite];
        if (somme == x) return true;
        if (somme < x) gauche++;
        else droite--;
    }
    return false;
}

// 3. Somme de 3 éléments
bool ArrayAnalyzer::trois_somme_force_brute(int x) const {
    size_t n = data.size();
    if (n < 3) return false;
    for (size_t i = 0; i < n - 2; ++i) {
        for (size_t j = i + 1; j < n - 1; ++j) {
            for (size_t k = j + 1; k < n; ++k) {
                if (data[i] + data[j] + data[k] == x) return true;
            }
        }
    }
    return false;
}

bool ArrayAnalyzer::trois_somme_dichotomique(int x) const {
    size_t n = data.size();
    if (n < 3) return false;
    auto sorted = get_sorted_data();

    for (size_t i = 0; i < n - 2; ++i) {
        for (size_t j = i + 1; j < n - 1; ++j) {
            int cible = x - (sorted[i] + sorted[j]);
            int gauche = j + 1;
            int droite = n - 1;
            while (gauche <= droite) {
                int milieu = gauche + (droite - gauche) / 2;
                if (sorted[milieu] == cible) return true;
                if (sorted[milieu] < cible) gauche = milieu + 1;
                else droite = milieu - 1;
            }
        }
    }
    return false;
}

bool ArrayAnalyzer::trois_somme_pointeurs(int x) const {
    size_t n = data.size();
    if (n < 3) return false;
    auto sorted = get_sorted_data();

    for (size_t i = 0; i < n - 2; ++i) {
        int gauche = i + 1;
        int droite = n - 1;
        int cible = x - sorted[i];

        while (gauche < droite) {
            int somme = sorted[gauche] + sorted[droite];
            if (somme == cible) return true;
            if (somme < cible) gauche++;
            else droite--;
        }
    }
    return false;
}

// 4. Somme de N éléments
bool ArrayAnalyzer::somme_sous_ensemble_existe(int x) const {
    if (x == 0) return true;
    if (x < 0) return false;

    std::vector<bool> dp(x + 1, false);
    dp[0] = true;

    for (const int& num : data) {
        for (int j = x; j >= num; --j) {
            if (dp[j - num]) dp[j] = true;
        }
    }
    return dp[x];
}

std::vector<int> ArrayAnalyzer::somme_sous_ensemble_reconstruire(int x) const {
    if (x <= 0) return {};

    std::vector<int> parent(x + 1, -1);
    parent[0] = 0;

    for (const int& num : data) {
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