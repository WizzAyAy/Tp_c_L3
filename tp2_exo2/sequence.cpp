#include "sequence.h"

sequence::sequence()
    : _contenue(nullptr), _taille(0){
}
sequence::sequence(seq const s)
    : (s._taille == 0) ? _contenue(nullptr) : _contenue(new couleur[s.taille]), _taille(s._taille){
    for (indicesequence i = 0; i < _taille; i++){
        _contenue[i] = s._contenue[i];
    }
}
sequence::~sequence() {
    delete [] _contenue;
}

int sequence::taille() const{
    return _taille;
}

void sequence::ajouter(const couleur &coul){

        couleur * newSeq (new couleur[_taille++]);

        for (size_t i = 0; i < _taille; i++){
            newSeq[i] = _contenue[i];

        }

        newSeq.couleurs[seq.indice] = coul;
        delete [] _contenue;
        _contenue = newSeq;
        ++_taille;
}

void sequence::copier (sequence const &source){
    _contenue = source;
}

void sequence::afficher(const couleur &coul, std::ostream os){
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
    for(indicesequence i = 0; i < _taille; i++){
        afficher(acces([i], os);
        os << " "
    }
    os << "\n";
}

void sequence::vider(){
    delete [] _contenue;
    _taille = 0;
    _contenue = nullptr;
}
