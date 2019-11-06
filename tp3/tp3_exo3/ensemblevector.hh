#pragma once
#include "ensemble.hh"
#include <vector>


class ensemblevector : public ensemble
{
public:
    ensemblevector();
    ensemblevector(ensemblevector const & ensvec);
    ensemblevector(ensemble const & ens);
    void ajoutersansverif(int nb);
    void afficher();
    std::vector<int> getVect(){return _vect;}
    void enlever(int nb);
    bool appartient(int nb)const;
    bool estVide();
    bool estfini(const parcours &p) const;
    int acces(const parcours &p) const;
    void vider();

private:
    std::vector<int> _vect;
};
