#include "pion.hh"
#include <vector>

pion::pion(const couleur &c, const position &p)
    :piece(c,p), _symbol("P"), _valeur(1), _dejaDeplace(false){

}

std::string pion::toString() const
{
    std::string s = "P";
    s += piece::toString();
    std::string L = std::to_string(getPosition().getLigne());
    std::string C = std::to_string(getPosition().getColonne());
    s += L;
    s += C;
    s += "\n";
    return s;
}

std::vector<position> pion::deplacementspossibles() const
{
    std::vector<position> lespos;
    position temp = getPosition();

    //blanc = vers le haut ! donc y - 1
    if(getCouleur() == couleur::B){
        temp.setLigne(temp.getLigne() - 1);
        if (temp.estvalide()) lespos.push_back(temp);
        if(!_dejaDeplace){
            temp.setLigne(temp.getLigne() - 1);
            if (temp.estvalide()) lespos.push_back(temp);
        }
    }
    //noir = vers le bas !  donc y + 1
    if(getCouleur() == couleur::N){
        temp.setLigne(temp.getLigne() + 1);
        if (temp.estvalide()) lespos.push_back(temp);
        if(!_dejaDeplace){
            temp.setLigne(temp.getLigne() + 1);
            if (temp.estvalide()) lespos.push_back(temp);
        }
    }
    return lespos;
}
