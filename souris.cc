#include "souris.hh"

// Constructeur avec paramètres
Souris::Souris(sf::Vector2u windowSize, int vitesse_souris, bool haut) {
    //initialisation des variables de position
    vitesse = vitesse_souris; 
    position.x = -130;

    //gérer les explosions
    image_expl = new sf::Texture();
    map_sprites_explosion["explosion"] = new sf::Sprite();
    image_expl->loadFromFile("./assets/sang.png");
    map_sprites_explosion["explosion"]->setTexture(*image_expl);
    
    //décide si la souris est en haut ou en bas pour gérer les explosions
    if (haut) { 
        position.y = (int)(windowSize.y / 3);
        map_sprites_explosion["explosion"]->setPosition(windowSize.x / 2.6, (windowSize.y / 4.6));
    } else {
        position.y = (int)(windowSize.y / 3) + 150;
        map_sprites_explosion["explosion"]->setPosition(windowSize.x / 2.6, (windowSize.y / 4.6) + 150);
    }
    
    //chargement de la texture de la souris
    image->loadFromFile("./assets/mouse-sprite2.png");
    sprite->setTexture(*image);
    sprite->setPosition(position);
}


// Constructeur par défaut
Souris::Souris(){
    vitesse=0; 
    position.x = -130;
    position.y = 0;
    image->loadFromFile("./assets/mouse-sprite2.png");
    sprite->setTexture(*image);
    sprite->setPosition(position);
}


// Méthode pour déplacer la souris
void Souris::seDeplacer(){
    position.x += vitesse;
    sprite->setPosition(position.x, position.y);

}

// Parcourt la map des explosions et les dessine
void Souris::explosion(sf::RenderWindow * main_window){
     for (auto it : map_sprites_explosion){
        main_window->draw(*it.second);
    }
}