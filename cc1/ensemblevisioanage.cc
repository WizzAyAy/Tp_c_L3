#include "ensemblevisioanage.hh"
#include "visionageserie.hh"
#include "visionagesaga.hh"
#include <iostream>


ensemblevisioanage::ensemblevisioanage(){

}

ensemblevisioanage::~ensemblevisioanage(){
    for(auto v : _ensemble){
        delete v;
    }
}

void ensemblevisioanage::afficherlesvisionage(){
    for(auto v : _ensemble){
        std::cout << v->toString();
    }
}

void ensemblevisioanage::ajoutervisionage(const visionage &v){
    _ensemble.push_back(v.clone());
}

void ensemblevisioanage::afficherlesserie() const{
    for (auto s : _ensemble){
        auto ss = dynamic_cast<visionageSerie const*>(s);
        if(ss != nullptr){
            std::cout << ss->toString();
        }
    }
}


void ensemblevisioanage::afficherannee(const unsigned int &a) const{
    std::cout << "les film de l'anné : " << a << " sont :\n";
    for(auto v : _ensemble){
        if(v->getDateVisonage() < (a+1)*10000 && v->getDateVisonage() > a*10000-1){
            std::cout << v->toString();
        }

    }
    std::cout << "-----------------------------\n";
}

int ensemblevisioanage::nombredesaga() const{
std::vector<std::string> temp;
for (auto s : _ensemble){
    auto ss = dynamic_cast<visionagesaga const*>(s);
    if(ss != nullptr){
        if(!dejadedans(ss->getNomSaga(),temp)) temp.push_back(ss->getNomSaga());
    }
}
return temp.size();
}

bool ensemblevisioanage::dejadedans(const std::string &titresaga, const std::vector<std::string> &temp) const{
    for(auto v : temp){
        if(v == titresaga) return true;
    }
    return false;
}

