#include "chat1.hh"

Chat1::Chat1(sf::RenderWindow * main_window) {
    position.x = (int)(main_window->getSize().x/2);
    position.y = (int)(main_window->getSize().y) - (int)(main_window->getSize().y/2.05);
    image2 = new sf::Texture();
    image->loadFromFile("./assets/cat-rest.png");
    image2->loadFromFile("./assets/cat-catch.png");
    sprite->setTexture(*image);
    sprite->setPosition(position);
    sprite->setScale(sf::Vector2f(2.5f,2.5f));
}

int Chat1::jouer(sf::RenderWindow * main_window) {
    sprite->setTexture(*image2);
    main_window->draw(*sprite);
    main_window->display();
    for (int i = 0 ; i < 10000 ; i++) {
        
    }
    sprite->setTexture(*image);
    return 0;
}