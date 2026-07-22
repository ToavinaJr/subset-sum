#!/bin/bash

# Arrêter le script immédiatement en cas d'erreur
set -e

echo "=== Configuration du projet avec CMake ==="
# -B build : crée un dossier 'build' s'il n'existe pas et y génère les fichiers de build
# -S . : indique que le CMakeLists.txt source se trouve dans le dossier courant
cmake -S . -B build

echo "=== Compilation de l'application ==="
# Compile le projet de manière indépendante du générateur sous-jacent (Make, Ninja, etc.)
cmake --build build

