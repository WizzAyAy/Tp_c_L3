#pragma once
#include "position.hh"
#include <vector>
#include <memory>

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
    virtual std::unique_ptr<piece> clone() const =0;

    void setPosition(position const & p){_p = p;}

    position getPosition()const{return _p;}
    couleur getCouleur()const{return _c;}
    virtual int getValeur()const=0;
    virtual std::string getSymbol()const=0;

    virtual std::vector<position> deplacementspossibles()const=0;
    bool accepterposition(position const & p)const;
    bool deplacer(position const & p);

private:
    couleur _c;
    position _p;
};

std::ostream & operator<<(std::ostream & os, piece const & p);
