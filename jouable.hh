#pragma once

#include "objet.hh"
#include "souris.hh"

class Jouable: public Objet {
public:
    virtual int jouer(sf::RenderWindow * main_window,std::vector<Souris *> souris_liste,int* nb_souris_attrape){return 0;};
};