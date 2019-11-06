#include "figure.hh"
#include <iostream>

figure::figure(couleur coul, point a)
    :_coul(coul), _origine(a) {
    std::cout << "contruction d'une figure \n";
}

void figure::afficher() const {

    std::cout << "point origine = ";
    _origine.afficher();
    std::cout << "la couleur est : ";
    switch (_coul) {
    case couleur::bleu:
        std::cout << "bleu \n";
        break;
    case couleur::rouge:
        std::cout << "rouge \n";
        break;
    case couleur::vert:
        std::cout << "vert \n";
        break;
    }
}


bool figure::memeOrigine(const figure &a, const figure &b){
    return (a._origine.getX() == b._origine.getX() && a._origine.getY() == b._origine.getY());
}
