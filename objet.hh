#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class Objet {
protected:
    sf::Vector2f position;
    sf::Texture * image;
    sf::Sprite * sprite;
    bool est_explosif;
public:
    int vitesse;
    Objet(sf::Vector2f position, sf::Texture * image);
    Objet();
    ~Objet();
    sf::Sprite * getSprite(){return sprite;};
    sf::Vector2f getPosition(){return position;};
    bool getEst_explosif(){return est_explosif;};
    virtual void seDeplacer() {};
    virtual void explosion(sf::RenderWindow * main_window) {};
    sf::Sprite * operator()(){return sprite;};
};

