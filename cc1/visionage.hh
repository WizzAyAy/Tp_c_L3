#pragma once
#include <string>

class visionage
{
public:
    visionage(unsigned int date, std::string nom);
    virtual ~visionage() =default;
    unsigned int getDateVisonage()const {return _dateVisonage;}
    std::string getNom()const {return _nom;}
    virtual std::string typevisionnage()const =0;
    virtual std::string toString()const;
    virtual visionage * clone() const =0;
    virtual bool contientnumero(unsigned int const &a)const =0;

private:
    unsigned int _dateVisonage;
    std::string _nom;

};

