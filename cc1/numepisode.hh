#pragma once
#include <string>

struct numEpSerie
{
    unsigned int numSaison;
    unsigned int numEpisode;
};

class numepisode
{
public:
    numepisode(unsigned int nS, unsigned int nE);
    unsigned int getNumSasion()const{return _num.numSaison;}
    unsigned int getNumEpisode()const{return _num.numEpisode;}
    std::string toString()const;
    bool estAvant(const numepisode &n2)const;

private:
    numEpSerie _num;
};
