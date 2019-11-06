#pragma once
#include <string>

using coordonnee = int;

class taille
{
public:
    taille(coordonnee hauteur, coordonnee largeur);
    taille(const taille &t);

    coordonnee getHauteur () const {return _hauteur;}
    coordonnee getLargeur () const {return _largeur;}
    void setLargeur (coordonnee largeur){_largeur = largeur;}
    void setHauteur (coordonnee hauteur){_hauteur = hauteur;}

    std::string toString() const;

private:
    coordonnee _hauteur, _largeur;

};
