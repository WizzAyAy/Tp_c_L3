#pragma once
#include "piece.hh"
#include <vector>

class dame : public piece
{
public:
    dame(const couleur &c, const position &p);
    std::unique_ptr<piece> clone() const override {
        return std::make_unique<dame>(*this);
    }
    std::vector<position> deplacementspossibles() const;
    int getValeur()const override{return 9;}
    std::string getSymbol()const{return "D";}
private:
};

