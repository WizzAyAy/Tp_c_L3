#include "rectangle.hh"
#include <iostream>

rectangle::rectangle(couleur const &coul, point const &a, point const& b)
    :figure(coul, a), _b(b){
    std::cout << "construction d'un rectangle par default \n";
}

rectangle::rectangle(rectangle const &rec)
    :figure(rec), _b(rec._b){
    std::cout << "construction d'un rectangle par recopie \n";
}

rectangle::~rectangle(){
    std::cout << "destruction d'un rectangle \n";
}

void rectangle::afficher(){
  std::cout << "type rectangle \n";
    figure::afficher();
    _b.afficher();
}

bool rectangle::estCarre() const{
    return (getOrigine().getX() - _b.getX() == getOrigine().getY() - _b.getY());
}

