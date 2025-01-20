#include "instance.hh"

// Constructeur
 Instance::Instance(sf::RenderWindow * main_window, int* gameState):gameState(gameState),main_window(main_window){
    font = new sf::Font();
    image = new sf::Texture();
    map_sprites["bg"]=new sf::Sprite();
    set_values_instance();
 };

// Destructeur
Instance::~Instance() {
    delete(font);
    delete(image);
    delete(map_sprites["bg"]);
   
}


// Initialiser les valeurs de l'instance
void Instance::set_values_instance(){
    main_window->setPosition(sf::Vector2i(0,0));
    pressed=false;
    windowSize = main_window->getSize();
}


// Boucle d'événements
void Instance::loop_events(){
    sf::Event event;

  while(main_window->pollEvent(event)) {
        //gérer la fermeture de la fenêtre
        if (event.type == sf::Event::Closed) {
        main_window->close();
        }
        //gérer le redimensionnement de la fenêtre
        if (event.type == sf::Event::Resized){
            windowSize = main_window->getSize();
        }
    }
}


// Lancer la fenêtre de l'instance de jeu correspondante
void Instance::run(){
    while(main_window->isOpen()){
        main_window->clear();
        main_window->draw(*map_sprites["bg"]);
        main_window->display();
        loop_events();
    }
}
