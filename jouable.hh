#pragma once

#include "objet.hh"

class Jouable: public Objet {
public:
    virtual int jouer(sf::RenderWindow * main_window){return 0;};
};