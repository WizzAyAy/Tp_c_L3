#pragma once
#include "documentmanuscrit.hh"

class livre : public documentManuscrit
{
public:
    livre(std::string const & t, std::string const & a, unsigned int pages, bool emprunt);
    bool peutEtreEmprunt() const {return _empruntable;}
    document * clone() const override {return new livre(*this);}
    std::string getTypedoc() const {return "LIVRE";}
private:
    bool _empruntable;
};

std::ostream & operator<<(std::ostream & os, livre const & l);


