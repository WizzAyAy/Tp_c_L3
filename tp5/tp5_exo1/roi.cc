#include "roi.hh"


roi::roi(const couleur &c, const position &p)
    :piece(c,p){

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
