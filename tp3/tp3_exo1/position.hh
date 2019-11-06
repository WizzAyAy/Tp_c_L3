#pragma once
#include <string>

using coordonnee = int;

class position
{
public:
    position(coordonnee x, coordonnee y);
    position(const position &pos);

    coordonnee getX() const {return _x ;}
    coordonnee getY() const {return _y ;}
    void setX (coordonnee const &x) {_x = x;}
    void setY (coordonnee const &y) {_y = y;}

    bool compare (position const &pos) const;
    void affiche () const;
    std::string toString() const;


private:
    coordonnee _x, _y;

};


