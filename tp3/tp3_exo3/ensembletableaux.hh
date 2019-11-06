#pragma once
#include "ensemble.hh"
#include <array>
class ensembletableaux : public ensemble
{
public:
    ensembletableaux();
    ensembletableaux(const ensembletableaux & e);
    ~ensembletableaux();

    void ajoutersansverif(int nb);
    void afficher();
    int * getTab(){return _tab;}
    size_t getTaille(){return _taille;}
    bool appartient(int nb)const;
    void enlever(int nb);
    bool estVide();
    bool estfini(const parcours &p) const;
    int acces(const parcours &p) const;
    void vider();

private:
    std::size_t _taille;
    int *_tab;

};
