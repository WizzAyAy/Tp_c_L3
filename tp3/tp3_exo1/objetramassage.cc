#include "objetramassage.hh"
#include <string>

objetRamassage::objetRamassage(position pos, taille t, int nbPoints)
    :element(pos,t), _nbPoints(nbPoints) {}

std::string objetRamassage::toString()const {
    std::string S;
    std::string x = std::to_string(_nbPoints);
    S = "nbPoints(";
    S += x;
    S += ") ";
    S += element::toString();

    return S;
}

