#include "position.hh"
#include <iostream>

position::position(coordonnee x, coordonnee y){
    _x = x;
    _y = y;
}

bool position::compare (position pos){
    return ( _x == pos.getX() && pos.getY() == _y);
}

void position::affiche(){
    std::cout << "x[" << _x << "], y[" << _y << "] \n";
}
