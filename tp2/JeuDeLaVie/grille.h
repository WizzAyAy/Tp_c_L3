#pragma once
#include <vector>
#include <string>

using coordonnee = size_t;

class Grille
{
public:
    Grille(coordonnee hauteur, coordonnee largeur);
    void vider();
    bool vivante(coordonnee x, coordonnee y);
    void generer(coordonnee x, coordonnee y);
    void tuer(coordonnee x, coordonnee y);
    void afficher();

private:

    enum etatCell {mort,vivant};
    coordonnee _hauteur;
    coordonnee _largeur;
    std::vector<etatCell> _matriceEtats;
//    std::vector<vec> _matriceEtat;
//    std::vector<std::vector<etatCell>> _matriceEtat;
//    std::vector<std::vector<etatCell> > _matriceEtat(10, vector<M>(10));

      struct structures{
          std::string nom;
          std::vector<coordonnee> cellVivantes;
      };
};
