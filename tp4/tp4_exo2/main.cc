#include <iostream>
#include "livre.hh"
#include "video.hh"
#include "periodique.hh"
#include "bibliotheque.hh"

using namespace std;

int main()
{
    livre l("je suis un titre", "BERNARD LEVIS", 500,1);
    periodique p("je sui un magasine","GALA", 90, 22);
    video v("je suis un film", "spilberg", typeSupport::DVD);

    bibliotheque b;
    b.ajouterDoc(l);
    b.ajouterDoc(p);
    b.ajouterDoc(v);
    b.afficher();
    std::cout << std::endl;

    bibliotheque bcopie(b);
    bcopie.afficher();
    bcopie.ajouterDoc(livre("titre copier", "ici", 500, 0));

    std::cout << std::endl;
    b.afficher();
    std::cout << std::endl;
    bcopie.afficher();

    std::cout << b.nombreVideoType(typeSupport::DVD) << std::endl;

    return 0;
}
