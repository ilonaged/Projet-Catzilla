#pragma once

#include "objet.hh"
#include "souris.hh"

class Chat1: public Objet {
protected : 
    sf::Texture * image2;
    bool est_en_haut;

public:
    Chat1(sf::Vector2u windowSize);
    int jouer(sf::RenderWindow * main_window,std::vector<Objet *> * pointeur_liste,sf::Sprite * bg);
    void seDeplacer();
    void avancer_reculer(int deplacement);

};