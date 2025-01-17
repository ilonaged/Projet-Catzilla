

#include "finjeu1.hh"
#include <string>

FinJeu1::FinJeu1(sf::RenderWindow * main_window,int* gameState,int nb_souris_attrape,int nb_souris_attrape_max,int niveau_jeu,bool is_game_over):Instance(main_window,gameState),nb_souris_attrape(nb_souris_attrape),nb_souris_attrape_max(nb_souris_attrape_max),niveau_jeu(niveau_jeu),is_game_over(is_game_over){

  set_values();
}

FinJeu1::~FinJeu1(){
  delete font;
  delete image;
  delete bg;
}

void FinJeu1::set_values(){

    if (is_game_over){
        image->loadFromFile("./assets/game_over.png");
        score="votre score etait de "+std::to_string(nb_souris_attrape);
        options = {"GAME OVER","Veuillez appuyer sur entrer pour revenir au menu",score.c_str()};
        texts.resize(3);
        text_coords = {{410,225},{100,365},{100,510}};
        text_size = {30,15,15};
        for (std::size_t i{}; i < texts.size(); ++i){
        texts[i].setFont(*font); 
        texts[i].setString(options[i]); 
        texts[i].setCharacterSize(text_size[i]);
        texts[i].setOutlineColor(sf::Color::Black);
        texts[i].setPosition(text_coords[i]);
        }

    }else{
        image->loadFromFile("./assets/arc_en_ciel.png");
        //  score="votre score est de "+std::to_string(nb_souris_attrape)+" pour "+std::to_string(nb_souris_attrape_max)+" souris passees !! (difficulte : "+ std::to_string(niveau_jeu)+")";
        score="votre score est de "+std::to_string(nb_souris_attrape)+" (niveau "+std::to_string(nb_souris_attrape_max)+":"+ std::to_string(niveau_jeu)+")";
        options = {"Bravo", "Veuillez appuyer sur entrer pour revenir au menu",score.c_str()};
        texts.resize(3);
        text_coords = {{410,225},{100,365},{100,510}};
        text_size = {30,15,15};
        for (std::size_t i{}; i < texts.size(); ++i){
        texts[i].setFont(*font); 
        texts[i].setString(options[i]); 
        texts[i].setCharacterSize(text_size[i]);
        texts[i].setOutlineColor(sf::Color::Black);
        texts[i].setPosition(text_coords[i]);
        }
    }
  
  bg->setTexture(*image);
    sf::Vector2u textureSize = image->getSize();
    bg->setScale(
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
    }
  }
}

void FinJeu1::draw_all(){
  main_window->clear();
  main_window->draw(*bg);
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