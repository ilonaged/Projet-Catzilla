#include "souris_expl.hh"


Souris_expl::Souris_expl(sf::Vector2u windowSize,int vitesse_souris,bool haut){
    est_explosif=true;
    vitesse=vitesse_souris; 
    position.x = -130;
    image_expl = new sf::Texture();
    sprite_expl = new sf::Sprite();
    image_expl->loadFromFile("./assets/explosion.png");
    sprite_expl->setTexture(*image_expl);
    sprite_expl->setScale(sf::Vector2f(4.0f,4.0f));
     if (haut){
        position.y = (int)(windowSize.y/3);
        sprite_expl->setPosition(windowSize.x/2.6,(windowSize.y/4.6));

    }else{
        position.y = (int)(windowSize.y/3)+150;
        sprite_expl->setPosition((windowSize.x/2.6),(windowSize.y/4.6)+150);
    }
    image->loadFromFile("./assets/angry_mouse2.png");
    sprite->setTexture(*image);
    sprite->setPosition(position);
}



void Souris_expl::explosion(sf::RenderWindow * main_window){
    main_window->draw(*sprite_expl);
    
}
