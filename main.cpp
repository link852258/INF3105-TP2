#include "arbremap.h"
#include <stdio.h>

using namespace std;

int main(int argc, const char** argv){
    ArbreMap<string, int> arbre;
    arbre["allo"] = 5;
    cout << arbre["allo"];
    return 0;
}