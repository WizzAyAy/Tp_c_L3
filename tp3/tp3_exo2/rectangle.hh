#pragma once
#include "segment.hh"
#include "point.hh"

class rectangle : public figure
{
public:
    rectangle(couleur const &coul, const point &a, const point &b);
    rectangle(rectangle const &rec);
    ~rectangle();
    void afficher();
    bool estCarre()const;
public:

    point _b;
};
