#pragma once
#include <array>
#include <string>
#include <math.h>


using namespace std;
using tabL = array<char,25>;
using tabC = array<int,10>;

void init (tabL & tabLettre);
int cherche_rang (char const & lettre, tabL const &tabLettre);
int cherche_rang(char const & chiffre);
char donne_lettre (int const &nb, tabL const &tabLettre);
int nb_voyelle(string const &mot);
bool palindrome (string const & mot);
string cesar (string const &mot, int const &decal);
int string_to_int (string const &mot, int size);

