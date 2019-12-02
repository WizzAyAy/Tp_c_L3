#include "document.hh"
#include <iostream>
document::document(const std::string &t, const std::string &a)
    :_titre(t), _nomAuteur(a){

}

void document::sortieflux(std::ostream &os ) const{
    os << getTypedoc() << " " << _titre << " " <<_nomAuteur << " ";
    if(peutEtreEmprunt())
        os << "empruntable ";
    else
        os << "nom empruntable ";
    os << coutPerte() << "e";
}

std::ostream &operator<<(std::ostream &os, const document &d){
    d.sortieflux(os);
    return os;
}
