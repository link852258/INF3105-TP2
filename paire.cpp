#include "paire.h"


std::string Paire::getDateExpiration(){
    return dateExpitation;
}

std::vector<std::string>& Paire::getListeRecette(){
    return listeRecette;
}

void Paire::setDateExpiration(std::string _dateExpiration){
    dateExpitation = _dateExpiration;
}