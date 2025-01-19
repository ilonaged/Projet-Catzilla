#include "jeu1.hh"
#include "chat1.hh"
#include <random>
#include <chrono>
#include <string>
#include <cstdlib>

Jeu1::Jeu1(sf::RenderWindow * main_window,int* gameState,int nb_souris_attrape_max,int niveau_jeu): Instance(main_window, gameState),nb_souris_attrape_max(nb_souris_attrape_max),niveau_jeu(niveau_jeu) {
  main_window->setKeyRepeatEnabled(false);
  chat = new Chat1(windowSize);

  set_values();
}



void Jeu1::set_values() {
  nb_souris_attrape=0;
  nb_souris_passe=0;
  inc_pressed_up_key=0;
  pressed_up_key=true;
  seed = static_cast<unsigned int>(std::chrono::steady_clock::now().time_since_epoch().count());

  image->loadFromFile("./assets/game1-floor.png");
  sf::Vector2u textureSize = image->getSize();
  map_sprites["bg"]->setScale(
    float(windowSize.x) / textureSize.x,
    float(windowSize.y) / textureSize.y
  );
  map_sprites["bg"]->setTexture(*image);

  font->loadFromFile("./assets/LVDCGO__.TTF");
  options={"0/0","Press Space to catch the mouse","Use the up and down keys to move the cat"};
  texts.resize(3);
  text_coords = {{static_cast<float>(main_window->getSize().x) / 1.2f , static_cast<float>(main_window->getSize().y) / 20.0f},{25, 25},{25, 25}};
  text_size = {30,20,20};
  for (std::size_t i{}; i < texts.size(); ++i){
    texts[i].setFont(*font); 
    texts[i].setString(options[i]); 
    texts[i].setCharacterSize(text_size[i]);
    texts[i].setOutlineColor(sf::Color::Black);
    texts[i].setPosition(text_coords[i]);
    texts[i].setOutlineThickness(4);
  }
}


void Jeu1::loop_events() {
  sf::Event event;
  int resultat_jeu=0;

  while(main_window->pollEvent(event)) {
    if (event.type == sf::Event::Closed) {
      main_window->close();
    }
    if (event.type == sf::Event::Resized){
        windowSize = main_window->getSize();
    }

    if (event.type == sf::Event::KeyPressed){
      if (event.key.code == sf::Keyboard::Space){
        pressed=true;
        if (inc_pressed_up_key==0)
          pressed_up_key=false;
        inc_pressed_up_key++;

        resultat_jeu=chat->jouer(main_window, &souris_liste,map_sprites["bg"]);
        if ( resultat_jeu==1 ) 
            nb_souris_attrape++;
          
        if(resultat_jeu==-1)
            *gameState=5;
        if(resultat_jeu==2){
          nb_souris_attrape+=3;
        }
      }
      if (event.key.code == sf::Keyboard::Up) {
        pressed_up_key=true;
        chat->avancer_reculer(1);
      }

      if (event.key.code == sf::Keyboard::Down) {
        chat->avancer_reculer(-1);

      }
    }
  }
}


void Jeu1::draw_all(){
  main_window->draw(*map_sprites["bg"]);
  for (auto it = souris_liste.begin(); it != souris_liste.end();) {
    (*it)->seDeplacer();
    main_window->draw(*(*it)->getSprite());

    if ((*it)->getPosition().x > main_window->getSize().x) {
      it = souris_liste.erase(it);
    } else {
      ++it;
    }
  }
  main_window->draw(*chat->getSprite());
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
  if (pressed_up_key==false){
    main_window->draw(texts[2]);
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
      // std::cout<<"vitesse_souris "<<*vitesse_souris<<std::endl;
      // std::cout<<"inc_vitesse "<<*inc_vitesse<<std::endl;
    }

};

void Jeu1::genere_objet(int vitesse_souris){
  int choix_alea = 1+rand()%10;
  bool haut=false;
  if (nb_souris_attrape/nb_souris_attrape_max>0.33333){
    if (nb_souris_passe%2)
        haut=true;

    if (nb_souris_passe/nb_souris_attrape_max>0.5){
      if(0<choix_alea && choix_alea<5)
      souris_liste.push_back(new Souris(windowSize,vitesse_souris,haut));
      if (4<choix_alea && choix_alea<7)
        souris_liste.push_back(new Bestiole(windowSize,vitesse_souris,haut));
      if (6<choix_alea && choix_alea<11)
        souris_liste.push_back(new Souris_expl(windowSize,vitesse_souris,haut));

    }else{

      if(0<choix_alea && choix_alea<8){
        souris_liste.push_back(new Souris(windowSize,vitesse_souris,haut));
      }else{
        souris_liste.push_back(new Bestiole(windowSize,vitesse_souris,haut));
      }
    }
  haut=false;

  }else{
    if(0<choix_alea && choix_alea<8){
      souris_liste.push_back(new Souris(windowSize,vitesse_souris,false));
    }else{
      souris_liste.push_back(new Bestiole(windowSize,vitesse_souris,false));
    }
  }

}


void Jeu1::run() {
  std::default_random_engine generator(seed);
  std::uniform_int_distribution<int> distribution(200, 3000); // intervalle de temps aléatoire entre 0.2 et 3 secondes
  auto last_spawn_time = std::chrono::steady_clock::now();
  int spawn_interval = distribution(generator);

  float inc_vitesse=1;
  int vitesse_souris=10;

  while(main_window->isOpen() && *gameState == 1) {
    main_window->clear();

    auto current_time = std::chrono::steady_clock::now();
    auto elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(current_time - last_spawn_time).count();

    if (elapsed_time > spawn_interval) {
      genere_objet(vitesse_souris);
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





