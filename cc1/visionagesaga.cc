#include "visionagesaga.hh"

visionagesaga::visionagesaga(unsigned int date, std::string nom, std::string nomReal, std::string nonSaga, unsigned int lastvue)
    :visionagefilm(date,nom,nomReal), _nomSaga(nonSaga),_dernierFilmSaga(lastvue){
}

std::string visionagesaga::toString() const
{
    std::string s = visionagefilm::toString();
    s += "(";
    s += _nomSaga;
    s += " ";
    std::string last = std::to_string(_dernierFilmSaga);
    s += last;
    s += ")\n";
    return s;
}

bool visionagesaga::contientnumero(const unsigned int &a) const
{
    if (a == _dernierFilmSaga) return true;
    return false;
}
visionage* visionagesaga::clone()const{
    return new visionagesaga(*this);
}

