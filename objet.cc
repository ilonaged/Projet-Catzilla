#include "objet.hh"

Objet::Objet(sf::Vector2f position, sf::Texture * image):position(position),image(image){
    sprite = new sf::Sprite();
    sprite->setTexture(*image);
    sprite->setPosition(position);
}

Objet::Objet(){
    position={0,0};
    image = new sf::Texture();
    sprite = new sf::Sprite();
}

Objet::~Objet(){
    delete sprite;
}
