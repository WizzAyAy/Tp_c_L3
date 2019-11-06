#pragma once
#include "element.hh"
#include "position.hh"
#include "taille.hh"
#include <string>

class obstacle : public element
{
public:
    obstacle(position pos, taille t);
    std::string toString()const;
};
