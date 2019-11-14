#include "visionage.hh"

visionage::visionage(unsigned int date, std::string nom)
    : _dateVisonage(date), _nom(nom){

}

std::string visionage::toString() const
{
    std::string date = std::to_string(_dateVisonage);
    std::string s = date;
    s += " ";
    s += typevisionnage();
    s += " ";
    s += _nom;
    s += " ";
    return s;

}
