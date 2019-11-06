#include <iostream>
#include "ensemble.hh"
#include "ensembletableaux.hh"
#include "ensemblevector.hh"


void testfonction(ensemble & e1, ensemble & e2 ){//2
    std::cout << "err resAtt->resObtenu\n";
    std::cout << "1   1->" << e1.appartient(5) << "\n";
    std::cout << "2   0->" << e1.estVide() << "\n";
    std::cout << "3   1->" << e1.appartient(5) << "\n";
    std::cout << "3.1 0->" << e1.appartient(6) << "\n";
    std::cout << "4   1->" << e2.appartient(5) << "\n";
    std::cout << "4.1 0->" << e2.appartient(3) << "\n";

    std::cout << "5a 5 2-> "; e1.afficher();
    std::cout << "5b 5 2-> ";
    for (parcours p = e1.commencer(); !e1.estfini(p) ;e1.suivant(p) ){
        std::cout << e1.acces(p) << " ";
    }
    std::cout << "\n";
    std::cout << "5c 5 2-> ";e1.afficherParcours();
    std::cout << "5c 5 2-> ";e2.afficherParcours();

    ensemblevector e3;
    e1.ajouter(3);
    e3.calculerunion(e1,e2);

    std::cout << "6 5 2 3 -> ";e3.afficherParcours();

    e3.calculerinter(e1,e2);
    std::cout << "7 5 2 -> ";e3.afficherParcours();

    e3.calculerdiff(e1,e2);
    std::cout << "8 3 -> ";e3.afficherParcours();


}


int main(){
    std::cout << "----- ensemble Vector -----\n";
    ensemblevector ensvec;
    ensvec.ajouter(5);
    ensvec.ajouter(2);
    ensvec.ajouter(10);
    ensvec.ajouter(10);
    ensvec.afficher();

    ensvec.enlever(10);
    ensvec.afficher();


    std::cout << "----- ensemble tableau (pointeur) -----\n";

    ensembletableaux enstab;
    enstab.ajouter(5);
    enstab.ajouter(2);
    enstab.ajouter(10);
    enstab.ajouter(10);
    enstab.afficher();

    enstab.enlever(10);
    enstab.afficher();



    std::cout << "----- comparaison des ensemebles ----- \n";
    testfonction(ensvec,enstab);
    return 0;
}
