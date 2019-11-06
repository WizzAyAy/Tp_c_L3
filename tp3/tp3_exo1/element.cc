#include "element.hh"
#include "position.hh"
#include "taille.hh"

element::element(position pos, taille t)
    :_pos(pos), _t(t){
}

std::string element::toString() const{
    std::string S("");
    S += _pos.toString();
    S += " ";
    S += _t.toString();
    return S;
}

bool element::contientPosition(position const &pos)const{
    //la pos doit etre dans le this;
    //pos = x et y
    //pos._x compris entre this._pox._x et this._pox._x + largeur;
    //pos.y compris entre this._pox._y et this._pox._y + hauteur;

    if (pos.getX() >= _pos.getX() && pos.getX() <= _pos.getX() + _t.getLargeur() ){
        if (pos.getY() >= _pos.getY() && pos.getY() <= _pos.getY() + _t.getHauteur() ){
            return true;
        }
    }
    return false;
}
