/*
  INF3105 - Structures de données et algorithmes
  UQAM / Département d'informatique
  
  Squelette de départ. Vous pouvez modifier ce fichier à votre guise.
  Vous n'êtes pas oubligés de l'utiliser.
*/
#ifndef STOCK_H
#define STOCK_H

#include <iostream>
#include <map>
#include <vector>
#include "paire.h"

class Recette {

    private:
        std::map<std::string, int> ingredients;

    public:
        std::map<std::string, int> getIngredients() const;

  
    friend std::istream& operator >> (std::istream& is, Recette& recette);
};

class Stock
{
    private:
        
        std::map<std::string, std::map<std::string, int >> ingredients;

        bool ingredientExiste(const std::string& nomIngredient);

        bool ingredientQuantiteValide(const std::string& nomIngredient, const int& quantiteRequise);

    public:
        Stock();

        void ajout(std::string nomingredient, std::string date, int nombre);

        void retrait(std::string nomingredient, int nombre);

        void affichage();

        std::string dateExpiration(const Recette& recette);

        bool realisable(const Recette& recette);

        void utilisation(const Recette& recette);

        void recommendation(const std::map<std::string, Recette>& recettesValide);

        std::map<std::string, std::map<std::string, int>> getIngredients();

};




#endif // STOCK_H