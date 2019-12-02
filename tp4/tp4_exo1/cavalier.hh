#pragma once
#include "piece.hh"
#include <vector>

class cavalier : public piece
{
public:
    cavalier(const couleur &c, const position &p);
    std::string toString()const;
    std::vector<position> deplacementspossibles() const;
private:
    const char* _symbol;
    unsigned int _valeur;
};
