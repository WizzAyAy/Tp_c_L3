#include <iostream>
#include <string>
#include "sequence2.hh"

void sc_initialiservide (sequence &seq){
    //for(std::size_t i = 0; i < Taille; i++){
    //    seq.tab[i] = couleur::rouge;
    //}
    seq.indice = 0;
}

void sc_vider (sequence &seq){
    seq.indice = 0;
}

void sc_ajouter (sequence &seq, couleur const &coul){
    if(seq.indice < Taille){
        seq.tab[seq.indice] = coul;
    }
    seq.indice++;
}

void sc_copier (sequence &seqA, sequence const &seqB){
   sc_initialiservide(seqA);
   for(size_t i = 0; i < seqB.indice; i++){
       seqA.tab[i] = seqB.tab[i];
   }
   seqA.indice = seqB.indice;
}

couleur sc_acces (sequence const &seq, std::size_t const &ind){
    return seq.tab[ind];
}

void sc_afficher (couleur const &coul){
    switch (coul) {
    case couleur::rouge : cout << "rouge";break;
    case couleur::bleu : cout << "bleu";break;
    case couleur::vert : cout << "vert";break;
    case couleur::jaune : cout << "jaune";break;
    default: cout << "ERR for color";break;
    }
    cout << " ";
}

void sc_afficher(sequence const &seq){
    for(size_t i = 0; i < seq.indice; i++){
        sc_afficher(seq.tab[i]);
        cout << " ";
    }
    cout << endl;
}

bool sc_comparer (sequence const& seqA, sequence const& seqB){
    if (seqA.indice != seqB.indice) return false;
    for (size_t i = 0; i < seqA.indice; i++){
        if (seqA.tab[i] != seqB.tab[i]) return false;
    }
    return true;
}
