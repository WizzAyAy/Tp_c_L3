#include <iostream>
#include <vector>

using namespace std;

int main(){

    vector<int> v1 = {2 ,5 ,56 ,48 ,484 ,6};
    int Max;

//    int nb;
//    cout << "entrez 6 valeurs : ";
//    for (size_t i = 0; i < 6; i++){
//        cin >> nb;
//        v1.push_back(nb);
//    }

    for (size_t i = 0; i < v1.size(); i++){
        cout << v1[i] << " ";
    }
    cout << endl;


    //par indice
    Max = v1[0];
    for (size_t i = 1; i < v1.size(); i++) {

        if (Max < v1[i]) Max = v1[i];
    }
    cout << "le max par indice est : " << Max << endl;

    //par iterateur
    Max = v1[0];
    for (std::vector<int>::const_iterator i(v1.begin() + 1); i!=v1.end(); ++i){

        if (Max < *i) Max = *i;
    }

    cout << "le max par iterateur est : " << Max << endl;

    //par boucle d'interval
    Max = v1[0];
    for (auto i : v1){
        if (Max < i) Max = i;
    }

    cout << "le max par boucle d'interval est : " << Max << endl;

    return 0;
}
