#include "sequence.h"
#include <iostream>

sequence::sequence()
    : _taille(0) {
}

sequence::sequence(const sequence &s) :
_contenue(s._contenue), _taille(s._taille){

}

void sequence::ajouter(const couleur &coul){
    _contenue.push_back(coul);
    _taille++;
}

couleur sequence::acces(const indicesequence &ind){
    return _contenue[ind];
}

void sequence::vider(){
    _contenue.clear();
    _taille++;
}

bool sequence::comparer(const sequence &seqB){
    if (seqB._taille != _taille) return false;
    for (std::vector<int>::size_type i(0); i<_contenue.size(); ++i)
        if (_contenue[i] != seqB._contenue[i]) return false;
    return true;
}
void sequence::afficher(const couleur &coul, std::ostream &os){

    switch (coul) {
    case couleur::rouge :
        os << "rouge";
        break;
    case couleur::bleu :
        os << "bleu";
        break;
    case couleur::jaune :
        os << "jaune";
        break;
    case couleur::vert :
        os << "vert";
        break;

    default:
        break;
    }
}
void sequence::afficher(const couleur &coul){

    switch (coul) {
    case couleur::rouge :
        std::cout << "rouge";
        break;
    case couleur::bleu :
        std::cout << "bleu";
        break;
    case couleur::jaune :
        std::cout << "jaune";
        break;
    case couleur::vert :
        std::cout << "vert";
        break;

    default:
        break;
    }
}

void sequence::afficher(std::ostream &os){
    for (std::vector<int>::size_type i(0); i<_contenue.size(); ++i)
        afficher(acces(i),os);
    std::cout << " ";

}

indicesequence sequence::taille() const{
    return _taille;
}

void sequence::copier(const sequence &seqB){
    //copie seqB dans this
    _contenue.clear();
    for (auto & i : seqB._contenue)
        _contenue.push_back(i);
    _taille = seqB._taille;
}
