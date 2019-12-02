#include "roi.hh"


roi::roi(const couleur &c, const position &p)
    :piece(c,p), _symbol("D"), _valeur(9){

}

std::string roi::toString() const
{
    std::string s = "R";
    s += piece::toString();
    std::string L = std::to_string(getPosition().getLigne());
    std::string C = std::to_string(getPosition().getColonne());
    s += L;
    s += C;
    s += "\n";
    return s;
}

std::vector<position> roi::deplacementspossibles() const
{
    std::vector<position> lespos;
    position temp = getPosition();
    for(int i = -1; i < 2; i++){
        for(int j = -1; j < 2; j++){
            if(!(i == 0 && j == 0)){
                temp.setLigne(temp.getLigne()+i);
                temp.setColonne(temp.getColonne()+j);
                if(temp.estvalide()) lespos.push_back(temp);
                temp = getPosition();
            }
        }
    }
    return lespos;
}
