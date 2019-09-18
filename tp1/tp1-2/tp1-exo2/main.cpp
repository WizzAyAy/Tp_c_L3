#include <iostream>
#include "string.hh"




int main()
{
   string mot("je suis cesar ! le grand cesar");
   cout << "entrez un mot : ";
   //cin >> mot;

   cout << "le mot [" << mot << "] posséde " << nb_voyelle(mot) << " voyelle(s) \n";

   if (palindrome(mot)) cout << "le mot " << mot << " est un palindrome \n";

   cout << cesar(mot, 0) << endl;
   cout << cesar(mot, 27) << endl;
   cout << cesar(mot, 1) << endl;

   string nombre("9999110");
   cout << string_to_int(nombre,nombre.length()) << "\n";
   cout << 100 + string_to_int(nombre,nombre.length()) << endl;
   return 0;
}
