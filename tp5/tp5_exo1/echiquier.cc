#include "echiquier.hh"
#include "piece.hh"
#include "pion.hh"
#include "roi.hh"
#include "dame.hh"
#include "cavalier.hh"
#include <fstream>
#include <string>
#include <algorithm>
#include <cstdlib>

echiquier::echiquier(const echiquier &e){
    for (auto const & p : e._lespieces)
    _lespieces.push_back(p->clone());
}

void echiquier::ajoutpiece(std::unique_ptr<piece> p){
    _lespieces.push_back(std::move(p));
}

int echiquier::valeurdujoueur(const couleur &coul) const{
    int somme (0);
    for(auto const & x : _lespieces){
            if(x->getCouleur() == coul) somme += x->getValeur();
        }
    return somme;
}

void echiquier::enleverPiece(const position &p){
    for(auto it = _lespieces.begin(); it != _lespieces.end(); it++){
        if(it->get()->getPosition() == p) {
            _lespieces.erase(it);
            return;
        }
    }
}

bool echiquier::deplacer(const position &depart, const position &arrive){
//    std::cout << "depalcement de " << depart << " vers " << arrive << std::endl;
    for(auto const & pieceD : _lespieces){
        if(depart == pieceD->getPosition()){
//            std::cout << pieceD.get()->toString() << " vers " << arrive << std::endl;
            //la piece de depart ne peut pas aller en arrive
            if(!(pieceD->accepterposition(arrive))){return false;}
            couleur coul = pieceD->getCouleur();
            for(auto const & pieceA : _lespieces){
                if(arrive == pieceA->getPosition()){
//                      std::cout << "en " << arrive << " il y a " << pieceA.get()->toString() << std::endl;
                    //la piece de depart peut aller en arrive mais il y a une autre piece de la meme couleur
                    if(pieceA->getCouleur() == coul){
//                        std::cout << "la piece de depart et celle d'arrive sont de la meme couleur !" << std::endl;
                        return false;}
                    else {
                        //la piece de depart mange la piece en arrive qui est d'une couleur differnte
//                        std::cout << pieceD.get()->toString() << " mange " << pieceA.get()->toString() << std::endl;
                        enleverPiece(arrive);
                        pieceD->setPosition(arrive);
                        return true;
                    }
                }
            }
            //ya pas de piece en arrive donc je bouge simplement la piece
            pieceD->setPosition(arrive);
            return true;
        }
    }
    //il n'y a pas de piece en depart
    return false;
}

void echiquier::afficherToutesPieces() const{
    for(auto const & x : _lespieces){
        std::cout << x.get()->toString() << std::endl;
    }
}

void echiquier::afficher() const{
    std::cout << "Colonne 0  1  2  3  4  5  6  7" << std::endl;
for(size_t ligne = 0; ligne < 8; ligne++){
    std::cout << "Ligne " << ligne << " ";
    for(size_t colonne = 0; colonne < 8; colonne++){
        position temp(ligne, colonne);
        auto i = _lespieces.begin();
        for(; i != _lespieces.end(); i++){
            if(i->get()->getPosition() == temp) break;
        }
        if(i != _lespieces.end()){
            std::string sym = i->get()->getSymbol();
            std::cout << sym;
            if(i->get()->getCouleur() == couleur::B)
                std::cout << "B";
            else
                std::cout << "N";
            std::cout << " ";
        }
        else
            std::cout << "   ";
    }
    std::cout << std::endl;
}

}

void echiquier::sauvegarder(std::ofstream &os){
    os.open("echiquier.save");
    for(auto const & x :_lespieces)
        os << x.get()->toString() << std::endl;
    os.close();
}

