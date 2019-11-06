#include "point.hh"
#include <iostream>

point::point(int const &x, int const &y)
    :_x(x), _y(y) {
    std::cout << "construction grace au constructeur de point \n";
}

point::point(point const &p)
    :_x(p._x), _y(p._y) {
    std::cout << "construction grace au constructeur par recopie du point ! \n";
}

point::~point(){
    std::cout << "destruction de l'object point ... \n";
}

void point::afficher()const{
    std::cout << "point [" << _x << "," << _y << "] \n";
}
