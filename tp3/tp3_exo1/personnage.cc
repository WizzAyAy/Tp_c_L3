#include "personnage.hh"
#include <string>
#include <iostream>

personnage::personnage(position pos, taille t, std::string nom)
    : element(pos,t), _nom(nom), _nbCoins(0){

}

//void personnage::updatePos(){
//    int newX = this->getPos().getX() + _velX;
//    int newY = this->getPos().getY() + _velY;
//    position posTemp(newX,newY);
//    this->setPos(posTemp);
//}

std::string personnage::toString()const{
    std::string S;
    std::string x = std::to_string(_nbCoins);
    S = "nom(";
    S += _nom;
    S += ") ";
    S += "piece(";
    S += x;
    S += ") ";
    S += element::toString();
    return S;
}

void personnage::ramasserObjet(objetRamassage &obj){
    if(contientPosition(obj.getPos())){
        std::cout << "votre personnage a pris l'obj et prend " << obj.getNbPoints() << " points\n\n";
        _nbCoins += obj.getNbPoints();
        obj.setNbpoints(0);
        //delete obj on att un pointeur sur l'obj

    }
    else std::cout << "votre personnage est trop loin de l'obj a rammasser \n\n";
}
