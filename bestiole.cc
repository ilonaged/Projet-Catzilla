#include <cmath>
#include "bestiole.hh"



Bestiole::Bestiole(sf::Vector2u windowSize,int vitesse_objet,bool haut){
    vitesse=vitesse_objet; 
    position.x = -130;
    // image_expl = new sf::Texture();
    // sprite_expl = new sf::Sprite();
    // image_expl->loadFromFile("./assets/sang.png");
    // sprite_expl->setTexture(*image_expl);
     if (haut){
        position.y = (int)(windowSize.y/2.9);
        pos_hor_init=position.y;
        // sprite_expl->setPosition(windowSize.x/2.6,(windowSize.y/4.6));

    }else{
        position.y = (int)(windowSize.y/2.9)+150;
        pos_hor_init=position.y;
        // sprite_expl->setPosition(windowSize.x/2.6,(windowSize.y/4.6)+150);
    }
    image->loadFromFile("./assets/cafard.png");
    sprite->setTexture(*image);
    sprite->setPosition(position);
    sprite->setScale(sf::Vector2f(0.5f,0.5f));
    

}

void Bestiole::seDeplacer(){
    position.x += vitesse;
    position.y=pos_hor_init+(int)(9*sin(3*position.x));
    sprite->setPosition(position.x, position.y);

}


