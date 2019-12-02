#pragma once
#include "document.hh"


enum class typeSupport
{
    DVD,
    BluRay,
    BluRay3D
};

class video : public document
{
public:
    video(std::string const & t, std::string const & a, typeSupport const & s);
    bool peutEtreEmprunt()const {return true;}
    float coutPerte()const {return 70;}
    typeSupport getType()const {return _support;}
    document * clone() const override {return new video(*this);}
    void sortieflux(std::ostream & os)const;
    std::string getTypedoc() const {return "VIDEO";}
private:
    typeSupport _support;
};

std::ostream & operator<<(std::ostream & os, video const & v);

