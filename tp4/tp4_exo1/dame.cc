#include "dame.hh"

dame::dame(const couleur &c, const position &p)
    :piece(c,p), _symbol("D"), _valeur(9){

}

std::string dame::toString() const
{
    std::string s = "D";
    s += piece::toString();
    std::string L = std::to_string(getPosition().getLigne());
    std::string C = std::to_string(getPosition().getColonne());
    s += L;
    s += C;
    s += "\n";
    return s;
}

std::vector<position> dame::deplacementspossibles() const
{
    std::vector<position> lespos;
    position temp = getPosition();
//    for(int i = 1; i < 8; i++){
//        position p(temp.getLigne()-i, temp.getColonne()-i);
//        if(p.estvalide())
//            lespos.push_back(p);
//        position p1(temp.getLigne()-i, temp.getColonne());
//        if(p1.estvalide())
//            lespos.push_back(p1);
//        position p2(temp.getLigne(), temp.getColonne()-i);
//        if(p2.estvalide())
//            lespos.push_back(p2);
//        position p3(temp.getLigne()+i, temp.getColonne()+i);
//        if(p3.estvalide())
//            lespos.push_back(p3);
//        position p4(temp.getLigne()+i, temp.getColonne());
//        if(p4.estvalide())
//            lespos.push_back(p4);
//        position p5(temp.getLigne(), temp.getColonne()+i);
//        if(p5.estvalide())
//            lespos.push_back(p5);
//        position p6(temp.getLigne()+i, temp.getColonne()-i);
//        if(p6.estvalide())
//            lespos.push_back(p6);
//        position p7(temp.getLigne()-i, temp.getColonne()+i);
//        if(p7.estvalide())
//            lespos.push_back(p7);

//    }
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
