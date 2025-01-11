#include "souris.hh"

Souris::Souris(sf::RenderWindow * main_window) {
    position.x = main_window->getSize().x;
    position.y = (int)(main_window->getSize().y)/2;
    image->loadFromFile("./assets/mouse-sprite2.png");
    sprite->setTexture(*image);
}


void Souris::seDeplacer(float vitesse){
    sprite->setPosition(position.x + vitesse, position.y);

}