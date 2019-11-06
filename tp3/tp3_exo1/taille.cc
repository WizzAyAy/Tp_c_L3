#include "taille.hh"
#include <iostream>

taille::taille(coordonnee hauteur, coordonnee largeur){
    _hauteur = hauteur;
    _largeur = largeur;
}

taille::taille(const taille &t)
    :_hauteur(t._hauteur), _largeur(t._largeur){

}

std::string taille::toString() const{
    std::string S("");
    std::string hauteur = std::to_string(_hauteur);
    std::string largeur = std::to_string(_largeur);
    S += "T[";
    S += hauteur;
    S += ",";
    S += largeur;
    S += "]";
    return S;
}
