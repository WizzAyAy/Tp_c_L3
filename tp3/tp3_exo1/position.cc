#include "position.hh"
#include <iostream>
#include <string>

position::position(coordonnee x, coordonnee y)
    : _x(x), _y(y){
}

position::position(const position &pos)
    : _x(pos._x), _y(pos._y){
}

bool position::compare (position const &pos)const{
    return ( _x == pos.getX() && pos.getY() == _y);
}

void position::affiche() const{
    std::cout << "x[" << _x << "], y[" << _y << "] \n";
}

std::string position::toString()const{
    std::string S("");
    std::string x = std::to_string(_x);
    std::string y = std::to_string(_y);
    S += "pos[";
    S += x;
    S += ",";
    S += y;
    S += "]";
    return S;
}
