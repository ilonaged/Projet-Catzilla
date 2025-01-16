#include "chat1.hh"

Chat1::Chat1(sf::RenderWindow * main_window) {
    position.x = (int)(main_window->getSize().x/2.5);
    position.y = (int)(main_window->getSize().y) - (int)(main_window->getSize().y/2.05);

    image2 = new sf::Texture();
    image->loadFromFile("./assets/cat2-rest.png");
    image2->loadFromFile("./assets/cat2-catch.png");
    sprite->setTexture(*image);
    sprite->setPosition(position);
    sprite->setScale(sf::Vector2f(1.0f,1.0f));

}

int Chat1::jouer(sf::RenderWindow * main_window,std::vector<Souris *> *pointeur_souris_liste,sf::Sprite * bg) {
    int borne_gauche,borne_droite;
    int attrape=0;

    for (std::size_t i = 0; i < pointeur_souris_liste->size(); ++i) {
        borne_gauche=(*pointeur_souris_liste)[i]->sprite->getPosition().x;
        borne_droite=(*pointeur_souris_liste)[i]->sprite->getPosition().x + (int)((*pointeur_souris_liste)[i]->sprite->getGlobalBounds().width/1.08);
        
        if( borne_gauche < (main_window->getSize().x/2.45) && (main_window->getSize().x/2.45) < borne_droite ){
            std::cout<<"souris attrapée !!!"<<std::endl;
            pointeur_souris_liste->erase(pointeur_souris_liste->begin()+i);
            attrape=1;
        }
    }
    sprite->setTexture(*image2);

    for (int i = 0 ; i < 7 ; i++) {
        main_window->clear();
        main_window->draw(*bg);
        for (std::size_t i = 0; i < pointeur_souris_liste->size(); ++i) {
        (*pointeur_souris_liste)[i]->seDeplacer();
        main_window->draw(*((*pointeur_souris_liste)[i]->sprite));
        }
        main_window->draw(*sprite);
        main_window->display();
    }

    sprite->setTexture(*image);
    return attrape;
}