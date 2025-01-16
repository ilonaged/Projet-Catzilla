#pragma once

#include "objet.hh"
//#include "souris.hh"

class Jouable: public Objet {
    public:
        virtual int jouer(sf::RenderWindow * main_window, std::vector<Objet *> *liste_objets) {return 0;};
};