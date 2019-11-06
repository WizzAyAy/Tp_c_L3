#pragma once
#include "point.hh"

enum class couleur
{
    rouge,
    vert,
    bleu

};

class figure
{
public:
    figure(couleur coul, point a);
    void afficher() const;
    couleur const & getCouleur() const {return _coul;}
    point const & getOrigine() const {return _origine;}
    static bool memeOrigine(figure const &a, figure const &b);
private:
    couleur _coul;
    point _origine;
};

