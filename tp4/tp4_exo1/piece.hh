#pragma once
#include "position.hh"
#include <vector>

enum class couleur
{
    B,
    N
};

class piece
{
public:
    piece(couleur const & c, position const &p);
    //on aurait pu cree une seule methde to string !!!
    virtual std::string toString()const;
    position getPosition()const{return _p;}
    void setPosition(position const & p){_p = p;}
    couleur getCouleur()const{return _c;}
    virtual std::vector<position> deplacementspossibles()const=0;
    bool accepterposition(position const & p)const;
    bool deplacer(position const & p);
private:
    couleur _c;
    position _p;
};

