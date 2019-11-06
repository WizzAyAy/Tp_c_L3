#pragma once
#include <string>
#include <list>

using identificateur = unsigned int;

struct arcSortant
{
    std::string etiquette;
    identificateur id;
};


class sommet
{
public:
    sommet(std::string etiquette);
    std::string const getEtiquette(){return _etiquette;}
    identificateur getId(){return _id;}
    std::list<arcSortant> const & getArcSortant() const {return _arcSortant;}
    void ajouterSommet(identificateur idExter, std::string eti);
    void supprimeArc(identificateur id);
    void supprimeTousArc();
    void dot_etiquette(std::ostream &os) const;
    void dot_arcsortant(std::ostream &os) const;
    void ajouterArcSortant(arcSortant arc);

private:
    identificateur _id;
    std::string _etiquette;
    std::list<arcSortant> _arcSortant;
    static identificateur compteur;
};
