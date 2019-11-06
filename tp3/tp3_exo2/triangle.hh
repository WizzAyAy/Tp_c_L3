#pragma once
#include "point.hh"
#include "figure.hh"
class triangle : public figure
{
public:
    triangle(couleur coul, point a, point b, point c);
    triangle(triangle const &trian);
    ~triangle();
    void afficher();

private:
    point _b;
    point _c;
    couleur _coul;
};

