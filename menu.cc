#include "menu.hh"

Menu::Menu(sf::RenderWindow * main_window,int* gameState):gameState(gameState),main_window(main_window){
  // window = new sf::RenderWindow();
  font = new sf::Font();
  image = new sf::Texture();
  bg = new sf::Sprite();

  set_values();
}

Menu::~Menu(){
  delete font;
  delete image;
  delete bg;
}

void Menu::set_values(){
  // window->create(sf::VideoMode(1280,720), "Menu SFML", sf::Style::Default);
  main_window->setPosition(sf::Vector2i(0,0));

  pos = 0;
  pressed = theselect = false;
  font->loadFromFile("./assets/LVDCGO__.TTF");
  image->loadFromFile("./assets/menu-catzilla.png");

  bg->setTexture(*image);

  // pos_mouse = {0,0};
  mouse_coord = {0, 0};

  options = {"JEU 1", "JEU 2", "JEU 3"};
  texts.resize(3);
  coords = {{410,225},{410,365},{410,510}};
  sizes = {30,30,30};

  for (std::size_t i{}; i < texts.size(); ++i){
   texts[i].setFont(*font); 
   texts[i].setString(options[i]); 
   texts[i].setCharacterSize(sizes[i]);
   texts[i].setOutlineColor(sf::Color::Black);
   texts[i].setPosition(coords[i]);
  }
  texts[0].setOutlineThickness(4);
  pos = 0;

}

void Menu::loop_events(){
  sf::Event event;
  while(main_window->pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        main_window->close();
      }

    pos_mouse = main_window->getPosition();
    mouse_coord = main_window->mapPixelToCoords(pos_mouse);
    // mouse_coord = main_window->getMousePosition();


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
      // pour chaque gamestate, on envoie vers une fenetre différente (fenetre vide avec ecrit jeu1, jeu2, jeu3 en fonction du gamestate)

      

    }

    // if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
    //   if(winclose->getGlobalBounds().contains(mouse_coord)){
    //     //std::cout << "Close the window!" << '\n';
    //     window->close();
    //   }
    // }
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

void Menu::run_menu(){
  while(main_window->isOpen() && *gameState == 0){
    loop_events();
    draw_all();
  }
}