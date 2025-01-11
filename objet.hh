#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class Objet {
protected:
    sf::Vector2f position;
public:
    sf::Texture * image;
    sf::Sprite * sprite;
    Objet(sf::Vector2f position, sf::Texture * image);
    Objet();
    ~Objet();
    virtual void seDeplacer(float vitesse) {};
};