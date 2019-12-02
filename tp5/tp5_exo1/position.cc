#include "position.hh"
#include <iostream>


position::position(const coordornee &ligne, const coordornee &colonne)
    :_ligne(ligne), _colonne(colonne){

}

position::position(const position &pos)
    :_ligne(pos.getLigne()), _colonne(pos.getColonne()){

}

bool position::operator==(const position &p) const
{
    return(_colonne == p.getColonne() && _ligne == p.getLigne());
}

bool position::operator!=(const position &p) const
{
    return(_colonne != p.getColonne() || _ligne != p.getLigne());
    //ou return !operator==(p);
}

void position::sortie(std::ostream &os) const
{
    os << "position[" << _ligne << "," << _colonne << "] ";
}

std::ostream & operator<<(std::ostream & os, position const & p) {
    os << "position (" << p.getLigne() << "," << p.getColonne() << ")";
    return os;
}

bool position::estvalide() const
{
    return ((_colonne < 8 && _colonne >= 0) && (_ligne < 8 && _ligne >= 0));
}
