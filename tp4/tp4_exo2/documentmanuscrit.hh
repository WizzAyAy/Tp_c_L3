#pragma once
#include "document.hh"

class documentManuscrit : public document
{
public:
    documentManuscrit(std::string const & t, std::string const & a, unsigned int page);
    float coutPerte() const {return 0.5 * _nbpages;}
    unsigned int getnbPages()const{return _nbpages;}
    void sortieflux(std::ostream &os) const;
private:
    unsigned int _nbpages;
};

std::ostream & operator<<(std::ostream & os, documentManuscrit const & d);
