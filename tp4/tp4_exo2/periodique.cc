#include "periodique.hh"
#include <iostream>

periodique::periodique(const std::string &t, const std::string &a, unsigned int pages, unsigned int num)
    :documentManuscrit(t,a,pages), _numero(num){}

void periodique::periodique::sortieflux(std::ostream &os) const
{
    documentManuscrit::sortieflux(os);
    os << _numero << "num";
}

std::ostream &operator<<(std::ostream &os, const periodique &p)
{
    os << "periodique (" << p.getTitre() << "," << p.getNomAuteur() << ",emprunt=" << p.peutEtreEmprunt() << ",cout=" << p.coutPerte();
    os << ",nbpage=" << p.getnbPages() << ",numero=" << p.getNum() <<")";
    return os;
}
