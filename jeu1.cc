#include "jeu1.hh"
#include "chat1.hh"
#include <random>
#include <chrono>
#include <string>

Jeu1::Jeu1(sf::RenderWindow * main_window,int* gameState,int nb_souris_attrape_max,int niveau_jeu): Instance(main_window, gameState),nb_souris_attrape_max(nb_souris_attrape_max),niveau_jeu(niveau_jeu) {
  main_window->setKeyRepeatEnabled(false);
  chat = new Chat1(main_window);
  image_sang=new sf::Texture();
  sprite_sang=new sf::Sprite();
  set_values();
}



void Jeu1::set_values(){
  animation_duree=0;

  nb_souris_attrape=0;
  nb_souris_passe=0;
  seed = static_cast<unsigned int>(std::chrono::steady_clock::now().time_since_epoch().count());

  image->loadFromFile("./assets/game1-floor.png");
  sf::Vector2u textureSize = image->getSize();
  bg->setScale(
    float(windowSize.x) / textureSize.x,
    float(windowSize.y) / textureSize.y
  );
  bg->setTexture(*image);


  image_sang->loadFromFile("./assets/sang.png");
  sprite_sang->setTexture(*image_sang);
  sprite_sang->setPosition((int)(main_window->getSize().x/2.6),(int)(main_window->getSize().y/3));

  font->loadFromFile("./assets/LVDCGO__.TTF");
  options={"0/0","Press Space to catch the mouse"};
  texts.resize(2);
  text_coords = {{static_cast<float>(main_window->getSize().x) / 1.2f , static_cast<float>(main_window->getSize().y) / 20.0f},{25, 25}};
  text_size = {30,20};
  for (std::size_t i{}; i < texts.size(); ++i){
    texts[i].setFont(*font); 
    texts[i].setString(options[i]); 
    texts[i].setCharacterSize(text_size[i]);
    texts[i].setOutlineColor(sf::Color::Black);
    texts[i].setPosition(text_coords[i]);
  }
  texts[0].setOutlineThickness(4);
}


void Jeu1::loop_events() {
  sf::Event event;

  while(main_window->pollEvent(event)) {
    if (event.type == sf::Event::Closed) {
      main_window->close();
    }
    if (event.type == sf::Event::Resized){
        windowSize = main_window->getSize();
    }

    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {
      pressed=true;
      // main_window->clear();
      // main_window->draw(*bg);
      if ( chat->jouer(main_window, &souris_liste,bg) == 1 ) {
          nb_souris_attrape++;
          animation_duree = 15;
        }

    }
        
  }
}

// intervalle de temps aléatoire entre 0.2 et 3 secondes
// int Jeu1::genere_intervalle(int borne_gauche, int borne_droite){
//   std::default_random_engine generator(seed);
//   std::uniform_int_distribution<int> distribution(borne_gauche, borne_droite);
//   return (int)(distribution(generator));
// }

void Jeu1::draw_all(){
  main_window->draw(*bg);
  for (auto it = souris_liste.begin(); it != souris_liste.end();) {
    (*it)->seDeplacer();
    main_window->draw(*(*it)->sprite);

    if ((*it)->position.x > main_window->getSize().x) {
      it = souris_liste.erase(it);
    } else {
      ++it;
    }
  }
  if (animation_duree>0){
    main_window->draw(*sprite_sang);
    animation_duree--;

  }
  main_window->draw(*chat->sprite);
  print_text(nb_souris_attrape,nb_souris_attrape_max);
}



// void Jeu1::draw_all() {
//   main_window->clear();
//   main_window->draw(*bg);
//   main_window->display();
// }

void Jeu1::print_text(int nb_souris_attrape,float nb_souris_attrape_max) {
  score=std::to_string(nb_souris_attrape);
  texts[0].setString(score); 
  main_window->draw(texts[0]);
  if (pressed==false){
    main_window->draw(texts[1]);
  }
}

void Jeu1::gestion_vitesse(int * vitesse_souris,float * inc_vitesse){
  if ((nb_souris_attrape/nb_souris_attrape_max)>(*inc_vitesse)/6){
       switch (niveau_jeu)
      {
         case 1:
            (*vitesse_souris)+=2;
            break;
         case 2:
            (*vitesse_souris)+=5;
            break;
         case 3:
            (*vitesse_souris)+=8;
      }
      (*inc_vitesse)+=1;
      std::cout<<"vitesse_souris "<<*vitesse_souris<<std::endl;
      std::cout<<"inc_vitesse "<<*inc_vitesse<<std::endl;
    }

};



void Jeu1::run() {
  std::default_random_engine generator(seed);
  std::uniform_int_distribution<int> distribution(200, 3000); // intervalle de temps aléatoire entre 0.2 et 3 secondes
  auto last_spawn_time = std::chrono::steady_clock::now();
  int spawn_interval = distribution(generator);

  float inc_vitesse=1;
  int vitesse_souris=10;
  sf::Texture *image2 = new sf::Texture();
  image2->loadFromFile("./assets/pointeur.png");
  sf::Sprite * pointeur=new sf::Sprite();
  pointeur->setTexture(*image2);
  pointeur->setPosition(main_window->getSize().x/2.45,main_window->getSize().y/1.85);
  pointeur->setScale(sf::Vector2f(0.5f,0.5f));


  while(main_window->isOpen() && *gameState == 1) {
    main_window->clear();
    main_window->draw(*pointeur);

    auto current_time = std::chrono::steady_clock::now();
    auto elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(current_time - last_spawn_time).count();

    if (elapsed_time > spawn_interval) {
      souris_liste.push_back(new Souris(main_window,vitesse_souris));
      if (pressed){
        nb_souris_passe++;
      }
      last_spawn_time = current_time;
      spawn_interval = distribution(generator);
  }
  
  draw_all();
  main_window->display();

  loop_events();
  gestion_vitesse(&vitesse_souris,&inc_vitesse);

    if (nb_souris_passe>nb_souris_attrape_max){
      *gameState=4;
    }

  }

}





