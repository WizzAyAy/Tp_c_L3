#include "sommet.hh"
#include <iostream>

identificateur sommet::compteur(1);

sommet::sommet(std::string etiquette)
    :_id(sommet::compteur++), _etiquette(etiquette){
}

void sommet::ajouterSommet(identificateur idExter, std::string eti){

    for (auto arc : _arcSortant) {
        if(arc.id == idExter){
            arc.etiquette = eti;
        }
        return;
    }

    arcSortant temp;
    temp.etiquette = eti;
    temp.id = idExter;
    _arcSortant.push_back(temp);
}

void sommet::supprimeArc(identificateur id){
    for (auto it = _arcSortant.begin(); it != _arcSortant.end(); it++) {
            if(it->id == id){
                _arcSortant.erase(it);
                --it;
            }
    }
}

void sommet::supprimeTousArc(){
    _arcSortant.clear();
}

void sommet::dot_etiquette(std::ostream &os) const{
    os << "c" << _id << " [label=\"" << _etiquette << "\"]\n";
}

void sommet::dot_arcsortant(std::ostream &os) const{


    for (auto it = _arcSortant.begin(); it != _arcSortant.end(); it++) {

        os << "c" << _id << "-> c" << it->id << " [label=\"" << it->etiquette << "\"]\n";
    }
}

void sommet::ajouterArcSortant(arcSortant arc){
    _arcSortant.push_back(arc);
}

