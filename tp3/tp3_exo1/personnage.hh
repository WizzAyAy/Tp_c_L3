#pragma once
#include "taille.hh"
#include "position.hh"
#include "element.hh"
#include <string>
#include "objetramassage.hh"

class personnage : public element
{
public:
    personnage(position pos, taille t, std::string nom);
//    int getvelX() const {return _velX;}
//    int getvelY() const {return _velY;}
//    void setvelX(int velX){_velX = velX;}
//    void setvelY(int velY){_velY = velY;}
//    void updatePos();
    std::string const & getNom(){return _nom;}
    std::string toString()const;
    void ramasserObjet(objetRamassage &obj);

private:
    std::string _nom;
//    int _velX;
//    int _velY;
    int _nbCoins;
};

