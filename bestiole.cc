#include <cmath>
#include "bestiole.hh"


//permet de générer une bestiole soit sur le chemin du haut soit sur le chemin du bas en focntion de l'arguement haut
Bestiole::Bestiole(sf::Vector2u windowSize,int vitesse_objet,bool haut){
    est_bestiole=true;
    vitesse=vitesse_objet; 
    position.x = -130;

     if (haut){
        position.y = (int)(windowSize.y/2.9);
        pos_hor_init=position.y;


    }else{
        position.y = (int)(windowSize.y/2.9)+150;
        pos_hor_init=position.y;

    }
    image->loadFromFile("./assets/cafard.png");
    sprite->setTexture(*image);
    sprite->setPosition(position);
    sprite->setScale(sf::Vector2f(0.5f,0.5f));
    

}

//La bestiole se déplace étrangement...
void Bestiole::seDeplacer(){
    position.x += vitesse;
    position.y=pos_hor_init+(int)(9*sin(3*position.x));
    sprite->setPosition(position.x, position.y);

}


