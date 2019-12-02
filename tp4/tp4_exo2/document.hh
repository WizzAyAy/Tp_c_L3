#pragma once
#include <string>


class document
{
public:
    document(std::string const & t, std::string const & a);
    virtual ~document() =default;
    virtual document * clone() const =0;

    virtual bool peutEtreEmprunt()const=0;
    virtual float coutPerte()const=0;

    std::string getTitre()const{return _titre;}
    std::string getNomAuteur()const{return _nomAuteur;}

    virtual void sortieflux(std::ostream & os)const;
    virtual std::string getTypedoc()const=0;
private:
    std::string _titre;
    std::string _nomAuteur;
};

std::ostream & operator<<(std::ostream & os, document const & d);
