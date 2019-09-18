#include <iostream>
#include <string>
#include "sequence2.hh"

void sc_initialiservide (sequence &seq){
    //for(std::size_t i = 0; i < Taille; i++){
    //    seq.tab[i] = couleur::rouge;
    //}
    seq.indice = 0;
    seq.couleurs  = new couleur[seq.indice];
}

void sc_vider (sequence &seq){
    delete seq.couleurs;
    seq.indice = 0;
}

void sc_ajouter (sequence &seq, couleur const &coul){
    /*seq.indice++;
    sequence newSeq;
    newSeq.couleurs = new couleur[seq.indice];
    for (size_t i = 0; i < seq.indice - 1; i++){
        newSeq.couleurs[i] = seq.couleurs[i];
    }
    newSeq.couleurs[seq.indice-1] = coul;
    newSeq.indice = seq.indice;
    seq = newSeq;*/

    if (seq.indice % 5 == 0){
        seq.indice++;
            sequence newSeq;
            newSeq.couleurs = new couleur[seq.indice+5];
            for (size_t i = 0; i < seq.indice - 1; i++){
                newSeq.couleurs[i] = seq.couleurs[i];
            }
            newSeq.couleurs[seq.indice-1] = coul;
            newSeq.indice = seq.indice;
            seq = newSeq;
    }
    else {
        seq.indice++;
        seq.couleurs[seq.indice] = coul;
    }
}

void sc_copier (sequence &desination, sequence const &source){
    desination = source;
}

couleur sc_acces (sequence const &seq, std::size_t const &ind){
    return seq.couleurs[ind];
}

void sc_afficher (couleur const &coul){
    switch (coul) {
        case couleur::rouge : cout << "rouge";break;
        case couleur::bleu : cout << "bleu";break;
        case couleur::vert : cout << "vert";break;
        case couleur::jaune : cout << "jaune";break;
       // default: cout << "ERR for color";break; car on est dans un enum
    }
    cout << " ";

}

void sc_afficher(sequence const &seq){
    for (size_t i = 0; i < seq.indice; i++) {
        sc_afficher(seq.couleurs[i]);
    }
    cout << endl;
}

bool sc_comparer (sequence const& seqA, sequence const& seqB){
    if (seqA.indice != seqB.indice) return false;

    for (size_t i = 0; i < seqA.indice; i++){
        if (seqA.couleurs[i] != seqB.couleurs[i]) return false;
    }
    return true;
}
