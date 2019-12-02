#pragma once
#include "piece.hh"
#include <vector>

class dame : public piece
{
public:
    dame(const couleur &c, const position &p);
    std::string toString()const;
    std::vector<position> deplacementspossibles() const;
private:
    const char* _symbol;
    unsigned int _valeur;
};

