#include "livre.hh"
#include <iostream>

livre::livre(const std::string &t, const std::string &a, unsigned int pages, bool emprunt)
    :documentManuscrit(t,a,pages), _empruntable(emprunt){}

std::ostream &operator<<(std::ostream &os, const livre &l){
    os << "livre (" << l.getTitre() << "," << l.getNomAuteur() << ",emprunt=" << l.peutEtreEmprunt() << ",cout=" << l.coutPerte();
    os << ",nbpage=" << l.getnbPages() << ")";
    return os;
}
