#pragma once
#include "visionagefilm.hh"

class visionagesaga : public visionagefilm
{
public:
    visionagesaga(unsigned int date, std::string nom, std::string nomReal, std::string nonSaga, unsigned int lastvue);

    std::string getNomSaga()const {return _nomSaga;}
    unsigned int getDernierFilmSaga()const {return _dernierFilmSaga;}
    std::string toString() const;
    bool contientnumero(const unsigned int &a) const;
    visionage *clone()const;
private:
    std::string _nomSaga;
    unsigned int _dernierFilmSaga;
};

