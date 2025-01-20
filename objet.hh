#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <map>

// Classe Objet : permet de gérer les objets du jeu (chat, souris, bestioles...)
class Objet {
protected:
    sf::Vector2f position;
    sf::Texture * image;
    sf::Sprite * sprite;
    std::map<std::string,sf::Sprite *> map_sprites_explosion; //map contenant les sprites des explosions
    bool est_explosif;
    bool est_bestiole;

public:
    int vitesse;
    Objet(sf::Vector2f position, sf::Texture * image);
    Objet();
    ~Objet();

    //getters
    sf::Sprite * getSprite(){return sprite;};
    sf::Vector2f getPosition(){return position;};
    bool getEst_explosif(){return est_explosif;};
    bool getEst_bestiole(){return est_bestiole;};

    //méthodes virtuelles
    virtual void seDeplacer() {};
    virtual void explosion(sf::RenderWindow * main_window) {};

    //surcharge de l'opérateur ()
    sf::Sprite * operator()(){return sprite;};
};

