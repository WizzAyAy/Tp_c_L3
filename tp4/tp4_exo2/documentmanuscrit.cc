#include "documentmanuscrit.hh"
#include <iostream>

documentManuscrit::documentManuscrit(const std::string &t, const std::string &a, unsigned int page)
    :document(t,a), _nbpages(page){}

void documentManuscrit::documentManuscrit::sortieflux(std::ostream &os) const
{
    document::sortieflux(os);
    os << " " << _nbpages << "p ";
}
