#pragma once
#include "element.hh"
#include "taille.hh"
#include "position.hh"
#include <string>

class objetRamassage : public element
{
public:
    objetRamassage(position pos, taille t, int nbPoints);
    int getNbPoints() const {return _nbPoints;}
    void setNbpoints(int const nbPoints) {_nbPoints = nbPoints;}
    std::string toString()const;


private:
    int _nbPoints;
};
