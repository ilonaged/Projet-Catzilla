#include "finjeu1.hh"
#include <string>

FinJeu1::FinJeu1(sf::RenderWindow * main_window,int* gameState,int nb_souris_attrape,int nb_souris_attrape_max,int niveau_jeu,bool is_game_over):Instance(main_window,gameState),nb_souris_attrape(nb_souris_attrape),nb_souris_attrape_max(nb_souris_attrape_max),niveau_jeu(niveau_jeu),is_game_over(is_game_over){

  set_values();
}

FinJeu1::~FinJeu1(){
  delete font;
  delete image;
  // delete bg;
}

void FinJeu1::set_values(){

    if (is_game_over){
        image->loadFromFile("./assets/gameover.png");
        score="Your score is "+std::to_string(nb_souris_attrape);
        options = {"GAME OVER","Press Enter to go back to the menu",score.c_str()};
        texts.resize(3);
        text_coords = {{360,50},{210,650},{410,150}};
        text_size = {50,20,22};
        for (std::size_t i{}; i < texts.size(); ++i){
          texts[i].setFont(*font); 
          texts[i].setString(options[i]); 
          texts[i].setCharacterSize(text_size[i]);
          texts[i].setOutlineColor(sf::Color::Black);
          texts[i].setPosition(text_coords[i]);
        }
        texts[0].setFillColor(sf::Color::Red);

        music.openFromFile("./assets/gameover_music.ogg");
        music.play();


    } else {
        image->loadFromFile("./assets/rainbow.png");
        //score = "Your score is " + std::to_string(nb_souris_attrape)+" mice caught out of "+std::to_string(nb_souris_attrape_max)+" that appeared!! (Difficulty: "+ std::to_string(niveau_jeu)+")";
        //score="Your score is "+std::to_string(nb_souris_attrape)+" (level "+std::to_string(nb_souris_attrape_max)+":"+ std::to_string(niveau_jeu)+")";
        score = std::to_string(nb_souris_attrape) + " mice caught out of "+std::to_string(nb_souris_attrape_max)+" that appeared!";
        std::string difficulty = "Difficulty: "+ std::to_string(niveau_jeu);
        options = {"Congratulations!", "Press Enter to go back to the menu",
                  "Your score is: ", score.c_str(), difficulty.c_str()
                  };

        texts.resize(options.size());
        text_coords = {{340,170}, {210,650},
                      {400,300}, {160,380}, {470,450},
                      };
        text_size = {30, 20, 30, 22, 22};
        for (std::size_t i{}; i < texts.size(); ++i){
          texts[i].setFont(*font); 
          texts[i].setString(options[i]); 
          texts[i].setCharacterSize(text_size[i]);
          texts[i].setOutlineColor(sf::Color::Black);
          texts[i].setPosition(text_coords[i]);
          texts[i].setOutlineThickness(2);
        }
    }
    
  
  map_sprites["bg"]->setTexture(*image);
    sf::Vector2u textureSize = image->getSize();
    map_sprites["bg"]->setScale(
    float(windowSize.x) / textureSize.x,
    float(windowSize.y) / textureSize.y
  );
  font->loadFromFile("./assets/LVDCGO__.TTF");

}

void FinJeu1::loop_events(){
  sf::Event event;
  while(main_window->pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        main_window->close();
      }
      if (event.type == sf::Event::Resized){
        windowSize = main_window->getSize();

      }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
      *gameState=0;
      music.stop();
    }
  }
}

void FinJeu1::draw_all(){
  main_window->clear();
  main_window->draw(*map_sprites["bg"]);
  for(auto t : texts){
   main_window->draw(t); 
  }
  main_window->display();
}

void FinJeu1::run(){
    int inc=0;
    if(is_game_over){
        inc++;
    }
  while(main_window->isOpen() && *gameState == 4+inc){
    loop_events();
    draw_all();
  }
}