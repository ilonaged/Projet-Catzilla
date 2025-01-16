#pragma once

#include "objet.hh"
#include "souris.hh"

class Chat1: public Objet {
public:
    sf::Texture * image2;

    Chat1(sf::RenderWindow * main_window);
    int jouer(sf::RenderWindow * main_window,std::vector<Souris *> * pointeur_souris_liste,sf::Sprite * bg);

};