#pragma once
#include "point.hh"
#include "figure.hh"

class segment : public figure
{
public:
    segment(couleur coul, const point &a, const point &b);
    segment(segment const &seg);
    ~segment();
    void afficher();
//   static bool sontParalle(segment a, segment b);

private:
    point _b;
};
