#include "ensembletableaux.hh"
#include <iostream>

ensembletableaux::ensembletableaux()
    :_taille(0),_tab(nullptr){
}

ensembletableaux::ensembletableaux(ensembletableaux const & e)
    : _taille(e._taille), _tab((e._taille == 0) ? nullptr : new int [e._taille])  {
    //(e._taille == 0) ? _tab=nullptr : _tab=new int [_taille];
    //je ne sais pas la metre dans la liste d'init ... ENFAITE SI mdr
    for (std::size_t i = 0; i < _taille; i++){
           _tab[i] = e._tab[i];
    }
}

ensembletableaux::~ensembletableaux(){
    delete [] _tab;
}

void ensembletableaux::ajoutersansverif(int nb){
    int * newSeq (new int[_taille+1]);

    for (size_t i = 0; i < _taille; i++){
        newSeq[i] = _tab[i];

    }
    newSeq[_taille] = nb;
    delete [] _tab;
    _tab = newSeq;
    ++_taille;
}

void ensembletableaux::afficher(){
    for (size_t i = 0; i < _taille; i++){
        std::cout << _tab[i] << " ";
    }
    std::cout << "\n";
}

bool ensembletableaux::appartient(int nb)const{
    for (size_t i = 0; i < _taille; i++){
        if(nb == _tab[i]) return true;
    }
    return false;
}

void ensembletableaux::enlever(int nb){
    //si on enleve juste le pointeur on perd la suite du tab
    //donc il faut 1: regarder si il app
    //si c'est le premier alors on pointe _tab sur le 2eme ?
    //si c'est le ieme alors on pointe le i-1 sur le i+1 ?
    //si c'est le dernier on le supp juste ?
    if (_taille == 1){
        _taille = 0;
        delete [] _tab ;
        _tab = nullptr;
        return;
    }
    else {
        for (size_t i = 0; i < _taille; i++){
            if(_tab[i] == nb){
               _tab[i] = _tab[_taille+1];
               _taille--;
               return;
            }
        }
    }
}

bool ensembletableaux::estVide(){
    return (_taille == 0);
}

bool ensembletableaux::estfini(const parcours &p) const{
    return _taille <= p.getPos();
}

int ensembletableaux::acces(const parcours &p) const
{
    return _tab[p.getPos()];
}

void ensembletableaux::vider()
{
    delete [] _tab;
    _tab = nullptr;
    _taille = 0;
}
