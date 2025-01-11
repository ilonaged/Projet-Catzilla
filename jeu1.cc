#include "jeu1.hh"
#include "souris.hh"

Jeu1::Jeu1(sf::RenderWindow * main_window,int* gameState):gameState(gameState),main_window(main_window) {
  font = new sf::Font();
  image = new sf::Texture();
  bg = new sf::Sprite();

  set_values();
}



void Jeu1::set_values(){
  // window->create(sf::VideoMode(1280,720), "Menu SFML", sf::Style::Default);
  main_window->setPosition(sf::Vector2i(0,0));

//   pos = 0;
//   pressed = theselect = false;
//   font->loadFromFile("./assets/LVDCGO__.TTF");
  image->loadFromFile("./assets/game1-floor.png");
  sf::Vector2u windowSize = main_window->getSize();
  sf::Vector2u textureSize = image->getSize();
  bg->setScale(
    float(windowSize.x) / textureSize.x,
    float(windowSize.y) / textureSize.y
  );
  bg->setTexture(*image);

  // pos_mouse = {0,0};
//   mouse_coord = {0, 0};

//   options = {"JEU 1", "JEU 2", "JEU 3"};
//   texts.resize(3);
//   coords = {{410,225},{410,365},{410,510}};
//   sizes = {30,30,30};

//   for (std::size_t i{}; i < texts.size(); ++i){
//    texts[i].setFont(*font); 
//    texts[i].setString(options[i]); 
//    texts[i].setCharacterSize(sizes[i]);
//    texts[i].setOutlineColor(sf::Color::Black);
//    texts[i].setPosition(coords[i]);
//   }
//   texts[0].setOutlineThickness(4);
//   pos = 0;

}

void Jeu1::loop_events() {
  sf::Event event;
  while(main_window->pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        main_window->close();
      }
  }
}


void Jeu1::draw_all() {
  main_window->clear();
  main_window->draw(*bg);
//   for(auto t : texts){
//    main_window->draw(t); 
//   }
  main_window->display();
}


void Jeu1::run_jeu1(){
  
    while(main_window->isOpen() && *gameState == 1) {
      draw_all();
      loop_events();
      
  }

}





