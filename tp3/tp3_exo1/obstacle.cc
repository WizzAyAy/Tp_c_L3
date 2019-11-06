#include "obstacle.hh"

obstacle::obstacle(position pos, taille t)
    :element(pos,t){}

std::string obstacle::toString()const{
    std::string S = element::toString();
    return S;
}
