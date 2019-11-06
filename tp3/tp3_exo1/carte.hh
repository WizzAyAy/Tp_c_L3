#pragma once
#include <list>
#include "personnage.hh"
#include "objetramassage.hh"
#include "obstacle.hh"
#include "position.hh"

class carte
{
public:
    carte(taille t);
    //question 5

    void ajouterPersonnage(personnage p){_listePerso.push_back(p);}
    void ajouterObjet(objetRamassage o){_listeObjet.push_back(o);}
    void ajouterObstacle(obstacle o){_listeObstacle.push_back(o);}
    void affichage() const;
    static bool intervalleIntEnCommun(int min1, int max1, int min2, int max2);
    static bool intersectionEnCommun(element const &e1, element const &e2);
    bool peutBouger(personnage const &p, int direction);
private:
    taille _taille;
    position _origine;
    std::list<personnage> _listePerso;
    std::list<objetRamassage> _listeObjet;
    std::list<obstacle> _listeObstacle;
};