void echiquier::chargement(std::ifstream &is){
    is.open("echiquier.save");
    if (is) {

        std::string ligne;
        while(std::getline(is, ligne)){
           std::string type  = std::string() + ligne.at(0);
           std::string coulS = std::string() + ligne.at(1);
           std::string lig   = std::string() + ligne.at(2);
           std::string col   = std::string() + ligne.at(3);
           int l = std::stoi(lig);
           int c = std::stoi(col);
           couleur coul_;
           if(coulS == "B")
               coul_ = couleur::B;
            else
               coul_ = couleur::N;

           if(type == "R"){
               auto temp = std::make_unique<roi>(coul_,position(l,c));
               _lespieces.push_back(std::move(temp));
            }
           if(type == "D"){
               auto temp = std::make_unique<dame>(coul_,position(l,c));
               _lespieces.push_back(std::move(temp));
            }
           if(type == "P"){
               auto temp = std::make_unique<pion>(coul_,position(l,c));
               _lespieces.push_back(std::move(temp));
            }
           if(type == "C"){
               auto temp = std::make_unique<cavalier>(coul_,position(l,c));
               _lespieces.push_back(std::move(temp));
            }
        }
    }
    else
        std::cout << "aucun fichier de sauvegarde deja present !\n";
}


void echiquier::jouer(){
    bool tourB = true, temp;
    int ligneD, colonneD;
    int ligneA, colonneA;

    while (partieFinie()) {
        afficher();
        if(tourB){
            std::cout << "à Blanc de jouez !\n";
            do{
                std::cout << "postion piece de depart (li,co) : ";

                std::cin >> ligneD >> colonneD;
                std::cout << "postion piece de arrive (li,co) : ";
                std::cin >> ligneA >> colonneA;
                temp = deplacer(position(ligneD, colonneD), position(ligneA, colonneA));
            }while(!temp);
            tourB = false;
        }
        else {

            do{
                std::cout << "postion piece de depart (li,co) : ";

                std::cin >> ligneD >> colonneD;
                std::cout << "postion piece de arrive (li,co) : ";
                std::cin >> ligneA >> colonneA;
                temp = deplacer(position(ligneD, colonneD), position(ligneA, colonneA));
            }while(!temp);
            tourB = true;
        }
        system("clear");

    }
    if(tourB) std::cout << "Bien joué !!! \nle joueur Noir a Win !!!\n";
    else std::cout << "Bien joué !!! \nle joueur Blanc a Win !!!\n";
}

bool echiquier::partieFinie() const{
    bool roiN = false;
    bool roiB = false;

    for(auto const & x : _lespieces){
        if(x.get()->getSymbol() == "R")
        {
            if(x.get()->getCouleur() == couleur::B) roiB = true;
            if(x.get()->getCouleur() == couleur::N) roiN = true;
        }
    }
    return (roiN && roiB);
}

void echiquier::depart(){
    //les pions
    for(int i = 0; i < 8; i++){
        auto tmpN = std::make_unique<pion>(couleur::N,position(1,i));
        auto tmpB = std::make_unique<pion>(couleur::B,position(6,i));
        _lespieces.push_back(std::move(tmpN));
        _lespieces.push_back(std::move(tmpB));
    }
    auto roiN = std::make_unique<roi>(couleur::N,position(0,4));
    auto roiB = std::make_unique<roi>(couleur::B,position(7,3));
    _lespieces.push_back(std::move(roiN));
    _lespieces.push_back(std::move(roiB));

    auto dameN = std::make_unique<dame>(couleur::N,position(0,3));
    auto dameB = std::make_unique<dame>(couleur::B,position(7,4));
    _lespieces.push_back(std::move(dameN));
    _lespieces.push_back(std::move(dameB));


    auto cavalierNG = std::make_unique<cavalier>(couleur::N,position(0,1));
    auto cavalierND = std::make_unique<cavalier>(couleur::N,position(0,6));
    _lespieces.push_back(std::move(cavalierNG));
    _lespieces.push_back(std::move(cavalierND));

    auto cavalierBG = std::make_unique<cavalier>(couleur::B,position(7,1));
    auto cavalierBD = std::make_unique<cavalier>(couleur::B,position(7,6));
    _lespieces.push_back(std::move(cavalierBG));
    _lespieces.push_back(std::move(cavalierBD));

}
