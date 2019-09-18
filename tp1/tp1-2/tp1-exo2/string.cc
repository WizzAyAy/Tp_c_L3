#include "string.hh"


int nb_voyelle(string const &mot){
    int nb_voy(0);
    for (size_t i = 0; i < mot.size();++i){
        if (mot.at(i) == 'a') nb_voy++;
        if (mot.at(i) == 'e') nb_voy++;
        if (mot.at(i) == 'i') nb_voy++;
        if (mot.at(i) == 'o') nb_voy++;
        if (mot.at(i) == 'u') nb_voy++;
        if (mot.at(i) == 'y') nb_voy++;
    }
    return nb_voy;
}

bool palindrome (string const & mot){
    size_t taille = mot.size();
    for (size_t i = 0; i < taille/2; i++) {
        if (mot.at(i) != mot.at(taille-i-1)) return false;
    }
    return true;
}

string cesar (string const &mot, int const &decal){

    tabL tabLettre;
    init(tabLettre);
    int rangLettre;
    string motCesar("");

    for (size_t i = 0; i < mot.length(); i++){
        rangLettre = cherche_rang(mot[i],tabLettre);
        if (rangLettre != -1){
            rangLettre += decal;
            rangLettre = rangLettre%26;
            motCesar += donne_lettre(rangLettre,tabLettre);
        }
        else motCesar += mot[i];
    }
    return motCesar;
}

int cherche_rang (char const & lettre, tabL const &tabLettre){
    for (size_t i = 0; i < 26; i++){
        if (lettre == tabLettre[i]) return i;
    }
    //si ce n'est pas une lettre on retourne -1;
    return -1;
}

char donne_lettre (int const &nb, tabL const &tabLettre){
    return tabLettre[nb];
}

void init (tabL & tabLettre){
    char lettre ('a');
    for (size_t i = 0; i < 26;i++){
        tabLettre[i] = lettre;
        lettre++;
    }
}
void init (tabC & tabChiffre){
    char lettre ('0');
    for (size_t i = 0; i < 10;i++){
        tabChiffre[i] = lettre;
        lettre++;
    }
}

/*int cherche_rang (char const & chiffre, tabC const &tabChiffre){
    for (size_t i = 0; i < 10; i++){
        if (chiffre == tabChiffre[i]) return i;
    }
    //si ce n'est pas un Chiffre on retourne -1;
    return -1;
}*/

int cherche_rang (char const & chiffre){
    return chiffre-48;
    //-48 car le code ascii de 0 est 48 un char de type chiffre -48
    // = le int de ce car. !! que si mon char est bien un chiffre!
}

/*int string_to_int (string const &mot){
    int entier(0);
    tabC tabChiffre;
    init(tabChiffre);
    int rang;
    int tailleMot(mot.length());

    for (size_t i = 0; i < tailleMot; i++){
        rang = cherche_rang(mot.at(i),tabChiffre);
        if (rang != -1){
            entier += rang*pow(10,tailleMot-i-1);
        }
    }
    return entier;
}*/

int string_to_int(const string &mot, int size){
    int rang;
    int res;
    if (size != 0){

        rang = cherche_rang(mot.at(0));
        if (rang != -1)
            res = rang*pow(10,size-1);
            return string_to_int(mot.substr(1,size-1),size-1) + res;
    }
    else return 0;
}
