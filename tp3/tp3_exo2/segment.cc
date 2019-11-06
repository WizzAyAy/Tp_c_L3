#include "segment.hh"
#include <iostream>

segment::segment(couleur coul, point const &a, point const&b)
    :figure(coul,a), _b(b) {
    std::cout << "constructeur de segment \n";
}

segment::segment(segment const &seg)
    :figure(seg), _b(seg._b) {
    std::cout << "constructeur par recopie de segment \n";
}

segment::~segment(){
    std::cout << "destructeur de seg \n";
}

//bool segment::sontParalle(segment a, segment b){
//    float pentA, pentB;
//    pentA = (a._a.getX() - a._b.getX()) / (a._a.getY() - a._b.getY());
//    pentB = (b._a.getX() - b._b.getX()) / (b._a.getY() - b._b.getY());
//    return (pentA == pentB);
//}

void segment::afficher(){
    std::cout << "\ntype segment \n";
    figure::afficher();
    _b.afficher();
}
