#include "carte.hh"
#include <iostream>

carte::carte(taille t)
    :_taille(t),_origine(0,0){

}

void carte::affichage() const{

    std::cout << "la carte ----> \n";
    std::cout << _origine.toString()<< "\n";
    std::cout << _taille.toString()<< "\n";
      std::cout << "\n";
    std::cout << "la carte est composé des objets ----> \n";
    for(auto i : _listeObjet) std::cout << "obj->" << i.toString() << "\n";
      std::cout << "\n";
    std::cout << "la carte est composé des personage ----> \n";
    for(auto i : _listePerso) std::cout << "perso->" << i.toString() << "\n";
      std::cout << "\n";
    std::cout << "la carte est composé des obstacle ----> \n";
    for(auto i : _listeObstacle) std::cout << "obstacle->" << i.toString()<< "\n";
    std::cout << "\n";
}

bool carte::intervalleIntEnCommun(int min1, int max1, int min2, int max2){
    if(max1 > max2){
        if(max2 < min1) return true;
    }
    else {
        if(max1 < min1) return true;
    }
    return false;
}

bool carte::intersectionEnCommun(element const &e1, element const &e2){
    int x1 = e1.getPos().getX()+e1.getTaille().getLargeur();
    int y1 = e1.getPos().getY()+e1.getTaille().getHauteur();

    int x2 = e2.getPos().getX()+e2.getTaille().getLargeur();
    int y2 = e2.getPos().getY()+e2.getTaille().getHauteur();

    if(intervalleIntEnCommun(e1.getPos().getX(),x1,e2.getPos().getX(),x2)&&
            intervalleIntEnCommun(e2.getPos().getY(),y1,e2.getPos().getY(),y2)){
        return true;
    }
    else return false;
}

bool carte::peutBouger(const personnage &p, int direction){
    //0 = nord
    //1 = est
    //2 = sud
    //3 = ouest
    int X,Y;
    if (direction == 0){
        Y = -1;
        X = 0;
    }
    else if (direction == 1){
        Y = 0;
        X = 1;
    }
    else if (direction == 2){
        Y = 1;
        X = 0;
    }
    else if (direction == 3){
        Y = 0;
        X = -1;
    }
    else {
        std::cout << "MAUVAISE DIRECTION VOTRE DIRECTION DOIT ETRE ENTRE 0 ET 3";
        return false;
    }
    //pour la limite de la carte !
    if(intervalleIntEnCommun(0,_taille.getLargeur(),p.getPos().getX(),p.getTaille().getLargeur()+p.getPos().getX())&&
            intervalleIntEnCommun(0,_taille.getHauteur(),p.getPos().getY(),p.getPos().getY()+p.getTaille().getHauteur())){
            return false;
        }

    //pour les obstacles



    return true;
}
