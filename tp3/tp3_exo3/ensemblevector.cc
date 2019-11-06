#include "ensemblevector.hh"
#include <iostream>
#include <algorithm>

ensemblevector::ensemblevector(){
//    std::cout << "construction ensvec \n";
}

ensemblevector::ensemblevector(const ensemble &ens)
{
    for(parcours p = ens.commencer(); !ens.estfini(p); ens.suivant(p)){
        _vect.push_back(ens.acces(p));
    }
}

void ensemblevector::ajoutersansverif(int nb){
    _vect.push_back(nb);
}

void ensemblevector::afficher(){
    for(auto x : _vect){
        std::cout << x << " ";
    }
    std::cout << "\n";
}

void ensemblevector::enlever (int nb){

//    for(std::vector<int>::iterator i(_vect.begin()); i!=_vect.end(); i++){
//        if(nb == *i) {
//            _vect.erase(i);
//            return;
//        }
//    }
    //meilleur soluce
    auto it = std::find(_vect.begin(),_vect.end(),nb);
    if(it != _vect.end());
    _vect.erase(it);
}

bool ensemblevector::appartient(int nb)const{
    for(auto x : _vect){
        if (x == nb) return true;
    }
    return false;
}

bool ensemblevector::estVide(){
    return (_vect.empty());
}

bool ensemblevector::estfini(const parcours &p) const
{
    return p.getPos() >= _vect.size();
}

int ensemblevector::acces(const parcours &p) const
{
    return _vect[p.getPos()];
}

void ensemblevector::vider()
{
    _vect.clear();
}
