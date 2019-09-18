#pragma once
#include <iostream>

using coordonnee = int;

class taille
{
public:
    taille(coordonnee hauteur, coordonnee largeur);

    coordonnee getHauteur () {
        return _hauteur;
    }
    coordonnee getLargeur () {
        return _largeur;
    }
    void setLargeur (coordonnee largeur){
        _largeur = largeur;
    }
    void setHauteur (coordonnee hauteur){
        _hauteur = hauteur;
    }

private:
    coordonnee _hauteur, _largeur;

};
