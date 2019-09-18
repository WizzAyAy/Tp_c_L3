#pragma once
#include <array>

using namespace std;
using indicesequence = size_t;

enum class couleur {rouge,vert,jaune,bleu};

const int Taille(100);
using tab_couleur = array <couleur,Taille>;

struct sequence {
    tab_couleur tab;
    indicesequence indice;
};

void sc_initialiservide (sequence &seq);
void sc_vider (sequence &seq);
void sc_ajouter (sequence &seq, couleur const &coul);
void sc_copier (sequence &seqA, sequence const &seqB);
couleur sc_acces (sequence const &seq, size_t const &ind);
void sc_afficher (couleur const &coul);
void sc_afficher(sequence const &seq);
bool sc_comparer (sequence const& seqA, sequence const& seqB);


