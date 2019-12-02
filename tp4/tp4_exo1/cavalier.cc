#include "cavalier.hh"

cavalier::cavalier(const couleur &c, const position &p)
    :piece(c,p), _symbol("P"), _valeur(4){

}

std::string cavalier::toString()const{
    std::string s = "C";
    s += piece::toString();
    std::string L = std::to_string(getPosition().getLigne());
    std::string C = std::to_string(getPosition().getColonne());
    s += L;
    s += C;
    s += "\n";
    return s;
}

std::vector<position> cavalier::deplacementspossibles() const
{
        std::vector<position> res;
        auto posactuelle = getPosition();

        for(auto a : {-2, 2}){
            for(auto b : {-1, 1}){
                position p(posactuelle.getColonne()+a, posactuelle.getLigne()+b);
                if (p.estvalide()){
                    res.push_back(p);
                }
            }
        }
        for(auto a : {-2, 2}){
            for(auto b : {-1, 1}){
                position p(posactuelle.getColonne()+b, posactuelle.getLigne()+a);
                if (p.estvalide()){
                    res.push_back(p);
                }
            }
        }

        return res;
//        position temp = getPosition();

//        //les deux du haut
//        temp.setLigne(temp.getLigne() - 2);
//        temp.setColonne(temp.getColonne() - 1);
//        lespos.push_back(temp);
//        temp.setColonne(temp.getColonne() + 2);
//        lespos.push_back(temp);


//        temp = getPosition();
//        //les deux de gauche
//        temp.setColonne(temp.getColonne() - 2);
//        temp.setLigne(temp.getLigne() - 1);
//        lespos.push_back(temp);
//        temp.setLigne(temp.getLigne() + 2);
//        lespos.push_back(temp);


//        temp = getPosition();
//        //les deux de droite
//        temp.setColonne(temp.getColonne() + 2);
//        temp.setLigne(temp.getLigne() - 1);
//        lespos.push_back(temp);
//        temp.setLigne(temp.getLigne() + 2);
//        lespos.push_back(temp);


//        temp = getPosition();
//        //les deux du bas
//        temp.setLigne(temp.getLigne() + 2);
//        temp.setColonne(temp.getColonne() - 1);
//        lespos.push_back(temp);
//        temp.setColonne(temp.getColonne() + 2);
//        lespos.push_back(temp);


}
