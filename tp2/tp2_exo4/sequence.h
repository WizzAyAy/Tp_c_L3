#pragma once
#include <iostream>
#include <vector>

enum couleur {
    rouge,
    jaune,
    bleu,
    vert,
};

using indicesequence = size_t;

class sequence{
public:
    sequence();
    sequence(sequence const &s);
    indicesequence taille () const;
    void vider ();
    void ajouter (couleur const &coul);
    void copier (sequence const &seqB);
    couleur acces (indicesequence const &ind);
    void afficher (couleur const &coul, std::ostream & os);
    void afficher (couleur const &coul);
    void afficher(std::ostream &os);
    bool comparer (sequence const& seqB);

private:
    std::vector<couleur> _contenue;
    indicesequence _taille;

};
