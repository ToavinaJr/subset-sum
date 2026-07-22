cmake_minimum_required(VERSION 3.20)

# Nom du projet et langage utilisé
project(SommeTableauNatif CXX)

# Forcer l'utilisation du standard C++23
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Ajouter l'exécutable et lister tous les fichiers sources nécessaires
add_executable(main_app 
    main.cpp 
    partial_sum.cpp 
    partial_sum.hpp
)