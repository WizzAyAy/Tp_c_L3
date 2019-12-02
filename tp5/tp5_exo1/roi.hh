#pragma once
#include "piece.hh"
#include <vector>

class roi : public piece
{
public:
    roi(const couleur &c, const position &p);
    std::unique_ptr<piece> clone() const override {
        return std::make_unique<roi>(*this);
    }
    std::vector<position> deplacementspossibles() const;
    int getValeur()const override{return 20;}
    std::string getSymbol()const{return "R";}
private:
};
