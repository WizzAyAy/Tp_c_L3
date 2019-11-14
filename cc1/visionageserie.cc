#include "visionageserie.hh"

visionageSerie::visionageSerie(unsigned int date, std::string nom, numepisode ne)
    :visionage(date,nom), _dernierEpisodeVue(ne){

}

std::string visionageSerie::toString() const
{
    std::string s = visionage::toString();
    s += " ";
    s += getNom();
    s += " ";
    s += getDernierEp().toString();
    return s;

}

bool visionageSerie::contientnumero(const unsigned int &a) const
{
    if (a == _dernierEpisodeVue.getNumEpisode() || a == _dernierEpisodeVue.getNumSasion()) return true;
    else return false;
}

visionage *visionageSerie::clone()const{
    return new visionageSerie(*this);
}

