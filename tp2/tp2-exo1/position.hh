#pragma once


using coordonnee = int;

class position
{
public:
    position(coordonnee x, coordonnee y);
    position(const position & pos);

    coordonnee getX() {
        return _x ;
    }
    coordonnee getY() {
        return _y ;
    }

    void setX (coordonnee x) {
        _x = x;
    }
    void setY (coordonnee y) {
        _y = y;
    }

    bool compare (position pos);
    void affiche ();


private:
    coordonnee _x, _y;

};


