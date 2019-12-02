#pragma once
#include "documentmanuscrit.hh"

class periodique : public documentManuscrit
{
public:
    periodique(std::string const & t, std::string const & a, unsigned int pages, unsigned int num);
    bool peutEtreEmprunt() const {return false;}
    unsigned int getNum()const{return _numero;}
    document * clone() const override {return new periodique(*this);}
    void sortieflux(std::ostream &os) const;
    std::string getTypedoc() const {return "PERIODIQUE";}
private:
    unsigned int _numero;
};

std::ostream & operator<<(std::ostream & os, periodique const & p);

