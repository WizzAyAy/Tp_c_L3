#include <iostream>
#include "position.hh"
#include "pion.hh"
#include "cavalier.hh"
#include "dame.hh"
#include "roi.hh"
#include <vector>

using namespace std;

int main()
{
    position p(2,4);
    pion p1(couleur::N,p);
    cavalier c1(couleur::N,p);
    dame d1(couleur::B,p);
    roi r1(couleur::B,p);


    std::cout << p1.toString();
    std::vector<position> lespospions = p1.deplacementspossibles();
    for( auto i : lespospions ){
        std::cout << i<< std::endl;
    }
    std::cout << std::endl;


    std::cout << r1.toString();
    std::vector<position> lesposroi = r1.deplacementspossibles();
    for( auto i : lesposroi ){
        std::cout << i << std::endl;
    }
    std::cout << std::endl;


    std::cout << c1.toString();
    std::vector<position> lesposcavalier = c1.deplacementspossibles();
    for( auto i : lesposcavalier ){
        std::cout << i << std::endl;
    }
    std::cout << std::endl;

    std::cout << d1.toString();
    std::vector<position> lesposreine = d1.deplacementspossibles();
    for( auto i : lesposreine ){
        std::cout << i << std::endl;
    }
    std::cout << std::endl;

    position arrive(7,1);
    d1.deplacer(arrive);
    std::cout << d1.toString();
    position fake(5,4);
    d1.deplacer(fake);
    std::cout << d1.toString();
    return 0;
}
