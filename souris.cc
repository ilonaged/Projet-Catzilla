#include "souris.hh"

Souris::Souris(sf::Vector2u windowSize,int vitesse_souris,bool haut){
    vitesse=vitesse_souris; 
    position.x = -130;
    image_expl = new sf::Texture();
    map_sprites_explosion["explosion"]= new sf::Sprite();
    image_expl->loadFromFile("./assets/sang.png");
    map_sprites_explosion["explosion"]->setTexture(*image_expl);
     if (haut){
        position.y = (int)(windowSize.y/3);
        map_sprites_explosion["explosion"]->setPosition(windowSize.x/2.6,(windowSize.y/4.6));

    }else{
        position.y = (int)(windowSize.y/3)+150;
        map_sprites_explosion["explosion"]->setPosition(windowSize.x/2.6,(windowSize.y/4.6)+150);
    }
    image->loadFromFile("./assets/mouse-sprite2.png");
    sprite->setTexture(*image);
    sprite->setPosition(position);
}

Souris::Souris(){
    vitesse=0; 
    position.x = -130;
    position.y = 0;
    image->loadFromFile("./assets/mouse-sprite2.png");
    sprite->setTexture(*image);
    sprite->setPosition(position);

}


void Souris::seDeplacer(){
    position.x += vitesse;
    sprite->setPosition(position.x, position.y);

}


void Souris::explosion(sf::RenderWindow * main_window){
    // main_window->draw(*map_sprites_explosion["explosion"]);
     for (auto it : map_sprites_explosion){
        main_window->draw(*it.second);

    }
}