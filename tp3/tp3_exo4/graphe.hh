#pragma once
#include <list>
#include <string>
#include <iostream>
#include "sommet.hh"

class graphe
{
    //ajouter arc et suppr sommet sont faux !
public:
    graphe();
    identificateur ajoutersommet(std::string etiquette);
    bool ajouterarc(identificateur origine, identificateur destination, std::string etiquette);
    void supprimersommet(identificateur id);
    void dot_sortie(std::ostream &os) const;

private:
    std::list<sommet> _lesSommets;
};
