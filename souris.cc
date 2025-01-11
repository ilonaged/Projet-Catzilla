#include "souris.hh"

Souris::Souris(sf::RenderWindow * main_window) {
    position.x = -130;
    position.y = (int)(main_window->getSize().y/2);
    image->loadFromFile("./assets/mouse-sprite2.png");
    sprite->setTexture(*image);
    sprite->setPosition(position);
}


void Souris::seDeplacer(float vitesse){
    position.x += vitesse;
    sprite->setPosition(position.x + vitesse, position.y);

}