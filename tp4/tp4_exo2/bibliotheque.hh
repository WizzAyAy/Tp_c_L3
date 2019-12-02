#pragma once
#include "document.hh"
#include "video.hh"
#include <vector>


class bibliotheque
{
public:
    bibliotheque()=default;
    virtual ~bibliotheque();
    bibliotheque(bibliotheque const & b);
    void ajouterDoc(document const & d){_lesdocs.push_back(d.clone());}
    std::size_t taille()const {return _lesdocs.size();}
    document const & acces(std::size_t i )const {return *(_lesdocs.at(i));}

    void afficher()const;

    int nombreVideoType(typeSupport const & s)const;
private:
    std::vector<document *> _lesdocs;
};

