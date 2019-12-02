#pragma once
#include "piece.hh"
#include <vector>

class roi : public piece
{
public:
    roi(const couleur &c, const position &p);
    std::string toString()const;
    std::vector<position> deplacementspossibles() const;
private:
    //on aurait du cree des methodes pour avoir le symbole et la valeur ! car toute les instaces de roi
    //on la meme valeur !!!
    //donc cree des string et des int pour chaque instance est un peu inutile !!!
    const char* _symbol;
    unsigned int _valeur;
};
