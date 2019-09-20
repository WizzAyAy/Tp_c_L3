#include <iostream>
#include "grille.h"

using namespace std;

int main()
{
    Grille g1(10,10);
    g1.generer(0,0);
    g1.afficher();
    return 0;
}
