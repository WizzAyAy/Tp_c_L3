#include <iostream>
#include "grille.h"

Grille::Grille(coordonnee hauteur, coordonnee largeur)
    : _hauteur(hauteur),
      _largeur(largeur) {

    std::vector<etatCell> temp;
    for(size_t j = 0; j < _largeur; j++){
        temp.push_back(mort);
    }
    for(size_t i = 0; i < _hauteur; i++){
        _matriceEtats.push_back(temp);
    }
}

void Grille::vider(){
    for(size_t i = 0; i < _hauteur; i++){
        for(size_t j = 0; j < _largeur; j++){
            _matriceEtats[i][j] = mort;
        }
    }
}

bool Grille::vivante(coordonnee x, coordonnee y){
    if(x < 0 || x >= _hauteur) return false;
    if(y < 0 || y >= _largeur) return false;
    if(_matriceEtats[x][y] == vivant) return true;
    return false;
}

void Grille::generer(coordonnee x, coordonnee y){
    //meme si la case est deja vivant ce n'st pas grave
    _matriceEtats[x][y] = vivant;
}

void Grille::tuer(coordonnee x, coordonnee y){
    //meme si la case est deja morte ce n'st pas grave
    _matriceEtats[x][y] = mort;
}

void Grille::afficher(){
    for(size_t i = 0; i < _hauteur; i++){
        std::cout << "|";
        for(size_t j = 0; j < _largeur; j++){
            if(_matriceEtats[i][j] == mort)
                std::cout << " ";
            else
                std::cout << "*";
       }
        std::cout << "|" << std::endl;
    }
}
//x-1 y-1     x y-1   x+1 y-1
//x-1  y       x y     x+1 y
//x-1 y+1     x y+1   x+1 y+1

int Grille::vivantes(coordonnee x, coordonnee y){
    int nbCases(0);

//oui pour les cases du "milieu" et des bords grace a la modif de vivante
        for (int i = -1; i < 2; i++){
            for (int j = -1; j < 2; j++){
                if (vivante(i+x, j+y)) nbCases++;
            }
        }
    return nbCases;
}

void Grille::evolutionGrille(Grille &g){
    int nbvoisins(0);
    for(size_t i = 0; i < _hauteur; i++){
        for(size_t j = 0; j < _largeur; j++){
            nbvoisins = vivantes(i,j);
            if(_matriceEtats[i][j] == vivant) nbvoisins--;
            //si la case est morte et quelle a 3 voisins alors elle passe vivante
            if(_matriceEtats[i][j] == mort && nbvoisins == 3){
//std::cout << "case en " << i << " " << j << " est morte et elle a " << nbvoisins << " voisins donc dans la nouv elle sera vivante \n";
                g._matriceEtats[i][j] = vivant;
            }
            //si la case est vivante et quelle a 2 ou 3 voisins alors elle reste vivante
            if(_matriceEtats[i][j] == vivant && (nbvoisins == 2 || nbvoisins == 3)){
                g._matriceEtats[i][j] = vivant;
//std::cout << "case en " << i << " " << j << " est vivante et elle a " << nbvoisins << " voisins donc dans la nouv elle sera vivante \n";
            }
        }
    }
}

void Grille::ajouterStructure(structure struc, coordonnee x, coordonnee y){
    switch (struc) {
    case structure::oscillateurLigne :
        generer(x,y);
        generer(x,y+1);
        generer(x,y+2);
        break;
    case structure::floraison :
        ajouterStructure(structure::oscillateurLigne, x , y+1);
        ajouterStructure(structure::oscillateurLigne, x+2 , y+1);
        generer(x+1,y+0);
        generer(x+1,y+2);
        generer(x+1,y+4);
        break;
    case structure::planeur :
        generer(x,y);
        generer(x,y+1);
        generer(x,y+2);
        break;
    case structure::oscillateurCroix :
        generer(x,y);
        generer(x,y+1);
        generer(x,y+2);
        break;
    default:
        break;
    }

}
