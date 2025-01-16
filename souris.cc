#include "souris.hh"

Souris::Souris(sf::RenderWindow * main_window,int vitesse_souris):vitesse_souris(vitesse_souris) {
    position.x = -130;
    position.y = (int)(main_window->getSize().y/2);
    image->loadFromFile("./assets/mouse-sprite2.png");
    sprite->setTexture(*image);
    sprite->setPosition(position);
}


void Souris::seDeplacer(){
    position.x += vitesse_souris;
    sprite->setPosition(position.x + vitesse_souris, position.y);

}