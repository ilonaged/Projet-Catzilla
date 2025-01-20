#include "menu.hh"

// Constructeur
Menu::Menu(sf::RenderWindow * main_window,int* gameState):Instance(main_window,gameState){

  set_values();
}

// Destructeur
Menu::~Menu(){
  delete font;
  delete image;
}


// Initialisation des valeurs
void Menu::set_values(){
  pos = 0;
  theselect = false;

  image->loadFromFile("./assets/menu-catzilla.png");
  map_sprites["bg"]->setTexture(*image);

  font->loadFromFile("./assets/LVDCGO__.TTF");
  options = {"PLAY", "SETTINGS", "CREDITS", "Use the arrow keys to navigate and Enter to select"};
  texts.resize(4);
  text_coords = {{410,225},{350,365},{370,510}, {25, (float)main_window->getSize().y - 50}};
  text_size = {30,30,30, 20};

  for (std::size_t i{}; i < texts.size(); ++i){
   texts[i].setFont(*font); 
   texts[i].setString(options[i]); 
   texts[i].setCharacterSize(text_size[i]);
   texts[i].setOutlineColor(sf::Color::Black);
   texts[i].setPosition(text_coords[i]);
  }
  texts[0].setOutlineThickness(4);
  texts[3].setOutlineThickness(4);

  music.openFromFile("./assets/Dark-Meow.ogg");
  music.setLoop(true);
  music.play();
}


// Boucle d'événements
void Menu::loop_events(){
  sf::Event event;

  //gérer la fermeture de la fenêtre
  while(main_window->pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        music.stop();
        main_window->close();
      }

      //gérer le redimensionnement de la fenêtre
      if (event.type == sf::Event::Resized){
        windowSize = main_window->getSize();
      }

    // Navigation dans le menu avec les touches Haut, Bas et Entrée
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !pressed){
      if( pos < 2){
        ++pos;
        pressed = true;
        texts[pos].setOutlineThickness(4);
        texts[pos - 1].setOutlineThickness(0);
        pressed = false;
        theselect = false;
      }
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !pressed){
      if( pos > 0){
        --pos;
        pressed = true;
        texts[pos].setOutlineThickness(4);
        texts[pos + 1].setOutlineThickness(0);
        pressed = false;
        theselect = false;
      }
    }

    // Si on appuie sur Entrée, on va sur la page au gameState correspondant
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && !theselect) {
      theselect = true;
      *gameState = pos + 1;
      music.stop();
    }
  }
}


// Dessiner tous les éléments de la fenêtre
void Menu::draw_all(){
  main_window->clear();
  main_window->draw(*map_sprites["bg"]);
  for(auto t : texts){
   main_window->draw(t); 
  }
  main_window->display();
}


// Lancer la fenêtre du menu
void Menu::run(){
  theselect = false;
  while(main_window->isOpen() && *gameState == 0){
    loop_events();
    draw_all();
  }
}