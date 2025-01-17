#include "objet.hh"

Objet::Objet(sf::Vector2f position, sf::Texture * image):position(position),image(image),est_explosif(false),est_bestiole(false){
    sprite = new sf::Sprite();
    sprite->setTexture(*image);
    sprite->setPosition(position);
    vitesse=0;
}

Objet::Objet():est_explosif(false){
    position={0,0};
    image = new sf::Texture();
    sprite = new sf::Sprite();
    vitesse=0;
}

Objet::~Objet(){
    delete sprite;
}
