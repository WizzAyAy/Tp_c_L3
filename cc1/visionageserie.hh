#pragma once
#include "visionage.hh"
#include "numepisode.hh"


class visionageSerie : public visionage
{
public:
    visionageSerie(unsigned int date, std::string nom, numepisode ne);

    numepisode getDernierEp()const{return _dernierEpisodeVue;}
    std::string typevisionnage() const {return "Serie";}
    std::string toString()const;
    bool contientnumero(const unsigned int &a) const;
    visionage * clone()const;
private:
    numepisode _dernierEpisodeVue;
};
