#pragma once
#include "position.hh"
#include "taille.hh"
#include <string>


class element
{
public:
    element(position pos, taille t);

    position getPos()const{return _pos;}
    taille getTaille()const{return _t;}
    void setPos(position pos){_pos=pos;}
    void setTaille(taille t){_t=t;}
    std::string toString() const;
    bool contientPosition (position const &pos) const;

private:
    position _pos;
    taille _t;
};

