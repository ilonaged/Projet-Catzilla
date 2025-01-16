#pragma once

#include "objet.hh"

class Souris: public Objet {
public:
    int vitesse_souris;
    Souris(sf::RenderWindow * main_window,int vitesse_souris);
    void seDeplacer();
};