#pragma once
#include "visionage.hh"
#include <string>

class visionagefilm : public visionage
{
public:
    visionagefilm(unsigned int date, std::string nom, std::string nomReal);
    std::string getNomReal()const {return _nomReal;}
    std::string typevisionnage() const {return "Film";}
    std::string toString ()const;
    visionage* clone()const;
    bool contientnumero(const unsigned int &a) const override{return false;}
private:
    std::string _nomReal;
};

