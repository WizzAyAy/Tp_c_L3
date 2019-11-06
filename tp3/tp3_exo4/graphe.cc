#include "graphe.hh"
#include "sommet.hh"
#include <iostream>

graphe::graphe(){   
}

identificateur graphe::ajoutersommet(std::string etiquette){
    sommet temp (etiquette);
    _lesSommets.push_back(temp);
    return temp.getId();
}

bool graphe::ajouterarc(identificateur origine, identificateur destination, std::string etiquette){

    arcSortant arc {etiquette, destination};

    bool oriBool = false;
    bool destiBool = false;

    auto origineIter = _lesSommets.begin();

    for (auto it = _lesSommets.begin(); it != _lesSommets.end(); it++) {
        if(it->getId() == origine){
            origineIter = it;
            oriBool = true;
        }
        if(it->getId() == destination) {
            destiBool = true;
        }

        if (oriBool && destiBool) {
            origineIter->ajouterArcSortant(arc);
            return true;
        }
    }

    return false;
}

void graphe::supprimersommet(identificateur id){

    auto sommetAsup = _lesSommets.begin();
    for(auto it = _lesSommets.begin(); it != _lesSommets.end(); it++){
        if (it->getId() == id) sommetAsup = it;
    }
    //tous les arcs sortant !
    sommetAsup->supprimeTousArc();

    //tous les arcs entrant !
    for(auto it = _lesSommets.begin(); it != _lesSommets.end(); it++){
        it->supprimeArc(id);
    }
    _lesSommets.erase(sommetAsup);

}

void graphe::dot_sortie(std::ostream &os) const{
    os << "digraph G {\n";
    for(auto it = _lesSommets.begin(); it != _lesSommets.end(); it++){
        it->dot_etiquette(os);
        it->dot_arcsortant(os);
    }
    os << "}\n";
}
