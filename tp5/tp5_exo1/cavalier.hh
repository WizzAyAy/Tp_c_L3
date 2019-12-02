#pragma once
#include "piece.hh"
#include <vector>

class cavalier : public piece
{
public:
    cavalier(const couleur &c, const position &p);
    std::unique_ptr<piece> clone() const override {
        return std::make_unique<cavalier>(*this);
    }
    std::vector<position> deplacementspossibles() const;
    int getValeur()const override{return 3;}
    std::string getSymbol()const{return "C";}
private:
};
