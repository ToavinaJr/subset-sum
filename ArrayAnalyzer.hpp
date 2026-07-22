#ifndef ARRAY_ANALYZER_HPP
#define ARRAY_ANALYZER_HPP

#include <vector>

class ArrayAnalyzer {
private:
    std::vector<int> data;

    // Méthodes privées d'aide au tri (encapsulation)
    void echanger(int& a, int& b);
    int partitionner(std::vector<int>& arr, int bas, int haut);
    void tri_rapide(std::vector<int>& arr, int bas, int haut);

public:
    // Constructeur
    explicit ArrayAnalyzer(std::vector<int> values);

    // Obtenir une copie triée sans modifier l'objet d'origine
    std::vector<int> get_sorted_data() const;

    // 1. Recherche
    bool recherche_simple(int x) const;
    bool recherche_dichotomique(int x) const;

    // 2. Somme de 2 éléments
    bool deux_somme_naif(int x) const;
    bool deux_somme_pointeurs(int x) const;

    // 3. Somme de 3 éléments
    bool trois_somme_force_brute(int x) const;
    bool trois_somme_dichotomique(int x) const;
    bool trois_somme_pointeurs(int x) const;

    // 4. Somme de N éléments (Subset Sum)
    bool somme_sous_ensemble_existe(int x) const;
    std::vector<int> somme_sous_ensemble_reconstruire(int x) const;
};

#endif