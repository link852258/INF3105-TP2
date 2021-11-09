#include "arbreavl.h"
#include <stdio.h>

using namespace std;

int main(int argc, const char** argv){
    ArbreAVL<int> arbre, arbre2;
    arbre.inserer(10);
    arbre.inserer(15);
    arbre.inserer(5);
    arbre.inserer(1);
    arbre.inserer(7);
    arbre.inserer(17);
    arbre.inserer(20);
    cout << arbre.rechercherEgalOuSuivant(2);
    return 0;
}