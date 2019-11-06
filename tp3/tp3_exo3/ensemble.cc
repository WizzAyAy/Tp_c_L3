#include "ensemble.hh"
#include <iostream>

ensemble::ensemble(){
  //  std::cout << "construction  \n";
}

void ensemble::ajouter(int nb){
    if(!appartient(nb))
        ajoutersansverif(nb);
}

void ensemble::afficherParcours()
{
    for (parcours p = commencer(); !estfini(p); suivant(p)){
        std::cout << acces(p) << " ";
    }
    std::cout << "\n";
}

parcours ensemble::commencer() const{
    parcours p;
    return p;
}

void ensemble::suivant(parcours &p) const
{
    p.suivant();
}

void ensemble::unionavec(const ensemble &e2){
    for(parcours p = e2.commencer(); !e2.estfini(p); e2.suivant(p)){
        ajouter(e2.acces(p));
    }
}

//void ensemble::interavec(const ensemble &e2){
// cette boucle ne va jamais rien faire !
//    for(parcours p = e2.commencer(); !e2.estfini(p); e2.suivant(p)){
//        if(!appartient(e2.acces(p))) enlever(e2.acces(p));
//    }
//    for(parcours p = commencer(); !estfini(p); suivant(p)){
//        if(!e2.appartient(acces(p))) enlever(acces(p));
//    }
//}

void ensemble::diffavec(const ensemble &e2){
    for(parcours p = e2.commencer(); !e2.estfini(p); e2.suivant(p)){
        if(appartient(e2.acces(p))) enlever(e2.acces(p));
    }
}

void ensemble::calculerunion(const ensemble &e1, const ensemble &e2){
    vider();
    for(parcours p = e1.commencer(); !e1.estfini(p); e1.suivant(p)){
    ajouter(e1.acces(p));
    }
    for(parcours p = e2.commencer(); !e2.estfini(p); e2.suivant(p)){
    ajouter(e2.acces(p));
    }
}

void ensemble::calculerinter(const ensemble &e1, const ensemble &e2){
    vider();

    for(parcours p = e1.commencer(); !e1.estfini(p); e1.suivant(p)){
    if(e2.appartient(e1.acces(p))) ajouter(e1.acces(p));
    }


}

void ensemble::calculerdiff(const ensemble &e1, const ensemble &e2){
    vider();
    for(parcours p = e1.commencer(); !e1.estfini(p); e1.suivant(p)){
    if(!e2.appartient(e1.acces(p))) ajouter(e1.acces(p));
    }

}


