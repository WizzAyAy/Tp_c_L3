#include <iostream>
#include <string>
#include <random>
#include "grille.h"

using namespace std;
int const TAILLE = 120;
int main()
{
    string attente("");
    int tour(0);
    int nbGen(0);
    Grille g1(TAILLE,TAILLE);
    Grille g2(TAILLE,TAILLE);




    for (int i = 0; i < TAILLE; i++){
        for(int j = 0; j < TAILLE; j++){
           if(rand()%2 == 0) g1.generer(i,j);
        }
    }

    cout << "Generation " << nbGen << " \n";
    g1.afficher();
    nbGen++;

    while (attente == "") {
      cout << "--------- NOUVELLE GENRATION --------- \n";
      cout << "Generation " << nbGen << "\n";
        if(tour % 2 == 0){
            g2.vider();
            g1.evolutionGrille(g2);
            g2.afficher();

        }
        if(tour % 2 == 1){
            g1.vider();
            g2.evolutionGrille(g1);
            g1.afficher();

        }
        tour++;
        nbGen++;
        getline(cin, attente);
    }







    return 0;
}
