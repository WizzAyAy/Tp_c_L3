#include <iostream>
#include "point.hh"
#include "segment.hh"
#include "triangle.hh"
#include "rectangle.hh"

using namespace std;

int main()
{
    rectangle rec(couleur::bleu, point(0,0), point(-32,32));
    rec.afficher();
    if (rec.estCarre()) std::cout << "c'est bien un carré !!! \n";
    return 0;
}
