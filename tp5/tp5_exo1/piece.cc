#include "piece.hh"
#include <algorithm>

piece::piece(const couleur &c, const position &p)
    :_c(c), _p(p){

}

std::string piece::toString() const{
    std::string s = getSymbol();
    if(_c == couleur::B)
        s += "B";
    if(_c == couleur::N)
        s +="N";
    std::string L = std::to_string(getPosition().getLigne());
    std::string C = std::to_string(getPosition().getColonne());
    s += L + C;
    return s;
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

std::ostream &operator<<(std::ostream &os, const piece &p){
    os << p.getSymbol();
    if(p.getCouleur() ==  couleur::B)
        os << "B";
    else
        os << "N";
    return os;
}
