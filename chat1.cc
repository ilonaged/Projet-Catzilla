#include "chat1.hh"

Chat1::Chat1(sf::Vector2u windowSize) {
    position.x = (int)(windowSize.x/2.5);
    position.y = (int)(windowSize.y/1.78);
    est_en_haut=false;

    image2 = new sf::Texture();
    image->loadFromFile("./assets/cat2-rest.png");
    image2->loadFromFile("./assets/cat2-catch.png");
    sprite->setTexture(*image);
    sprite->setPosition(position);
    sprite->setScale(sf::Vector2f(1.0f,1.0f));

}

int Chat1::jouer(sf::RenderWindow * main_window,std::vector<Objet *> *pointeur_liste,sf::Sprite * bg) {
    int borne_gauche,borne_droite;
    int attrape=0;
    std::size_t ind_souris_morte;
        
    sprite->setTexture(*image2);

    for (int i = 0 ; i < 7 ; i++) {
        main_window->clear();
        main_window->draw(*bg);
        for (std::size_t i = 0; i < pointeur_liste->size(); ++i) {
            borne_gauche=(*pointeur_liste)[i]->getPosition().x;
            borne_droite=(*pointeur_liste)[i]->getPosition().x + (int)((*(*pointeur_liste)[i])()->getGlobalBounds().width/1.08);

            if((borne_gauche < (main_window->getSize().x/2.45) && (main_window->getSize().x/2.45) < borne_droite) && (((*pointeur_liste)[i]->getPosition().y<((main_window->getSize().y/3)+50))==est_en_haut)){
                    // std::cout<<"souris attrapée !!!"<<std::endl;
                    ind_souris_morte=i;
                    attrape=1;
                    (*pointeur_liste)[ind_souris_morte]->explosion(main_window);
            }else{
                (*pointeur_liste)[i]->seDeplacer();
                main_window->draw(*(*(*pointeur_liste)[i])());
            }

        }
        main_window->draw(*sprite);
        main_window->display();
    }

    sprite->setTexture(*image);

    if(attrape){
        for (int i = 0 ; i < 4 ; i++) {
            main_window->clear();
            main_window->draw(*bg);
            for (std::size_t i = 0; i < pointeur_liste->size(); ++i) {
                if(i!=ind_souris_morte){
                    (*pointeur_liste)[i]->seDeplacer();
                    main_window->draw(*(*(*pointeur_liste)[i])());
                }
            }
            (*pointeur_liste)[ind_souris_morte]->explosion(main_window);
            main_window->draw(*sprite);
            main_window->display();
        }
        if((*pointeur_liste)[ind_souris_morte]->getEst_explosif()){
            attrape=-1;
            for (int i = 0 ; i < 20 ; i++) {
            main_window->clear();
            main_window->draw(*bg);
            for (std::size_t i = 0; i < pointeur_liste->size(); ++i) {
                if(i!=ind_souris_morte){
                    main_window->draw(*(*(*pointeur_liste)[i])());
                }
            }
            (*pointeur_liste)[ind_souris_morte]->explosion(main_window);
            main_window->draw(*sprite);
            main_window->display();
            }
        }
        if((*pointeur_liste)[ind_souris_morte]->getEst_bestiole())
            attrape=2;
        pointeur_liste->erase(pointeur_liste->begin()+ind_souris_morte);
    }
    return attrape;
}



void Chat1::seDeplacer(){
    if(est_en_haut){
    position.y += 150;
    sprite->setPosition(position.x, position.y);

    }else{
        position.y -= 150;
        sprite->setPosition(position.x, position.y);
    }

};


void Chat1::avancer_reculer(int deplacement){
    if (deplacement==1){
        if (est_en_haut==false){
            seDeplacer();
            est_en_haut=true;

        }
    }
    if (deplacement==-1){
        if (est_en_haut==true){
            seDeplacer();
            est_en_haut=false;

        }
    }
}