#include "chat1.hh"

Chat1::Chat1(sf::Vector2u windowSize) {
    //On place le chat au bon endroit pour attraper les souris
    position.x = (int)(windowSize.x/2.5);
    position.y = (int)(windowSize.y/1.78);
    est_en_haut=false;

    //image2 correspond à l'image où le chat tend le bras
    image2 = new sf::Texture();
    image->loadFromFile("./assets/cat2-rest.png");
    image2->loadFromFile("./assets/cat2-catch.png");
    sprite->setTexture(*image);
    sprite->setPosition(position);
    sprite->setScale(sf::Vector2f(1.0f,1.0f));

}


//Fait jouer le chat à partir d'une fenêtre, d'un vecteur d'objets et d'un fond de jeu
int Chat1::jouer(sf::RenderWindow * main_window,std::vector<Objet *> *pointeur_liste,sf::Sprite * bg) {
    int borne_gauche,borne_droite;
    int attrape=0;
    //indice de la souris potentiellement attrapée
    std::size_t ind_souris_morte;
    
    //change l'image du chat statique en chat bras levé 
    sprite->setTexture(*image2);

    //cette boucle permet d'afficher l'animation du chat qui tend le bras (car le sprite a été changé) ainsi que de tester si une souris
    // a été attrapée.
    for (int i = 0 ; i < 7 ; i++) {
        main_window->clear();
        main_window->draw(*bg);
        for (std::size_t i = 0; i < pointeur_liste->size(); ++i) {
            //borne_gauche correspond à la queue de la souris/bestiole
            borne_gauche=(*pointeur_liste)[i]->getPosition().x;
            //borne_droite correspond à la tête de la souris/bestiole
            borne_droite=(*pointeur_liste)[i]->getPosition().x + (int)((*(*pointeur_liste)[i])()->getGlobalBounds().width/1.08);

            //teste si la patte est entre la borne gauche et la borne droite et si la souris en question est à la meme hauteur que le chat
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

    //Le chat revient en position normale
    sprite->setTexture(*image);

    //permet de continuer l'animation d'explosion dans le cas où la souris est attrapée
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
        //permet de faire durer encore plus l'animation d'explosion dans le cas où la souris est explosive et que c'est la fin du jeu
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
        //Supression de la souris dans le vecteur une fois morte 
        pointeur_liste->erase(pointeur_liste->begin()+ind_souris_morte);
    }
    return attrape;
}



//Le chat se déplace que verticalement et en faisant un "saut" de pixel
void Chat1::seDeplacer(){
    if(est_en_haut){
    position.y += 150;
    sprite->setPosition(position.x, position.y);

    }else{
        position.y -= 150;
        sprite->setPosition(position.x, position.y);
    }

};


//Permet en fonction de l'arguement deplacement de soit avancer soit reculer
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