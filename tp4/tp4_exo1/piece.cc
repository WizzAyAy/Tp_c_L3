#include "piece.hh"
#include <algorithm>

piece::piece(const couleur &c, const position &p)
    :_c(c), _p(p){

}

std::string piece::toString() const
{
    std::string s = "";
    if(_c == couleur::B)
        s += "B";
    if(_c == couleur::N)
        s +="N";
    return s;
    //avec les methodes symbole et valeur on aurait pu les appele la methode ici aussi !!!!!!!!!
}

bool piece::accepterposition(const position &p) const{
    auto dp(deplacementspossibles());
    return std::find(dp.begin(), dp.end(), p) != dp.end();
}

bool piece::deplacer(const position &p){
    if(accepterposition(p)){
        _p = p;
        return true;
    }
    return false;
}
