#include "menu.hh"

Menu::Menu(sf::RenderWindow * main_window,int* gameState):Instance(main_window,gameState){

  set_values();
}

Menu::~Menu(){
  delete font;
  delete image;
  delete bg;
}

void Menu::set_values(){
  pos = 0;
  theselect = false;

  image->loadFromFile("./assets/menu-catzilla.png");
  bg->setTexture(*image);

  font->loadFromFile("./assets/LVDCGO__.TTF");
  options = {"JEU 1", "JEU 2", "JEU 3"};
  texts.resize(3);
  text_coords = {{410,225},{410,365},{410,510}};
  text_size = {30,30,30};

  for (std::size_t i{}; i < texts.size(); ++i){
   texts[i].setFont(*font); 
   texts[i].setString(options[i]); 
   texts[i].setCharacterSize(text_size[i]);
   texts[i].setOutlineColor(sf::Color::Black);
   texts[i].setPosition(text_coords[i]);
  }
  texts[0].setOutlineThickness(4);

}

void Menu::loop_events(){
  sf::Event event;
  while(main_window->pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        main_window->close();
      }
      if (event.type == sf::Event::Resized){
        windowSize = main_window->getSize();

      }

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

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && !theselect) {
      theselect = true;
      
      std::cout << options[pos] << '\n';
      *gameState=pos+1;
    }
  }
}

void Menu::draw_all(){
  main_window->clear();
  main_window->draw(*bg);
  for(auto t : texts){
   main_window->draw(t); 
  }
  main_window->display();
}

void Menu::run(){
  while(main_window->isOpen() && *gameState == 0){
    loop_events();
    draw_all();
  }
}