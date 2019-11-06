#include <cstddef>
#pragma once
//classe ABSTRAITE ON EST PAS EN JAVA DONC PAS DE VIRTUAL OU ABSTRACT JUSTE AU MOINS UNE METHODE VIRTUAL PURE

class parcours{

public:
    parcours() : _pos(0){}
    std::size_t getPos() const{return _pos;}
    void suivant(){_pos++;}
private:
    std::size_t _pos;
};

class ensemble{
public:
    void ajouter(int nb);
    virtual void enlever(int nb)=0;
    //afficher est moins bien que affiche parcours qui elle na pas besoin d'etre redef sur les sous classe !!!
    virtual void afficher() =0;
    void afficherParcours();

    virtual bool appartient(int nb)const =0;
    virtual bool estVide() =0;

    virtual parcours commencer() const;
    virtual bool estfini(parcours const &p) const=0;
    virtual void suivant(parcours & p) const;
    virtual int acces(parcours const &p) const=0;
    virtual void vider()=0;

    void unionavec(ensemble const & e2);
    void interavec(ensemble const & e2);
    void diffavec(ensemble const & e2);

    void calculerunion(ensemble const&e1, ensemble const&e2);
    void calculerinter(ensemble const&e1, ensemble const&e2);
    void calculerdiff(ensemble const&e1, ensemble const&e2);

protected:
    virtual void ajoutersansverif(int nb)=0;

protected:
    ensemble();
};


