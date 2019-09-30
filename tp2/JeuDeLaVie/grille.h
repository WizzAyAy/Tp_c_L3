#pragma once
#include <vector>
#include <string>

using coordonnee = size_t;

enum class structure {oscillateurLigne,floraison,planeur,oscillateurCroix};

class Grille
{
public:
    Grille(coordonnee hauteur, coordonnee largeur);
    void vider();
    bool vivante(coordonnee x, coordonnee y);
    void generer(coordonnee x, coordonnee y);
    void tuer(coordonnee x, coordonnee y);
    void afficher();
    int vivantes(coordonnee x, coordonnee y);
    void evolutionGrille(Grille &g);
    void ajouterStructure(structure struc, coordonnee x, coordonnee y);

private:

    enum etatCell {mort,vivant};



    coordonnee _hauteur;
    coordonnee _largeur;
    structure struc;

    std::vector<std::vector<etatCell>> _matriceEtats;


};
