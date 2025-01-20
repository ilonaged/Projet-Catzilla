#include "souris_expl.hh"


Souris_expl::Souris_expl(sf::Vector2u windowSize,int vitesse_souris,bool haut){
    est_explosif=true;
    vitesse=vitesse_souris; 
    position.x = -130;
    //set l'image 1 de l'explosion
    image_expl = new sf::Texture();
    map_sprites_explosion["explosion1"] = new sf::Sprite();
    image_expl->loadFromFile("./assets/explosion.png");
    map_sprites_explosion["explosion1"]->setTexture(*image_expl);
    map_sprites_explosion["explosion1"]->setScale(sf::Vector2f(4.0f,4.0f));

    //envoie la souris explosive en haut si l'arguement haut passé en paramètre est vrai
     if (haut){
        position.y = (int)(windowSize.y/3);
        map_sprites_explosion["explosion1"]->setPosition(windowSize.x/2.6,(windowSize.y/4.6));

    }else{
        position.y = (int)(windowSize.y/3)+150;
        map_sprites_explosion["explosion1"]->setPosition((windowSize.x/2.6),(windowSize.y/4.6)+150);
    }
    //chargement de l'image de la souris explosive elle même
    image->loadFromFile("./assets/angry_mouse2.png");
    sprite->setTexture(*image);
    sprite->setPosition(position);

    //chargement de la 2e image de l'explosion
    image_expl2 = new sf::Texture();
    map_sprites_explosion["explosion2"] = new sf::Sprite();
    image_expl2->loadFromFile("./assets/explosion_bonus.png");
    map_sprites_explosion["explosion2"] ->setTexture(*image_expl2);
}



// void Souris_expl::explosion(sf::RenderWindow * main_window){
//     // main_window->draw(*map_sprites_explosion["explosion1"] );
//     // main_window->draw(*map_sprites_explosion["explosion2"] );
//     for (auto it : map_sprites_explosion){
//         main_window->draw(*it.second);

//     }
// }
