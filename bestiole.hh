#pragma once
#include "objet.hh"

class Bestiole : public Objet{
protected:
    // sf::Texture * image_expl;
    // sf::Sprite * sprite_expl;
    int pos_hor_init;

public : 
    Bestiole(sf::Vector2u windowSize,int vitesse_objet,bool haut);
    ~Bestiole();
    void seDeplacer();
};