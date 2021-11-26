#ifndef PAIRE_H
#define PAIRE_H

#include "vector"
#include <fstream>

class Paire{
    public:
        std::string getDateExpiration();
        std::vector<std::string>& getListeRecette();
        void setDateExpiration(std::string _dateExpiration);
    
    private:
        std::string dateExpitation;
        std::vector<std::string> listeRecette;

};

#endif