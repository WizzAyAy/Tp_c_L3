#include "numepisode.hh"
#include <string>

numepisode::numepisode(unsigned int nS, unsigned int nE)
   // : _num.numSaison(nS), _num.numEpisode(nE)
{
    //pas de liste d'init car struct
    _num.numSaison = nS;
    _num.numEpisode = nE;
}

std::string numepisode::toString() const
{
    std::string s = "S";
    std::string saison = std::to_string(getNumSasion());
    s += saison;
    std::string episode = std::to_string(getNumEpisode());
    s += "E";
    s += episode;
    s += "\n";
    return s;

}

bool numepisode::estAvant(const numepisode &n2) const
{
    //si c'est les meme ep alors je dis qu il est apres !
    if(_num.numSaison < n2.getNumSasion()) return true;
    else if(_num.numSaison > n2.getNumSasion()) return false;
    if(_num.numEpisode < n2.getNumEpisode()) return true;
    else return false;
}
