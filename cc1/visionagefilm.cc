#include "visionagefilm.hh"
#include "visionage.hh"

visionagefilm::visionagefilm(unsigned int date, std::string nom, std::string nomReal)
    :visionage(date,nom), _nomReal(nomReal){

}

std::string visionagefilm::toString() const{
    std::string s = visionage::toString();
    s += " - ";
    s += _nomReal;
    s += "\n";
    return s;

}

visionage* visionagefilm::clone()const{
    return new visionagefilm(*this);
}

