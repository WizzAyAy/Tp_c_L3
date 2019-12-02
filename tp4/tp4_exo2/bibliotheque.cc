#include "bibliotheque.hh"
#include "video.hh"
#include <iostream>

bibliotheque::~bibliotheque(){
    for(auto i : _lesdocs)
        delete i;
}

bibliotheque::bibliotheque(const bibliotheque &b){
    for(auto i : b._lesdocs)
        _lesdocs.push_back(i->clone());
}

void bibliotheque::afficher() const{
    for(auto i : _lesdocs)
        std::cout << (*i) << std::endl;
}

int bibliotheque::nombreVideoType(const typeSupport &s)const{
    int compteur = 0;
    for (auto d : _lesdocs) {

    auto vi = dynamic_cast<video const*>(d);
    if (vi != nullptr)
        if(vi->getType() == s) compteur++;
    }
    return compteur;
}
