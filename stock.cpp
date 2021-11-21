/*
  INF3105 - Structures de données et algorithmes
  UQAM / Département d'informatique
  
  Squelette de départ. Vous pouvez modifier ce fichier à votre guise.
  Vous n'êtes pas oubligés de l'utiliser.
*/

#include "stock.h"



std::istream& operator >> (std::istream& is, Recette& recette){

    std::string chaine;
    int quantite;


    for(;;) {
        is >> chaine;
        if(chaine == ";")
            break;
        is >> quantite;
        if(recette.ingredients.count(chaine) > 0){
            recette.ingredients[chaine] += quantite;
        }
        else
            recette.ingredients[chaine] = quantite;
    }


    return is;
}

Stock::Stock(){

}

void Stock::ajout(std::string nomingredient, std::string date, int quantite){
    std::map<std::string, int> informations;
    if(ingredients.count(nomingredient) > 0){
        informations = ingredients[nomingredient];
        if(informations.count(date) > 0){
            informations[date] += quantite;
        }
        else{

            informations[date] = quantite;
        }
    }
    else{
        informations[date] = quantite;
    }
    ingredients[nomingredient] = informations;
}

void Stock::retrait(std::string nomingredient, int quantite){
    std::map<std::string, int> informations;
    if(ingredients.count(nomingredient) > 0){
        informations = ingredients[nomingredient];
        std::map<std::string, int>::iterator iterDebut = informations.begin();
        std::map<std::string, int>::iterator iterIndexFin = informations.begin();
        while (quantite > 0)
        {
            quantite -= iterIndexFin->second;
            if(quantite >= 0){
                ++iterIndexFin;
            }
        }
        informations.erase(iterDebut, iterIndexFin);
        if(quantite < 0){
            informations[iterIndexFin->first] = -quantite;
        }
        ingredients[nomingredient] = informations;
        if(ingredients[nomingredient].empty()){
            ingredients.erase(nomingredient);
        }
    }
}


void Stock::affichage(){
    std::map<std::string, std::map<std::string, int>>::iterator iterDebut = ingredients.begin();
    std::map<std::string, std::map<std::string, int>>::iterator iterFin = ingredients.end();
    for(;iterDebut != iterFin;++iterDebut){
        int quantite = 0;
        std::cout << iterDebut->first << " ";
        std::map<std::string, int>::iterator iterDebut2 = iterDebut->second.begin();
        std::map<std::string, int>::iterator iterFin2 = iterDebut->second.end();
        for(;iterDebut2 != iterFin2; ++iterDebut2){
            quantite += iterDebut2->second;
        }
        std::cout << quantite << std::endl;
    }
    std::cout << ";";
}


bool Stock::realisable(const Recette& recette) const{
    for(const auto& ingredient: recette.getIngredients()){
        if(ingredientExiste(ingredient.first)){
            if(!ingredientQuantiteValide(ingredient.first, ingredient.second)){
                return false;
            }
        }
        else return false;
    }
    return true;
}

bool Stock::ingredientExiste(const std::string& nomIngredient) const{
    return (ingredients.count(nomIngredient) > 0);
}

bool Stock::ingredientQuantiteValide(const std::string& nomIngredient, const int& quantiteRequise) const{
    int quantiteTotale = 0;
    for(const auto& kv : getIngredients()[nomIngredient]){
        quantiteTotale += kv.second;
    }
    return (quantiteTotale >= quantiteRequise);
}

std::map<std::string, int> Recette::getIngredients() const{
    return ingredients;
}

std::map<std::string, std::map<std::string, int>> Stock::getIngredients() const{
    return ingredients;
}