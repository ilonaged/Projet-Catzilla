#pragma once

#include "objet.hh"

class Souris: public Objet {
protected:
    sf::Texture * image_expl;

public:
    Souris(sf::Vector2u windowSize,int vitesse_souris,bool haut);
    Souris();
    void seDeplacer();
    // virtual void explosion(sf::RenderWindow * main_window);
    void explosion(sf::RenderWindow * main_window);

};