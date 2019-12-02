#pragma once
#include <iostream>

using coordornee = unsigned int;

class position
{
public:
    position(coordornee const &ligne, coordornee const &colonne);
    position(position const & pos);
    coordornee getLigne()const {return _ligne;}
    coordornee getColonne()const {return _colonne;}
    void setLigne(coordornee const &x){_ligne = x;}
    position & operator =(position const & p) =default;
    void setColonne(coordornee const &x){_colonne = x;}
    bool operator==(position const &p)const;
    bool operator!=(position const &p)const;
    void sortie(std::ostream &os)const;
    bool estvalide()const;

private:
    coordornee _ligne;
    coordornee _colonne;
};

std::ostream & operator<<(std::ostream & os, position const & p);
