#pragma once
#include "piece.hh"
#include <vector>


class pion : public piece
{
public:
    pion(const couleur &c, const position &p);

    std::unique_ptr<piece> clone() const override {
        return std::make_unique<pion>(*this);
    }

    std::vector<position> deplacementspossibles() const;
    int getValeur()const override{return 1;}
    std::string getSymbol()const{return "P";}
private:
    bool _dejaDeplace;

};
