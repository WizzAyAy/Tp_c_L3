#include <iostream>
#include "grille.h"

Grille::Grille(coordonnee hauteur, coordonnee largeur)
    : _hauteur(hauteur),
      _largeur(largeur) {
    for(size_t i = 0; i < _hauteur; i++){
        for(size_t j = 0; j < _largeur; j++){
            _matriceEtat.push_back(mort);
        }
    }
}

void Grille::vider(){
    for(size_t i = 0; i < _hauteur; i++){
        for(size_t j = 0; j < _largeur; j++){
            _matriceEtat[i][j] = mort;
        }
    }
}

bool Grille::vivante(coordonnee x, coordonnee y){
    if(_matriceEtat[x] == vivant) return true;
    else return false;
}

void Grille::generer(coordonnee x, coordonnee y){
    //meme si la case est deja vivant ce n'st pas grave
    _matriceEtat[x][j] = vivant;
}

void Grille::tuer(coordonnee x, coordonnee y){
    //meme si la case est deja morte ce n'st pas grave
    _matriceEtat[x][j] = mort;
}

void Grille::afficher(){
    for(size_t i = 0; i < _hauteur; i++){
        for(size_t j = 0; j < _largeur; j++){
            if(_matriceEtat[i][j] == mort)
                std::cout << " ";
            else
                std::cout << "*";
       }
        std::cout << std::endl;
    }
}
