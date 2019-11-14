#include <iostream>
#include "numepisode.hh"
#include "visionage.hh"
#include "visionagefilm.hh"
#include "visionagesaga.hh"
#include "ensemblevisioanage.hh"
#include "visionageserie.hh"

using namespace std;



int main()
{
    numepisode n1(1,4);
    visionageSerie serie(270298, "Game of thrones", n1);
    visionagefilm film(123012,"Yes man","Peyton Reed");
    visionagefilm film2(181202,"je suis 2018", "quentinMaignan");
    visionagesaga saga3(101010,"the return of the king", "Peter Jackson", "lord of the ring", 3);
    visionagesaga saga2(101010,"les deux tours", "Peter Jackson", "lord of the ring", 2);
    visionagesaga saga1(101010,"la communauté de l'anneau", "Peter Jackson", "lord of the ring", 1);
    visionagesaga sagab(101010,"la communauté de l'anneau", "Peter Jackson", "harry potter", 1);

    ensemblevisioanage ens;
    ens.ajoutervisionage(serie);
    ens.ajoutervisionage(saga1);
    ens.ajoutervisionage(saga2);
    ens.ajoutervisionage(saga3);
    ens.ajoutervisionage(sagab);
    ens.ajoutervisionage(film);
    ens.ajoutervisionage(film2);

    ens.afficherlesvisionage();

    std::cout << ens.nombredesaga() << "\n";


    return 0;
}
