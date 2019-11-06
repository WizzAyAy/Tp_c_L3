#include "triangle.hh"
#include "figure.hh"
#include <iostream>

triangle::triangle(couleur coul, point a, point b, point c)
    :figure(coul,a), _b(b), _c(c) {
    std::cout << "contructeur de triangle \n";
}

triangle::triangle(const triangle &trian)
    :figure(trian),  _b(trian._b), _c(trian._c) {
    std::cout << "constructeur recopie d'un triangle \n";
}

triangle::~triangle(){
    std::cout << "destruction d'un triangle \n";
}

void triangle::afficher(){
    std::cout << "type : triangle \n";
    figure::afficher();
    _b.afficher();
    _c.afficher();
}
