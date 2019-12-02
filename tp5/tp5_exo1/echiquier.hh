#pragma once
#include <memory>
#include "piece.hh"
#include <vector>


class echiquier
{
public:
    echiquier()=default;
    ~echiquier()=default;
    echiquier(echiquier const & e);
    void ajoutpiece(std::unique_ptr<piece> p);

    int valeurdujoueur(couleur const & coul)const;

    void enleverPiece(position const & p);
    bool deplacer(position const & depart, position const & arrive);

    void afficherToutesPieces()const;
    void afficher()const;

    void sauvegarder(std::ofstream & os);
    void chargement(std::ifstream &is);

    void jouer();
    bool partieFinie()const;

    void depart();
private:
    std::vector<std::unique_ptr<piece>> _lespieces;
};

