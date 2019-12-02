#include <iostream>
#include "position.hh"
#include "pion.hh"
#include "cavalier.hh"
#include "dame.hh"
#include "roi.hh"
#include "echiquier.hh"
#include <vector>
#include <fstream>

using namespace std;

int main()
{

    std::ofstream ofsteam;
    std::ifstream ifstream;
    echiquier e;
    e.depart();
    e.jouer();
    e.sauvegarder(ofsteam);

    return 0;
}
