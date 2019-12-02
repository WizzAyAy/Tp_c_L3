#include "video.hh"
#include <iostream>

video::video(const std::string &t, const std::string &a, const typeSupport &s)
    :document(t,a), _support(s){}

void video::sortieflux(std::ostream &os) const
{
    document::sortieflux(os);
    typeSupport temp = getType();
    if(temp == typeSupport::BluRay)
        os << " BLURAY";
    if(temp == typeSupport::BluRay3D)
        os << " BLURAY3D";
    if(temp == typeSupport::DVD)
        os << " DVD";

}

std::ostream &operator<<(std::ostream &os, const video &v){
    os << "video (" << v.getTitre() << "," << v.getNomAuteur() << ",emprunt=" << v.peutEtreEmprunt() << ",cout=" << v.coutPerte();
    typeSupport temp = v.getType();
    os << ",type=";
    if(temp == typeSupport::BluRay)
        os << "BLURAY";
    if(temp == typeSupport::BluRay3D)
        os << "BLURAY3D";
    if(temp == typeSupport::DVD)
        os << "DVD";
    os << ")";
    return os;
}
