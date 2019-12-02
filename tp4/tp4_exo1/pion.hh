#pragma once
#include "piece.hh"
#include <vector>


class pion : public piece
{
public:
    pion(const couleur &c, const position &p);
    std::string toString()const;
    std::vector<position> deplacementspossibles() const;
private:
    const char* _symbol;
    unsigned int _valeur;
    bool _dejaDeplace;

};
