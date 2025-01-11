#pragma once

#include "objet.hh"
#include "screen.hh"

class Souris: public Objet {
public:
    Souris(sf::RenderWindow * main_window);
    void seDeplacer(float vitesse);
};