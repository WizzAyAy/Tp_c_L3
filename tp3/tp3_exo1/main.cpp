#include <iostream>
#include <random>
#include "position.hh"
#include "taille.hh"
#include "element.hh"
#include "obstacle.hh"
#include "personnage.hh"
#include "objetramassage.hh"
#include "carte.hh"



std::string random_string(std::string::size_type length)
{
    static auto& chrs = "0123456789"
        "abcdefghijklmnopqrstuvwxyz"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    thread_local static std::mt19937 rg{std::random_device{}()};
    thread_local static std::uniform_int_distribution<std::string::size_type> pick(0, sizeof(chrs) - 2);

    std::string s;

    s.reserve(length);

    while(length--)
        s += chrs[pick(rg)];

    return s;
}

int main(){
    position pos(12,12);
    taille t(1,1);

    personnage p(pos,t,"Da King");
    carte c(taille(50,50));

//    for(int i = 0; i < 10; i++){
//        c.ajouterObjet(objetRamassage(
//    position(random()%10, random()%10),
//    taille(random()%3+1, random()%3+1),
//    random()%50 ));
//    }

//    for(int i = 0; i < 10; i++){
//        c.ajouterObstacle(obstacle(
//    position(random()%10, random()%10),
//    taille(random()%3+1, random()%3+1)));
//    }

//    for(int i = 0; i < 1; i++){
//        std::string temp = random_string(random()%5+5);
//        c.ajouterPersonnage(personnage(
//    position(random()%10, random()%10),
//    taille(random()%3+1, random()%3+1),
//    temp));
//    }
    c.affichage();
    return 0;
}
