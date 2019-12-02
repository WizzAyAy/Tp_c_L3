#include "dame.hh"

dame::dame(const couleur &c, const position &p)
    :piece(c,p){

}


std::vector<position> dame::deplacementspossibles() const
{
    std::vector<position> lespos;
    position temp = getPosition();
    for(int i = 1; i < 8; i++){
        for(int a : {-1,0,1}){
            for(int b : {-1,0,1})
                if(a == 0 && b == 0) break;
                else {
                    position p(temp.getLigne()+i*a, temp.getColonne()+i*b);
                    if(p.estvalide()) lespos.push_back(p);
                }
        }
    }
    return lespos;
}


